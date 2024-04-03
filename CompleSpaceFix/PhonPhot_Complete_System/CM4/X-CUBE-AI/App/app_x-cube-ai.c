
/**
  ******************************************************************************
  * @file    app_x-cube-ai.c
  * @author  X-CUBE-AI C code generator
  * @brief   AI program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

 /*
  * Description
  *   v1.0 - Minimum template to show how to use the Embedded Client API
  *          model. Only one input and one output is supported. All
  *          memory resources are allocated statically (AI_NETWORK_XX, defines
  *          are used).
  *          Re-target of the printf function is out-of-scope.
  *   v2.0 - add multiple IO and/or multiple heap support
  *
  *   For more information, see the embeded documentation:
  *
  *       [1] %X_CUBE_AI_DIR%/Documentation/index.html
  *
  *   X_CUBE_AI_DIR indicates the location where the X-CUBE-AI pack is installed
  *   typical : C:\Users\<user_name>\STM32Cube\Repository\STMicroelectronics\X-CUBE-AI\7.1.0
  */

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#if defined ( __ICCARM__ )
#elif defined ( __CC_ARM ) || ( __GNUC__ )
#endif

/* System headers */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "app_x-cube-ai.h"
#include "main.h"
#include "ai_datatypes_defines.h"
#include "ann_756.h"
#include "ann_756_data.h"

/* USER CODE BEGIN includes */
/* USER CODE END includes */

/* IO buffers ----------------------------------------------------------------*/

#if !defined(AI_ANN_756_INPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_float data_in_1[AI_ANN_756_IN_1_SIZE];
ai_float* data_ins[AI_ANN_756_IN_NUM] = {
data_in_1
};
#else
ai_float* data_ins[AI_ANN_756_IN_NUM] = {
NULL
};
#endif

#if !defined(AI_ANN_756_OUTPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_float data_out_1[AI_ANN_756_OUT_1_SIZE];
ai_float* data_outs[AI_ANN_756_OUT_NUM] = {
data_out_1
};
#else
ai_float* data_outs[AI_ANN_756_OUT_NUM] = {
NULL
};
#endif

/* Activations buffers -------------------------------------------------------*/

AI_ALIGNED(32)
static uint8_t pool0[AI_ANN_756_DATA_ACTIVATION_1_SIZE];

ai_handle data_activations0[] = {pool0};

/* AI objects ----------------------------------------------------------------*/

static ai_handle ann_756 = AI_HANDLE_NULL;

static ai_buffer* ai_input;
static ai_buffer* ai_output;

static void ai_log_err(const ai_error err, const char *fct)
{
  /* USER CODE BEGIN log */
  if (fct)
    printf("TEMPLATE - Error (%s) - type=0x%02x code=0x%02x\r\n", fct,
        err.type, err.code);
  else
    printf("TEMPLATE - Error - type=0x%02x code=0x%02x\r\n", err.type, err.code);

  //do {} while (1);
  /* USER CODE END log */
}

static int ai_boostrap(ai_handle *act_addr)
{
  ai_error err;

  /* Create and initialize an instance of the model */
  err = ai_ann_756_create_and_init(&ann_756, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    ai_log_err(err, "ai_ann_756_create_and_init");
    return -1;
  }

  ai_input = ai_ann_756_inputs_get(ann_756, NULL);
  ai_output = ai_ann_756_outputs_get(ann_756, NULL);

#if defined(AI_ANN_756_INPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-inputs" option is used, memory buffer can be
   *  used from the activations buffer. This is not mandatory.
   */
  for (int idx=0; idx < AI_ANN_756_IN_NUM; idx++) {
	data_ins[idx] = ai_input[idx].data;
  }
#else
  for (int idx=0; idx < AI_ANN_756_IN_NUM; idx++) {
	  ai_input[idx].data = data_ins[idx];
  }
#endif

#if defined(AI_ANN_756_OUTPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-outputs" option is used, memory buffer can be
   *  used from the activations buffer. This is no mandatory.
   */
  for (int idx=0; idx < AI_ANN_756_OUT_NUM; idx++) {
	data_outs[idx] = ai_output[idx].data;
  }
#else
  for (int idx=0; idx < AI_ANN_756_OUT_NUM; idx++) {
	ai_output[idx].data = data_outs[idx];
  }
#endif

  return 0;
}

static int ai_run(void)
{
  ai_i32 batch;

  batch = ai_ann_756_run(ann_756, ai_input, ai_output);
  if (batch != 1) {
    ai_log_err(ai_ann_756_get_error(ann_756),
        "ai_ann_756_run");
    return -1;
  }

  return 0;
}

int acquire_and_process_data(ai_float data[AI_ANN_756_IN_1_SIZE], float mag_buffer[6][256]) {

	int total_iters = 0;
    for (int idx = 0; idx < 6; idx++) {

    	// Skip first two values in FFT data
    	// Are below 20k and add noise (not in training dataset)
        for (int j = 0; j < 126; j++) {
            data[total_iters] = mag_buffer[idx][j + 2];
            total_iters++;
        }
    }

    return 0;
}

int post_process(ai_float data[AI_ANN_756_OUT_1_SIZE])
{

      int8_t   prev_region, curr_region;
      // For testing
      //ai_float predicted_region[12];

      // process the predictions
      for (int idx = 0; idx < AI_ANN_756_OUT_1_SIZE; idx++) {

    	  // For testing
          //predicted_region[idx] = data[idx];
    	  //printf("data[%d] = %f\r\n\n", idx, data[idx]);

          if (data[idx] == 1.0) {
        	  curr_region = idx + 1;
          }
      }

      prev_region = IPCGetPredictedRegion();

      // Update IPC if predicted region has changed
      if( prev_region != curr_region) IPCSetPredictedRegion(curr_region);

      return 0;
}


/* Entry points --------------------------------------------------------------*/

void MX_X_CUBE_AI_Init(void)
{

  printf("\r\nMX_X_CUBE_AI_Init\r\n");

  ai_boostrap(data_activations0);
  printf("ann_756 returns  %d\r\n\n", ((uint8_t*) ann_756)[0]);

}

void MX_X_CUBE_AI_Process(float mag_buffer[6][256])
{

  int res = -1;

  printf("\nMX_X_CUBE_AI_Process\r\n\n");

  //printf("ann_756 %d\r\n", ((uint8_t*) ann_756)[0]);
  if (ann_756)
  {

    /* 1 - acquire and pre-process input data */
    res = acquire_and_process_data(data_in_1,mag_buffer);

    /* 2 - process the data - call inference engine */
    if (res == 0 ) res = ai_run();

    /* 3- post-process the predictions */
    if (res == 0) res = post_process(data_out_1);

  }

  if (res) {
    ai_error err = {AI_ERROR_INVALID_STATE, AI_ERROR_CODE_NETWORK};
    ai_log_err(err, "Process has FAILED");
  }
}
#ifdef __cplusplus
}
#endif
