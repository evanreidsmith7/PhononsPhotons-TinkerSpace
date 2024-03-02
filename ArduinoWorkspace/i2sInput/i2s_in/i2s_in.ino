#include <driver/i2s.h>
#include <string.h>
#include <stdio.h>

#define I2S_WS 25
#define I2S_SD 33
#define I2S_SCK 32

#define I2S_PORT I2S_NUM_0

// Define input buffer length
#define bufferLen 128
uint32_t sBuffer[bufferLen];

void i2s_install() 
{
  // Set up I2S Processor configuration
  const i2s_config_t i2s_config = 
  {
    .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 16000,
    .bits_per_sample = i2s_bits_per_sample_t(32),
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_STAND_I2S),
    .intr_alloc_flags = 0,
    .dma_buf_count = 8,
    .dma_buf_len = bufferLen,
    .use_apll = false
  };
 
  i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
}

void i2s_setpin()
{
  // Set I2S pin configuration
  const i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = -1,
    .data_in_num = I2S_SD
  };
 
  i2s_set_pin(I2S_PORT, &pin_config);
}

void setup() 
{
  // Set up Serial Monitor
  Serial.begin(115200);
  Serial.println(" ");
 
  delay(1000);
 
  // Set up I2S
  i2s_install();
  i2s_setpin();
  i2s_start(I2S_PORT);
 
 
  delay(500);
}

void loop() {

  // False print statements to "lock range" on serial plotter display
  // Change rangelimit value to adjust "sensitivity"
  
  
  

  // Get I2S data and place in data buffer
  size_t bytesIn = 0;
  esp_err_t result = i2s_read(I2S_PORT, &sBuffer, sizeof(sBuffer), &bytesIn, portMAX_DELAY);

  if (result == ESP_OK)
  {
    uint32_t mean = 0;
    uint32_t sampler = 0;
    for(int i = 0; i < (int)(bytesIn / sizeof(sBuffer[0])); i++) 
    {
      // Shift right by 8 to align 24-bit data
      //int32_t alignedSample = sBuffer[i] >> 8;
      // Apply mask to isolate 18 bits
      //int32_t rawSample = alignedSample & 0x3FFFF;
      // Check if sign extension is needed based on your processing requirements
      // Print the adjusted and masked sample value
      //Serial.println(rawSample);
      //mean+=((sBuffer[i] >> 8) & 0x3FFFF);
      //mean += sBuffer[i];

      sBuffer[i] >>= 14;
      //sBuffer[i] &= 0x0003FFFF;
      
      mean += sBuffer[i];
      sampler = sBuffer[i];
      



    }
    uint32_t samplesRead = (uint32_t)(bytesIn / sizeof(sBuffer[0]));
    mean /= samplesRead;

    uint32_t twosComplement = ~mean + 1; // Compute two's complementSerial.print("\noriginal:   ");
    
    //findRange(262144, twosComplement);
    //printTwo(mean, twosComplement);
    
    //findRangeMask(262144, mean);
    findRangeMask(262144, twosComplement);
  }
  else
  {
    Serial.println("NOT OK");
  }
}
//*********************************************************************************************************************************
//***************************************            FUNCTIONS               ******************************************************
//*********************************************************************************************************************************
void printTwo(uint32_t m, uint32_t t)
{
  Serial.print(m, BIN);
  Serial.println();
  Serial.print(t, BIN);
  Serial.println();
  Serial.println();
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