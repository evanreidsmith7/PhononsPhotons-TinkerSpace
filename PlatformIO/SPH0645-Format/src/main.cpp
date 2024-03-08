#include <Arduino.h>
#include <driver/i2s.h>
#include <string.h>
#include <stdio.h>
#include "soc/i2s_reg.h"
#include <algorithm>

#define I2S_WS 25
#define I2S_SD 33
#define I2S_SCK 32

#define I2S_PORT I2S_NUM_0

// Define input buffer length
const int SAMPLE_SIZE = 512;

// Function declarations
void i2s_install_atomic();
int read(int16_t *samples, int count);
void i2s_setpin_atomic();
void printPlotLimits(int rangelimit);






//*********************************************************************************************************************************
//***************************************            SETUP               ******************************************************
//*********************************************************************************************************************************
void setup()
{
  // Set up Serial Monitor
  Serial.begin(115200);
  Serial.println(" ");

  delay(1000);

  // Set up I2S
  i2s_install_atomic();
  i2s_setpin_atomic();
  // i2s_start(I2S_PORT);

  delay(500);
  printPlotLimits(32768); // Adjust rangelimit based on your data range
}

//*********************************************************************************************************************************
//***************************************             LOOP                   ******************************************************
//*********************************************************************************************************************************
void loop()
{
  // Dynamically allocate memory for storing the processed audio samples.
  // The size of the allocation is determined by SAMPLE_SIZE, which specifies
  // the number of samples to process in each iteration of the loop
  int16_t *samples = (int16_t *)malloc(sizeof(uint16_t) * SAMPLE_SIZE);
  if (!samples)
  {
    Serial.println("Failed to allocate memory for samples");
    return;
  }
  int samples_read = read(samples, SAMPLE_SIZE);
  free(samples); // Don't forget to free the allocated memory!
  delay(10); // Adjust delay as needed to manage plotting speed
}





//*********************************************************************************************************************************
//***************************************            FUNCTIONS               ******************************************************
//*********************************************************************************************************************************
/**
 * Reads audio samples from the I2S interface and processes them for visualization.
 * 
 * @param samples A pointer to an array where the processed audio samples will be stored.
 * @param count The number of samples to read and process.
 * @return The number of samples actually read and processed.
 */
int read(int16_t *samples, int count)
{
  // Temporary buffer to hold raw 32-bit samples from the I2S interface.
  int32_t raw_samples[256];

  // Index for the next position in the output samples array.
  int sample_index = 0;

  // Continue reading and processing samples until the requested count is met.
  while (count > 0)
  {
    // Variable to store the number of bytes actually read by i2s_read.
    size_t bytes_read = 0;

    // Read audio samples from the I2S interface.
    // std::min(count, 256) ensures that we do not request more samples than the buffer can hold or more than we need.
    // portMAX_DELAY indicates that the call should block until the requested number of bytes has been read.
    i2s_read(I2S_PORT, (void **)raw_samples, sizeof(int32_t) * std::min(count, 256), &bytes_read, portMAX_DELAY);

    // Calculate the number of samples actually read into raw_samples.
    int samples_read = bytes_read / sizeof(int32_t);

    // Process each raw sample.
    for (int i = 0; i < samples_read; i++)
    {
      // Process the raw sample by masking off the lower 4 bits (unused anyway) and right-shifting by 11 bits.
      // This specific processing depends on the characteristics of the audio source and the desired output format.
      samples[sample_index] = (raw_samples[i] & 0xFFFFFFF0) >> 11;

      // For visualization, print plot limits and the current sample to the Serial interface.
      // This facilitates using the Serial Plotter for visualizing the waveform.
      printPlotLimits(32768); 
      Serial.println(samples[sample_index]);

      // Move to the next sample in the output buffer and decrement the remaining count.
      sample_index++;
      count--;
    }
  }
  return sample_index;
}

void i2s_install_atomic()
{
  // Set up I2S Processor configuration
  const i2s_config_t i2s_config = {
    .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 16000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_STAND_I2S),
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 4,
    .dma_buf_len = 1024,
    .use_apll = false,
    .tx_desc_auto_clear = false,
    .fixed_mclk = 0};

  i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
}

void i2s_setpin_atomic()
{
  // Set I2S pin configuration
  const i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_SD};
  // FIXES for SPH0645
  REG_SET_BIT(I2S_TIMING_REG(I2S_PORT), BIT(9));
  REG_SET_BIT(I2S_CONF_REG(I2S_PORT), I2S_RX_MSB_SHIFT);

  i2s_set_pin(I2S_PORT, &pin_config);
}

void printPlotLimits(int rangelimit) 
{
  Serial.print(-1 * rangelimit);
  Serial.print(" ");
  Serial.print(rangelimit);
  Serial.print(" ");
}