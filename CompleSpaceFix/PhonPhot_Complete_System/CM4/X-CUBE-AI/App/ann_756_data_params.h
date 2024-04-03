/**
  ******************************************************************************
  * @file    ann_756_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    Mon Apr  1 23:14:06 2024
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

#ifndef ANN_756_DATA_PARAMS_H
#define ANN_756_DATA_PARAMS_H
#pragma once

#include "ai_platform.h"

/*
#define AI_ANN_756_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_ann_756_data_weights_params[1]))
*/

#define AI_ANN_756_DATA_CONFIG               (NULL)


#define AI_ANN_756_DATA_ACTIVATIONS_SIZES \
  { 5072, }
#define AI_ANN_756_DATA_ACTIVATIONS_SIZE     (5072)
#define AI_ANN_756_DATA_ACTIVATIONS_COUNT    (1)
#define AI_ANN_756_DATA_ACTIVATION_1_SIZE    (5072)



#define AI_ANN_756_DATA_WEIGHTS_SIZES \
  { 574280, }
#define AI_ANN_756_DATA_WEIGHTS_SIZE         (574280)
#define AI_ANN_756_DATA_WEIGHTS_COUNT        (1)
#define AI_ANN_756_DATA_WEIGHT_1_SIZE        (574280)



#define AI_ANN_756_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_ann_756_activations_table[1])

extern ai_handle g_ann_756_activations_table[1 + 2];



#define AI_ANN_756_DATA_WEIGHTS_TABLE_GET() \
  (&g_ann_756_weights_table[1])

extern ai_handle g_ann_756_weights_table[1 + 2];


#endif    /* ANN_756_DATA_PARAMS_H */
