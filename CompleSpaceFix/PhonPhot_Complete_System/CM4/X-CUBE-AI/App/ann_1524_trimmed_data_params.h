/**
  ******************************************************************************
  * @file    ann_1524_trimmed_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    Fri Mar 29 06:49:08 2024
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#ifndef ANN_1524_TRIMMED_DATA_PARAMS_H
#define ANN_1524_TRIMMED_DATA_PARAMS_H
#pragma once

#include "ai_platform.h"

/*
#define AI_ANN_1524_TRIMMED_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_ann_1524_trimmed_data_weights_params[1]))
*/

#define AI_ANN_1524_TRIMMED_DATA_CONFIG               (NULL)


#define AI_ANN_1524_TRIMMED_DATA_ACTIVATIONS_SIZES \
  { 9120, }
#define AI_ANN_1524_TRIMMED_DATA_ACTIVATIONS_SIZE     (9120)
#define AI_ANN_1524_TRIMMED_DATA_ACTIVATIONS_COUNT    (1)
#define AI_ANN_1524_TRIMMED_DATA_ACTIVATION_1_SIZE    (9120)



#define AI_ANN_1524_TRIMMED_DATA_WEIGHTS_SIZES \
  { 801544, }
#define AI_ANN_1524_TRIMMED_DATA_WEIGHTS_SIZE         (801544)
#define AI_ANN_1524_TRIMMED_DATA_WEIGHTS_COUNT        (1)
#define AI_ANN_1524_TRIMMED_DATA_WEIGHT_1_SIZE        (801544)



#define AI_ANN_1524_TRIMMED_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_ann_1524_trimmed_activations_table[1])

extern ai_handle g_ann_1524_trimmed_activations_table[1 + 2];



#define AI_ANN_1524_TRIMMED_DATA_WEIGHTS_TABLE_GET() \
  (&g_ann_1524_trimmed_weights_table[1])

extern ai_handle g_ann_1524_trimmed_weights_table[1 + 2];


#endif    /* ANN_1524_TRIMMED_DATA_PARAMS_H */
