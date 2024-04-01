#include <driver/i2s.h>

// Connections to INMP441 I2S microphone
#define I2S_WS 25
#define I2S_SD 33
#define I2S_SCK 32 //bck

// Connections to MAX98357
#define I2S_DOUT 26
#define I2S_BCLK 27
#define I2S_LRC  14

#define SAMPLE_RATE  16000
#define I2S_PORT_DAC I2S_NUM_1
#define I2S_PORT_MIC I2S_NUM_0

// Define input buffer length
#define bufferLen 64
int16_t sBuffer[bufferLen];

void i2s_install() {
  // Set up input I2S Processor configuration
  const i2s_config_t i2s_config_input = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = i2s_bits_per_sample_t(16),
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_STAND_I2S),
    .intr_alloc_flags = 0,
    .dma_buf_count = 8,
    .dma_buf_len = bufferLen,
    //.use_apll = false
  };
 
  // Set up output I2S Processor configuration
  const i2s_config_t i2s_config_output = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT, // Changed to 32-bit resolution
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S_MSB,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = bufferLen,
    //.use_apll = false
  };
 
  // Install input and output I2S drivers
  i2s_driver_install(I2S_PORT_MIC, &i2s_config_input, 0, NULL);
  i2s_driver_install(I2S_PORT_DAC, &i2s_config_output, 0, NULL);
}

void i2s_setpin() {
  // Set I2S pin configuration for input
  const i2s_pin_config_t pin_config_input = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = -1,
    .data_in_num = I2S_SD
  };
 
  // Set I2S pin configuration for output
  const i2s_pin_config_t pin_config_output = {
    .bck_io_num = I2S_BCLK,
    .ws_io_num = I2S_LRC,
    .data_out_num = I2S_DOUT,
    .data_in_num = -1
  };
  i2s_set_pin(I2S_PORT_MIC, &pin_config_input);
  i2s_set_pin(I2S_PORT_DAC, &pin_config_output);
}

void setup() {
  Serial.begin(115200);
  Serial.println(" ");
 
  delay(1000);

  i2s_install();
  i2s_setpin();
  i2s_start(I2S_PORT_MIC);
  i2s_start(I2S_PORT_DAC);

  delay(500);
}

void loop() {
  int rangelimit = 3000;
  Serial.print(rangelimit * -1);
  Serial.print(" ");
  Serial.print(rangelimit);
  Serial.print(" ");
  
  size_t bytesIn = 0;
  esp_err_t result = i2s_read(I2S_PORT_MIC, &sBuffer, bufferLen, &bytesIn, portMAX_DELAY);
 
  if (result == ESP_OK) {
    int16_t samples_read = bytesIn / 2; // Each sample is 2 bytes
    if (samples_read > 0) {
      float mean = 0;
      for (int16_t i = 0; i < samples_read; ++i) {
        mean += (sBuffer[i]);
      }
      mean /= samples_read;
      Serial.println(mean);
      
      // Write to output I2S interface
      size_t bytes_written;
      i2s_write(I2S_PORT_DAC, &sBuffer, bytesIn, &bytes_written, portMAX_DELAY);
    }
  }
}