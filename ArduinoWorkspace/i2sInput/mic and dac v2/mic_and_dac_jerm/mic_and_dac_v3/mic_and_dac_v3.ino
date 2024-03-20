#include <driver/i2s.h>
#include <string.h>
#include <stdio.h>

/*
//      I2S_SEL_mic gnd // SEL  3.3V
#define I2S_WS_MIC 25   // LRCL 25
#define I2S_SD_MIC 33   // DOUT 33
#define I2S_SCK_MIC 32  // BCLK 32
//             GND gnd  // GND  GND
//             VDD 3V   // 3V   3.3V


//      I2S_SEL_dac gnd // SCK  GND
#define I2S_SCK_DAC 14  // BCK  14
#define I2S_SD_DAC 22   // DIN  22
#define I2S_WS_DAC 25   // LCK  25
//             GND gnd  // GND  GND
//             VDD 5V   // VIN  5V
*/


//      I2S_SEL_mic gnd // SEL  3.3V
#define I2S_WS_MIC 25   // LRCL 25-25
#define I2S_SD_MIC 33   // DOUT 33-33
#define I2S_SCK_MIC 26  // BCLK 26-32
//             GND gnd  // GND  GND
//             VDD 3V   // 3V   3.3V


//      I2S_SEL_dac gnd // SCK  GND
#define I2S_SCK_DAC 14  // BCK  14-14
#define I2S_SD_DAC 22   // DIN  22-22
#define I2S_WS_DAC 15   // LCK  15-15
//             GND gnd  // GND  GND
//             VDD 5V   // VIN  5V

const i2s_port_t I2S_PORT_MIC = I2S_NUM_0;
const i2s_port_t I2S_PORT_DAC = I2S_NUM_1;

#define BUFFER_SIZE 8
#define NUM_BUFFERS 4

uint32_t sBuffer[NUM_BUFFERS][BUFFER_SIZE];
volatile int currentBuffer = 0;


//*********************************************************************************************************************************
//***************************************            i2s setup funcs               ************************************************
//*********************************************************************************************************************************
void i2s_install() 
{
  esp_err_t err;
//******************************************************************************
//**************   mic   *******************************************************             
//******************************************************************************
  const i2s_config_t i2s_config = 
  {
    .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX), // Set mode to I2S master and receiver to capture audio
    .sample_rate = 16000, // Set audio sample rate to 16kHz
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,  // Set bit depth to 32 bits per sample
    .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT, // Use only the left audio channel
    .communication_format =  i2s_comm_format_t(I2S_COMM_FORMAT_STAND_I2S), // Standard I2S communication format
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,     // Interrupt level 1
    .dma_buf_count = 4, // Number of DMA buffers
    .dma_buf_len = 8, // Length of each DMA buffer, defined by `bufferLen`
    .use_apll = false // Do not use Audio PLL for clock generation
    
  };
  i2s_driver_install(I2S_PORT_MIC, &i2s_config, 0, NULL);
    if (err != ESP_OK) {
    Serial.printf("Failed installing driver mic: %d\n", err);
    while (true);
  }
//******************************************************************************
//**************   dac   *******************************************************             
//******************************************************************************
  const i2s_config_t i2s_config_dac = 
  {
    .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_TX), // Set mode to I2S master and transmitter for audio output
    .sample_rate = 16000, // Match DAC sample rate with microphone (16kHz)
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,  // Set bit depth according to DAC datasheet, 32 bits
    .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT, // Configure for mono
    .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_STAND_I2S),  // Set communication format to I2S, MSB first
    .intr_alloc_flags = 0, // Default interrupt allocation flags
    .dma_buf_count = 4, // Number of DMA buffers for output
    .dma_buf_len = 8, // Length of each DMA buffer, defined by `bufferLen`
    .use_apll = false // Do not use Audio PLL for clock generation
  };
  i2s_driver_install(I2S_PORT_DAC, &i2s_config_dac, 0, NULL);
    if (err != ESP_OK) {
    Serial.printf("Failed installing driver dac: %d\n", err);
    while (true);
  }
  Serial.println("I2S driver installed.");
}

void i2s_setpin()
{
esp_err_t err;
//******************************************************************************
//**************   mic   *******************************************************
//******************************************************************************
  const i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK_MIC,
    .ws_io_num = I2S_WS_MIC,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_SD_MIC
  };
 
  i2s_set_pin(I2S_PORT_MIC, &pin_config);
   if (err != ESP_OK) {
    Serial.printf("Failed setting pin: %d\n", err);
    while (true);
  }

//******************************************************************************
//**************   dac   *******************************************************
//******************************************************************************
  const i2s_pin_config_t pin_config_dac = {
    .bck_io_num = I2S_SCK_DAC,
    .ws_io_num = I2S_WS_DAC,
    .data_out_num = I2S_SD_DAC,
    .data_in_num = I2S_PIN_NO_CHANGE
  };
 
  i2s_set_pin(I2S_PORT_DAC, &pin_config_dac);
   if (err != ESP_OK) {
    Serial.printf("Failed setting pin: %d\n", err);
    while (true);
  }
  Serial.println("I2S pins configed.");
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

void loop() {
    size_t bytesIn = 0;
    size_t bytesOut = 0;

    esp_err_t inResult = i2s_read(I2S_NUM_0, &sBuffer[currentBuffer], sizeof(sBuffer[currentBuffer]), &bytesIn, portMAX_DELAY);
    if (inResult != ESP_OK) {
        Serial.println("Failed to read audio data from microphone.");
        return;
    }

    currentBuffer = (currentBuffer + 1) % NUM_BUFFERS;

    // Send audio data over serial for visual plotter
    for (int i = 0; i < bytesIn / sizeof(sBuffer[currentBuffer][0]); i++) {
        float magnitude = (float)sBuffer[currentBuffer][i] / 2147483648.0;
        float scaledMagnitude = magnitude * 100.0 + 50.0;
        Serial.print(i); // X-coordinate (sample index)
        Serial.print(","); // Separator
        Serial.println(scaledMagnitude, 2); // Y-coordinate (scaled magnitude)
    }

    // Write the same buffer to the DAC
    esp_err_t outResult = i2s_write(I2S_NUM_1, &sBuffer[currentBuffer], bytesIn, &bytesOut, portMAX_DELAY);
    if (outResult != ESP_OK) {
        Serial.println("Failed to write audio data to DAC.");
        return;
    }
}