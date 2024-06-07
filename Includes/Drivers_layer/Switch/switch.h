/*
 * switch.h
 *
 *  Created on: Jun 2, 2024
 *      Author: Viet Ha
 */

/*******************************************************************************
 * Header guards
 ******************************************************************************/
#ifndef INCLUDES_DRIVERS_LAYER_SWITCH_SWITCH_H_
#define INCLUDES_DRIVERS_LAYER_SWITCH_SWITCH_H_

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "HAL_layer\hal_gpio.h"
#include "HAL_layer\hal_clock.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/
typedef struct
{
	PORT_Type *port;
	GPIO_Type *gpio;
	uint32_t pin;
	uint32_t pinMask;
} Switch_def;

/**
 * @brief Initialize the switches.
 *
 * This function initializes the switches by setting up the clock and enabling GPIO pins for switchs.
 * It also configures the pins as input for reading the switch states.
 */
void SWITCH_Init(PORT_Type *PORTx, GPIO_Type *GPIOx, uint32_t pin, uint32_t pinMask);

/**
 * @brief Check if switch is pressed.
 *
 * This function checks if switch is pressed by reading the GPIO pin.
 *
 * @return 1 if switch is pressed, 0 otherwise.
 */
uint32_t SWITCH_isPressed(GPIO_Type *GPIOx, uint32_t pinMask);

#endif /* INCLUDES_DRIVERS_LAYER_SWITCH_SWITCH_H_ */
