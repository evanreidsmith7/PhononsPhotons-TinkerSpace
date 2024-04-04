#include <Arduino.h>
#include <driver/i2s.h>

#define I2S_WS_MIC 25   // LRCL ws_io
#define I2S_SD_MIC 33   // DOUT data_in
#define I2S_SCK_MIC 32  // BCLK bck_io

#define I2S_SCK_DAC 14  // BCK  14
#define I2S_SD_DAC 22   // DIN  22
#define I2S_WS_DAC 15   // LCK  15

#define I2S_PORT_MIC I2S_NUM_0
#define I2S_PORT_DAC I2S_NUM_1

// Buffer length for I2S
#define BUFFER_LEN          (128)

// Global buffers
int32_t micBuffer[BUFFER_LEN];
int32_t dacBuffer[BUFFER_LEN];

// I2S configuration
#define I2S_SAMPLE_RATE     (16000)    // Sample rate of the I2S microphone
#define I2S_CHANNEL_NUM     (1)        // Mono audio channel
#define I2S_BITS_PER_SAMPLE (I2S_BITS_PER_SAMPLE_32BIT) // 32-bit audio samples

void setup() {
  Serial.begin(115200);
  Serial.println("Setup...");

  // Mic configuration
  i2s_config_t i2s_config_mic = {
    .mode = i2s_mode_t (I2S_MODE_MASTER | I2S_MODE_RX), // I2S receive mode
    .sample_rate = I2S_SAMPLE_RATE,
    .bits_per_sample = i2s_bits_per_sample_t(32),
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT, // Mono channel
    .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_STAND_I2S),
    .intr_alloc_flags = 0,  // Default interrupt allocation
    .dma_buf_count = 8,     // Number of DMA buffers
    .dma_buf_len = 64,      // Size of each DMA buffer
    .use_apll = false       // Use the internal APLL (Audio PLL)
  };

  // Mic pins
  i2s_pin_config_t pin_config_mic = {
    .bck_io_num = I2S_SCK_MIC,
    .ws_io_num = I2S_WS_MIC,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_SD_MIC
  };

  // DAC configuration
  i2s_config_t i2s_config_dac = {
    .mode = i2s_mode_t (I2S_MODE_MASTER | I2S_MODE_TX), // I2S transmit mode
    .sample_rate = I2S_SAMPLE_RATE,
    .bits_per_sample = i2s_bits_per_sample_t(32),
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT, // Mono channel
    .communication_format = I2S_COMM_FORMAT_I2S_MSB,
    .intr_alloc_flags = 0,  // Default interrupt allocation
    .dma_buf_count = 8,     // Number of DMA buffers
    .dma_buf_len = 64,      // Size of each DMA buffer
    .use_apll = false       // Use the internal APLL (Audio PLL)
  };

  // DAC pins
  i2s_pin_config_t pin_config_dac = {
    .bck_io_num = I2S_SCK_DAC,
    .ws_io_num = I2S_WS_DAC,
    .data_out_num = I2S_SD_DAC,
    .data_in_num = I2S_PIN_NO_CHANGE
  };

  // Initialize I2S configurations
  i2s_driver_install(I2S_NUM_0, &i2s_config_mic, 0, NULL);
  i2s_set_pin(I2S_NUM_0, &pin_config_mic);

  i2s_driver_install(I2S_NUM_1, &i2s_config_dac, 0, NULL);
  i2s_set_pin(I2S_NUM_1, &pin_config_dac);

  // Start I2S
  i2s_start(I2S_PORT_MIC);
  i2s_start(I2S_PORT_DAC);

  delay(500);
}

void loop() {
  // Read data from the MEMS microphone
  size_t bytesRead = 0;
  i2s_read(I2S_NUM_0, micBuffer, sizeof(micBuffer), &bytesRead, portMAX_DELAY);

  // Write the acquired data to the DAC
  size_t bytesWritten = 0;
  i2s_write(I2S_NUM_1, micBuffer, bytesRead, &bytesWritten, portMAX_DELAY);

  // Print the acquired data to the Serial Plotter
  for (size_t i = 0; i < bytesRead / sizeof(int32_t); i++) {
    Serial.println(micBuffer[i]);
  }

  delay(100); // Adjust delay based on your application's needs
}

