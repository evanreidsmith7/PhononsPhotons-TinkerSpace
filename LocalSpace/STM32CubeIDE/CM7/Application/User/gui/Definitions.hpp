/*
 * Definitions.h
 *
 *  Created on: Mar 29, 2022
 *      Author: Jessie Smith
 */
#include <stm32h7xx_hal.h>

#ifndef APPLICATION_USER_GUI_DEFINITIONS_H_
#define APPLICATION_USER_GUI_DEFINITIONS_H_


#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC

#define LD1_Pin GPIO_PIN_2
#define LD1_GPIO_Port GPIOJ

typedef enum{
    TRUE = 1,
    FALSE = 0
}boolean_t;

boolean_t getUserButtonState ( void );

void setUserLED1State ( boolean_t state );


#endif /* APPLICATION_USER_GUI_DEFINITIONS_H_ */
