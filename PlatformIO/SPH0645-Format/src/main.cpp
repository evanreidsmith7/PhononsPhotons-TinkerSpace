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
const int SAMPLE_SIZE = 16384;


// Function declarations
uint32_t actualSample(uint32_t sample);
void findRange(int rangelimit, uint32_t samp);
void findRangeMask(int rangelimit, uint32_t samp);
void printTwo(uint32_t m, uint32_t t);
void plotOne(uint32_t s);
void i2s_install_atomic();
int read(int16_t *samples, int count);
void i2s_setpin_atomic();

void setup() 
{
  // Set up Serial Monitor
  Serial.begin(115200);
  Serial.println(" ");
 
  delay(1000);
 
  // Set up I2S
  i2s_install_atomic();
  i2s_setpin_atomic();
  //i2s_start(I2S_PORT);
 
 
  delay(500);
}

void loop() 
{
  int16_t *samples = (int16_t *)malloc(sizeof(uint16_t) * SAMPLE_SIZE);
  if (!samples)
  {
    Serial.println("Failed to allocate memory for samples");
    return;
  }
  while (true)
  {
    int samples_read = read(samples, SAMPLE_SIZE);
    Serial.println(samples_read);
  }
}

//*********************************************************************************************************************************
//***************************************            FUNCTIONS               ******************************************************
//*********************************************************************************************************************************

int read(int16_t *samples, int count)
{
  int32_t raw_samples[256];
  int sample_index = 0;
  while (count > 0)
  {
    size_t bytes_read = 0;
    i2s_read(I2S_PORT, (void **)raw_samples, sizeof(int32_t) * std::min(count, 256), &bytes_read, portMAX_DELAY);

    int samples_read = bytes_read / sizeof(int32_t);

    for (int i = 0; i < samples_read; i++)
    {
      samples[sample_index] = (raw_samples[i] & 0xFFFFFFF0) >> 11;
      sample_index++;
      count--;
    }
  }
  return sample_index;
}

void i2s_install_atomic() 
{
  // Set up I2S Processor configuration
  const i2s_config_t i2s_config = 
  {
    .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 16000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_I2S),
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 4,
    .dma_buf_len = 1024,
    .use_apll = false,
    .tx_desc_auto_clear = false,
    .fixed_mclk = 0
  };
 
  i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
}

void i2s_setpin_atomic()
{
  // Set I2S pin configuration
  const i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_SD
  };
  // FIXES for SPH0645
  REG_SET_BIT(I2S_TIMING_REG(I2S_PORT), BIT(9));
  REG_SET_BIT(I2S_CONF_REG(I2S_PORT), I2S_RX_MSB_SHIFT);
 
  i2s_set_pin(I2S_PORT, &pin_config);
}









uint32_t actualSample(uint32_t sample)
{
  uint32_t twoComp = ~sample + 1;
  return twoComp & 0x0003FFFF;
}
void printTwo(uint32_t m, uint32_t t)
{
  Serial.print(m, BIN);
  Serial.println();
  Serial.print(t, BIN);
  Serial.println();
  Serial.println();
}
void plotOne(uint32_t samp)
{
  Serial.println(samp);
}
void findRange(int rangelimit, uint32_t samp)
{
  Serial.print(samp);
  Serial.print(" ");  
  Serial.print(-1);
  Serial.print(" ");
  Serial.print(rangelimit);
  Serial.println();
}
void findRangeMask(int rangelimit, uint32_t samp)
{
  samp &= 0x0003FFFF;
  Serial.print(samp);
  Serial.print(" ");  
  Serial.print(-1);
  Serial.print(" ");
  Serial.print(rangelimit);
  Serial.println();
}