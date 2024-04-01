#include "i2s_manager.h"
#include "websocket_client.h" // Include the header where WebsocketsClient and client are declared
#include <Arduino.h>

void i2s_install() 
{
  const i2s_config_t i2s_config = {
    .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 44100,
    .bits_per_sample = i2s_bits_per_sample_t(16),
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_STAND_I2S),
    .intr_alloc_flags = 0,
    .dma_buf_count = 10,
    .dma_buf_len = 1024,
    .use_apll = false
  };

  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
}

void i2s_setpin() 
{
  const i2s_pin_config_t pin_config = {
    .bck_io_num = 32,
    .ws_io_num = 25,
    .data_out_num = -1,
    .data_in_num = 33
  };

  i2s_set_pin(I2S_NUM_0, &pin_config);
}

void micTask(void *parameter)
{
   i2s_install();
   i2s_setpin();
   i2s_start(I2S_NUM_0);

   int16_t sBuffer[1024];
   size_t bytesIn = 0;
   while (true) 
   {
      if (i2s_read(I2S_NUM_0, &sBuffer, sizeof(sBuffer), &bytesIn, portMAX_DELAY) == ESP_OK && isWebSocketConnected)
      {
         client.sendBinary((const char*)sBuffer, bytesIn);
      }
   }
}