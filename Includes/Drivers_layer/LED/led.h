/*
 * led.h
 *
 *  Created on: Jun 2, 2024
 *      Author: Viet Ha
 */

/*******************************************************************************
 * Header guards
 ******************************************************************************/
#ifndef INCLUDES_DRIVERS_LAYER_LED_LED_H_
#define INCLUDES_DRIVERS_LAYER_LED_LED_H_

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "HAL_layer\hal_gpio.h"
#include "HAL_layer\hal_clock.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/
//#define RED_LED_PIN_MASK (1<<29)
//#define GREEN_LED_PIN_MASK (1<<5)
//#define RED_LED_PIN (29)
//#define GREEN_LED_PIN (5)

typedef struct
{
	PORT_Type *port;
	GPIO_Type *gpio;
	uint32_t pin;
	uint32_t pinMask;
} LED_def;

void LED_Init(PORT_Type *PORTx, GPIO_Type *GPIOx, uint32_t pin, uint32_t pinMask);

void LED_On(GPIO_Type *GPIOx, uint32_t pinMask);

void LED_Off(GPIO_Type *GPIOx, uint32_t pinMask);

#endif /* INCLUDES_DRIVERS_LAYER_LED_LED_H_ */
