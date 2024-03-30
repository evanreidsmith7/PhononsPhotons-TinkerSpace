
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
#include "ipc_interface.h"
#include "ai_datatypes_defines.h"
#include "ann_1524_trimmed.h"
#include "ann_1524_trimmed_data.h"

/* USER CODE BEGIN includes */
/* USER CODE END includes */

/* IO buffers ----------------------------------------------------------------*/

#if !defined(AI_ANN_1524_TRIMMED_INPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_float data_in_1[AI_ANN_1524ANN_1524_TRIMMED_IN_1_SIZE_BYTES];
ai_float* data_ins[AI_ANN_1524_TRIMMED_IN_NUM] = {
data_in_1
};
#else
ai_float* data_ins[AI_ANN_1524_TRIMMED_IN_NUM] = {
NULL
};
#endif

#if !defined(AI_ANN_1524_TRIMMED_OUTPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_out_1[AI_ANN_1524_TRIMMED_OUT_1_SIZE_BYTES];
ai_i8* data_outs[AI_ANN_1524_TRIMMED_OUT_NUM] = {
data_out_1
};
#else
ai_i8* data_outs[AI_ANN_1524_TRIMMED_OUT_NUM] = {
NULL
};
#endif

/* Activations buffers -------------------------------------------------------*/

AI_ALIGNED(32)
static uint8_t pool0[AI_ANN_1524_TRIMMED_DATA_ACTIVATION_1_SIZE];

ai_handle data_activations0[] = {pool0};

/* AI objects ----------------------------------------------------------------*/

static ai_handle ann_1524_trimmed = AI_HANDLE_NULL;

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
  err = ai_ann_1524_trimmed_create_and_init(&ann_1524_trimmed, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    ai_log_err(err, "ai_ann_1524_trimmed_create_and_init");
    return -1;
  }

  ai_input = ai_ann_1524_trimmed_inputs_get(ann_1524_trimmed, NULL);
  ai_output = ai_ann_1524_trimmed_outputs_get(ann_1524_trimmed, NULL);

#if defined(AI_ANN_1524_TRIMMED_INPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-inputs" option is used, memory buffer can be
   *  used from the activations buffer. This is not mandatory.
   */
  for (int idx=0; idx < AI_ANN_1524_TRIMMED_IN_NUM; idx++) {
	data_ins[idx] = ai_input[idx].data;
  }
#else
  for (int idx=0; idx < AI_ANN_1524_TRIMMED_IN_NUM; idx++) {
	  ai_input[idx].data = data_ins[idx];
  }
#endif

#if defined(AI_ANN_1524_TRIMMED_OUTPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-outputs" option is used, memory buffer can be
   *  used from the activations buffer. This is no mandatory.
   */
  for (int idx=0; idx < AI_ANN_1524_TRIMMED_OUT_NUM; idx++) {
	data_outs[idx] = ai_output[idx].data;
  }
#else
  for (int idx=0; idx < AI_ANN_1524_TRIMMED_OUT_NUM; idx++) {
	ai_output[idx].data = data_outs[idx];
  }
#endif

  return 0;
}

static int ai_run(void)
{
  ai_i32 batch;

  batch = ai_ann_1524_trimmed_run(ann_1524_trimmed, ai_input, ai_output);
  if (batch != 1) {
    ai_log_err(ai_ann_1524_trimmed_get_error(ann_1524_trimmed),
        "ai_ann_1524_trimmed_run");
    printf("batch = %f\r\n",batch);
    return -1;
  }

  return 0;
}

int acquire_and_process_data(ai_float* data[], float mag_buffer[6][256]) {

    for (int idx = 0; idx < 6; idx++) {

    	// Skip first value in FFT data
        for (int j = 0; j < 127; j++) {
            data[idx] = &mag_buffer[idx][j + 1]; // Assign values from mag_buffer
        }

    }

    return 0; // Return success
}

int post_process(ai_i8* data[])
{

    //printf("In post process\r\n");
    ai_i8* predicted_region[3];

    // process the predictions
    for (int idx = 0; idx < 3; idx++) {
        predicted_region[idx] = data[idx];
        printf("predicted_region[%d] = %d\r\n\n", idx, *predicted_region[idx]);
    }


  int8_t prev_region,curr_region;

  //printf("Reading predicted region from IPC before write\r\n");
  prev_region = IPCGetPredictedRegion();
  //printf("Predicted region Previous = %d\r\n\n", prev_region);

  //printf("Setting predicted region to IPC\r\n\n");
  IPCSetPredictedRegion((uint8_t)(*predicted_region[0]));

  //printf("Reading predicted region from IPC after write\r\n");
  curr_region = IPCGetPredictedRegion();
  //printf("Predicted region New = %d\r\n\n", curr_region);

  return 0;
}
/* USER CODE END 2 */

/* Entry points --------------------------------------------------------------*/

void MX_X_CUBE_AI_Init(void)
{
    /* USER CODE BEGIN 5 */
  printf("\r\nMX_X_CUBE_AI_Init\r\n");

  ai_boostrap(data_activations0);
  printf("ann_1524_trimmed returns  %d\r\n\n", ((uint8_t*) ann_1524_trimmed)[0]);
    /* USER CODE END 5 */
}

void MX_X_CUBE_AI_Process(float mag_buffer[6][256])
{
    /* USER CODE BEGIN 6 */
  int res = -1;

  printf("\nMX_X_CUBE_AI_Process\r\n\n");

  //printf("ann_1524_trimmed %d\r\n", ((uint8_t*) ann_1524_trimmed)[0]);
  if (ann_1524_trimmed) {

	//AI_RUNNING = TRUE;
    /* 1 - acquire and pre-process input data */
    res = acquire_and_process_data(data_ins,mag_buffer);
    //printf("acquire_and_process returns %d", res);
    /* 2 - process the data - call inference engine */
    if (res == 0 ) res = ai_run();
    //else AI_RUNNING = FALSE;
    /* 3- post-process the predictions */
    if (res == 0) res = post_process(data_outs);
    //else AI_RUNNING = FALSE;

  }


  if (res) {
    ai_error err = {AI_ERROR_INVALID_STATE, AI_ERROR_CODE_NETWORK};
    ai_log_err(err, "Process has FAILED");
  }
    /* USER CODE END 6 */
}
#ifdef __cplusplus
}
#endif
