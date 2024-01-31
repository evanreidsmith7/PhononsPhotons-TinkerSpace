/*
 * Definitions.cpp
 *
 *  Created on: Mar 29, 2022
 *      Author: Jessie Smith
 */

#include "Definitions.hpp"

boolean_t getUserButtonState ( void )
{
  return (HAL_GPIO_ReadPin( B1_GPIO_Port, B1_Pin) ? TRUE : FALSE);
}

void setUserLED1State ( boolean_t state )
{
  HAL_GPIO_WritePin( LD1_GPIO_Port, LD1_Pin, (state ? GPIO_PIN_RESET : GPIO_PIN_SET));
}


