#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "common.h"
#include "main.h"
#include "dsp.h"
#include "ipc_interface.h"

// alarm buffer length required for n integer cycles of 750 Hz
#define ALARM_BUFFER_LENGTH 64

// normalized sonification frequency from DSP
static volatile float sonification_frequency_normalized = 0.5f;


// boolean flags to detect change in alarm state
static boolean_t alarm_state_current = FALSE;
static boolean_t alarm_state_previous = FALSE;

// counter used for alarm on/off cycle
static uint32_t alarm_counter = 0;
static boolean_t alarm_mute = FALSE;
//**************************************************************************************************************************************************************************************************
//**************************************************************************************************************************************************************************************************
//**************************************************************************************************************************************************************************************************
// mesage 
char vMute[] = "vMute\n";
char vUnMute[] = "vUnMute\n";
char Nalarm[] = "!alarm\n";
volatile uint8_t uart_tx_complete = 1; // Transmission complete flag, set to 1 initially to send the first message
volatile uint8_t voiceActive = 0;
//**************************************************************************************************************************************************************************************************
//**************************************************************************************************************************************************************************************************
//**************************************************************************************************************************************************************************************************

// HAL defined variable
extern UART_HandleTypeDef huart1;

//**************************************************************************************************************************************************************************************************
//**************************************************************************************************************************************************************************************************
//**************************************************************************************************************************************************************************************************
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  if(huart->Instance == USART1)
  {
	  uart_tx_complete = 1; // Transmission completed, ready to send the next message
  }
}
//**************************************************************************************************************************************************************************************************
//**************************************************************************************************************************************************************************************************
//**************************************************************************************************************************************************************************************************
// passed array is voice audio from DSP
/*
    if (uart_tx_complete == 1)
    {
      HAL_UART_Transmit_DMA(&huart1, (uint8_t*)msg, strlen(msg));
      uart_tx_complete = 0;
    }
*/
void playAudio( )
{
	alarm_state_previous = alarm_state_current;
	alarm_state_current = dspGetIsAnomalyDetected( );

	if ( alarm_state_current && !alarm_state_previous )
	{
	  // alarm just went active, set mute false and set counter used for on/off cycle to zero
    alarm_mute = FALSE;
    alarm_counter = 0;

    // set global mute state in IPC
    IPCSetAlarmMuteState( FALSE );
    // get freq and magnitude from DSP
	}
	else
	{
	  // update mute state from IPC
	  alarm_mute = IPCGetAlarmMuteState( );
    // if alarm is muted send !alarm to esp
	}

	if ( IPCGetVoiceMuteState( ) )
	{
    // voice is muted, send vmute to esp
    if (uart_tx_complete == 1 && voiceActive == 1)
    {
      HAL_UART_Transmit_DMA(&huart1, (uint8_t*)vMute, strlen(vMute));
      uart_tx_complete = 0;
      voiceActive = 0;
    }

	}
	else
  {
	  // voice is active, adjust volume

    if (uart_tx_complete == 1 && voiceActive == 0)
    {
      HAL_UART_Transmit_DMA(&huart1, (uint8_t*)vUnMute, strlen(vUnMute));
      uart_tx_complete = 0;
      voiceActive = 1;
    }
	}
}
