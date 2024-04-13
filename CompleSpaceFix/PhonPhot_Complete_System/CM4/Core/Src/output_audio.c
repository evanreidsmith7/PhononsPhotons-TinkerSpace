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

static const float FREQ_MIN = 200;
static const float FREQ_MAX = 8000;

// maximum multiplier for voice volume
static const float VOICE_VOLUME_MAX = 16.0f;

// normalized voice volume variable
static float voice_volume_normalized = 0.5f;
static float voice_volume_log_approx;

// buffer for alarm tone, holds an integer number of cycles to avoid discontinuities
static int16_t alarm_tone_data_buffer[ALARM_BUFFER_LENGTH];

// decoupled index for alarm tone buffer so alarm is continuous across iterations
static uint16_t alarm_tone_buffer_index = 0;

// separate sonification index so sonification is not coupled to
//   the passed sample chunks, sonification is continuous throughout time
static uint32_t sonification_index_n = 0;

// boolean flag used to gracefully end sonification in event that the anomaly ends
//   and the sonification wave is not yet zero -> avoid pop on output
static boolean_t sonification_active = FALSE;

// normalized sonification frequency from DSP
static volatile float sonification_frequency_normalized = 0.5f;

// Hz sonification frequency determined from normalized frequency and
//    supported output frequency range
static float sonification_frequency_current = 1000.0f;
static float sonification_frequency_new = 1000.0f;
static float sonification_magnitude = -100.0f;

// current/previous used only to avoid discontinuities when changing frequencies
//  if a frequency change happens, it must occur when the speaker has positive inertia, i.e. it is
//  traveling in the same direction as it should for the next sample at the new frequency,
//  a discontinuity is heard otherwise
static int16_t sonification_sample_current;
static int16_t sonification_sample_previous;

// boolean flags to detect change in alarm state
static boolean_t alarm_state_current = FALSE;
static boolean_t alarm_state_previous = FALSE;

// counter used for alarm on/off cycle
static uint32_t alarm_counter = 0;
static boolean_t alarm_mute = FALSE;

// HAL defined variable
extern UART_HandleTypeDef huart3;

// one-time generation of alarm tone,
//   contains integer number of cycles of alarm frequency to avoid discontinuities
void alarminit( )
{
  int n;

  for (n = 0; n < ALARM_BUFFER_LENGTH; ++n)
	{
		alarm_tone_data_buffer[n] = (65535/64)* sinf((750.0f/16000.0f)*2*M_PI*n);
	}
}

// passed array is voice audio from DSP
void playAudio( int16_t *audio_samples, uint16_t audio_sample_length )
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

	// update voice volume from IPC
	voice_volume_normalized = IPCGetVoiceVolumeNormalized( );
	voice_volume_log_approx = powf(voice_volume_normalized, 4.0f) * VOICE_VOLUME_MAX;
	// scale raw voice audio data depending on volume variable, the other sources have their own volume standards
	// TODO - adjust this scaling so the bounds are reasonable
	if ( IPCGetVoiceMuteState( ) )
	{
    // voice is muted, send vmute to esp
	}
	else
  {
	  // voice is active, adjust volume
	}
}
