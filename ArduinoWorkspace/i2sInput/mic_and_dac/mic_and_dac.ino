#include <driver/i2s.h>
#include <string.h>
#include <stdio.h>

#define I2S_WS_MIC 25
#define I2S_SD_MIC 33
#define I2S_SCK_MIC 32

#define I2S_WS_DAC 25
#define I2S_SD_DAC 22
#define I2S_SCK_DAC 26

#define I2S_PORT_MIC I2S_NUM_0
#define I2S_PORT_DAC I2S_NUM_1

// Define input buffer length
#define bufferLen 128
uint32_t sBuffer[bufferLen];

//*********************************************************************************************************************************
//***************************************            i2s setup funcs               ************************************************
//*********************************************************************************************************************************
void i2s_install() 
{
//******************************************************************************
//**************   mic   *******************************************************             
//******************************************************************************
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
 
  i2s_driver_install(I2S_PORT_MIC, &i2s_config, 0, NULL);

//******************************************************************************
//**************   dac   *******************************************************             
//******************************************************************************
  const i2s_config_t i2s_config_dac = 
  {
    .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = 16000, // Match microphone sample rate
    .bits_per_sample = i2s_bits_per_sample_t(32), // Adjust according to DAC datasheet
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT, // DAC stereo format
    .communication_format = I2S_COMM_FORMAT_I2S_MSB,
    .intr_alloc_flags = 0,
    .dma_buf_count = 8,
    .dma_buf_len = bufferLen,
    .use_apll = false,
  };

  i2s_driver_install(I2S_PORT_DAC, &i2s_config_dac, 0, NULL);
}

void i2s_setpin()
{
//******************************************************************************
//**************   mic   *******************************************************
//******************************************************************************
  const i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK_MIC,
    .ws_io_num = I2S_WS_MIC,
    .data_out_num = -1,
    .data_in_num = I2S_SD_MIC
  };
 
  i2s_set_pin(I2S_PORT_MIC, &pin_config);

//******************************************************************************
//**************   dac   *******************************************************
//******************************************************************************
  const i2s_pin_config_t pin_config_dac = {
    .bck_io_num = I2S_SCK_DAC,
    .ws_io_num = I2S_WS_DAC,
    .data_out_num = I2S_SD_DAC,
    .data_in_num = -1
  };
 
  i2s_set_pin(I2S_PORT_DAC, &pin_config_dac);
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
 
 
  delay(500);
}

void loop() 
{
  Serial.println("starting...");
  size_t bytesIn = 0;
  size_t bytesOut = 0;

  esp_err_t inResult = i2s_read(I2S_PORT_MIC, &sBuffer, sizeof(sBuffer), &bytesIn, portMAX_DELAY);

  if (inResult == ESP_OK)
  {
    Serial.println("inResult is ok, going to write now");
    //DO WE NEED TO FORMAT THE DATA IN SBUFFER BEFORE WRITTING?
    esp_err_t outResult = i2s_write(I2S_PORT_DAC, &sBuffer, bytesIn, &bytesOut, portMAX_DELAY);

    if (outResult == ESP_OK)
    {
      Serial.println("outResult is ok");
    }
    else
    {
      Serial.println("outResult is fucked, entering infinite loop");
      while(true){}
    }
  }
  else
  {
    Serial.println("inResult is fucked, entering infinite loop");
    while(true){}
  }
}
/*
void loop() {
  size_t bytes_read, bytes_written;
  uint8_t i2s_read_buff[512];
  // Read data from the microphone
  i2s_read(I2S_NUM_0, &i2s_read_buff, sizeof(i2s_read_buff), &bytes_read, portMAX_DELAY);
  // Write data to the DAC
  i2s_write(I2S_NUM_1, &i2s_read_buff, bytes_read, &bytes_written, portMAX_DELAY);
}




*/
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
void recieveIncomingPlot()
{
    // False print statements to "lock range" on serial plotter display
  // Change rangelimit value to adjust "sensitivity"
  // Get I2S data and place in data buffer
  size_t bytesIn = 0;
  esp_err_t result = i2s_read(I2S_PORT_MIC, &sBuffer, sizeof(sBuffer), &bytesIn, portMAX_DELAY);

  if (result == ESP_OK)
  {
    uint32_t mean = 0;
    uint32_t sampler = 0;

    for(int i = 0; i < (int)(bytesIn / sizeof(sBuffer[0])); i++) 
    {
      sBuffer[i] >>= 14;
      
      mean += sBuffer[i];
      sampler = sBuffer[i];
    }

    uint32_t samplesRead = (uint32_t)(bytesIn / sizeof(sBuffer[0]));
    mean /= samplesRead;
    uint32_t twosComplement = ~mean + 1; // Compute two's complementSerial.print("\noriginal:   ");
    uint32_t actualSampleBufferAverage = twosComplement & 0x0003FFFF;

    Serial.println(actualSampleBufferAverage);
  }
  else
  {
    Serial.println("NOT OK");
  }
}