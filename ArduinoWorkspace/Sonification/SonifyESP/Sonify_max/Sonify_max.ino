#include <driver/i2s.h>
#include <HardwareSerial.h>


// Define frequency range
#define minInputFreq 17000  // Minimum input frequency
#define maxInputFreq 30000  // Maximum input frequency
#define minBuzzerFreq 300    // Minimum frequency the buzzer can handle
#define maxBuzzerFreq 1500   // Maximum frequency the buzzer can handle

// Define I2S parameters
#define SAMPLE_RATE 16000
#define I2S_PORT_DAC I2S_NUM_1
#define I2S_BCLK 27
#define I2S_LRC 14
#define I2S_DOUT 26

bool alarmActive = false;  // Flag to track if the alarm is active

void setup() {
  Serial.begin(115200);
  // Configure I2S
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S_MSB,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false,
    .tx_desc_auto_clear = true,
    .fixed_mclk = 0
  };
  
  i2s_driver_install(I2S_PORT_DAC, &i2s_config, 0, NULL);
  
  i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_BCLK,
    .ws_io_num = I2S_LRC,
    .data_out_num = I2S_DOUT,
    .data_in_num = -1
  };
  i2s_set_pin(I2S_PORT_DAC, &pin_config);
}

void loop() {


  if (Serial.available() > 0) {
    int freq = Serial.parseInt();
    
    if (freq >= minInputFreq && freq <= maxInputFreq) {
      freq = map(freq, minInputFreq, maxInputFreq, minBuzzerFreq, maxBuzzerFreq);

      if (freq >= minBuzzerFreq && freq <= maxBuzzerFreq) {
        alarmActive = true;
        float increment = (2 * PI * freq) / SAMPLE_RATE;
        float angle = 0;
        int16_t sample;
        for (int j = 0; j < SAMPLE_RATE; j++) {
          sample = (int16_t)(sin(angle) * INT16_MAX);
          i2s_write(I2S_PORT_DAC, &sample, sizeof(sample), NULL, portMAX_DELAY);
          angle += increment;
        }

        // Clear the serial buffer
        while(Serial.available()) {
          Serial.read();
        }
      }
    }
  }
}
