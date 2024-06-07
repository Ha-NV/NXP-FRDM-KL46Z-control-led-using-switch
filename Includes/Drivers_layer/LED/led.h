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
/**
 * @brief Structure defining an LED
 */
typedef struct
{
	PORT_Type *port; 	/* Pointer to the PORT_Type structure */
	GPIO_Type *gpio; 	/* Pointer to the GPIO_Type structure */
	uint32_t pin; 		/* Pin number */
	uint32_t pinMask; 	/* Pin mask */
} LED_def;

/**
 * @brief Initialize the LED
 *
 * @param PORTx Pointer to the PORT_Type structure
 * @param GPIOx Pointer to the GPIO_Type structure
 * @param pin Pin number
 * @param pinMask Pin mask
 */
void LED_Init(PORT_Type *PORTx, GPIO_Type *GPIOx, uint32_t pin, uint32_t pinMask);

/**
 * @brief Turn on the LED.
 *
 * This function clears the specified pin(s) on a given GPIO port to turn on the LED.
 *
 * @param GPIOx Pointer to the GPIO_Type structure that contains the GPIO port registers.
 * @param pinMask The mask representing the pin(s) to be turned on.
 */
void LED_On(GPIO_Type *GPIOx, uint32_t pinMask);

/**
 * @brief Turn off the LED.
 *
 * This function sets the specified pin(s) on a given GPIO port to turn off the LED.
 *
 * @param GPIOx Pointer to the GPIO_Type structure that contains the GPIO port registers.
 * @param pinMask The mask representing the pin(s) to be turned off.
 */
void LED_Off(GPIO_Type *GPIOx, uint32_t pinMask);

#endif /* INCLUDES_DRIVERS_LAYER_LED_LED_H_ */
