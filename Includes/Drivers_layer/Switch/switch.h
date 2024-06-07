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
/**
 * @brief Structure defining a switch.
 */
typedef struct
{
    PORT_Type *port; 	/* Pointer to the PORT_Type structure */
    GPIO_Type *gpio; 	/* Pointer to the GPIO_Type structure */
    uint32_t pin; 		/* The pin number */
    uint32_t pinMask; 	/* The mask representing the pin(s) */
} Switch_def;

/**
 * @brief Initialize the switches.
 *
 * This function initializes the switches by setting up the clock and enabling GPIO pins for switches.
 * It also configures the pins as input for reading the switch states.
 *
 * @param PORTx Pointer to the PORT_Type structure that contains the port registers.
 * @param GPIOx Pointer to the GPIO_Type structure that contains the GPIO port registers.
 * @param pin The pin number to be configured.
 * @param pinMask The mask representing the pin(s) to be set as input.
 */
void SWITCH_Init(PORT_Type *PORTx, GPIO_Type *GPIOx, uint32_t pin, uint32_t pinMask);

/**
 * @brief Check if the switch is pressed.
 *
 * This function checks if the switch connected to the specified GPIO pin is pressed.
 *
 * @param GPIOx Pointer to the GPIO_Type structure that contains the GPIO port registers.
 * @param pinMask The mask representing the pin(s) to be checked.
 * @return 1 if the switch is pressed, 0 otherwise.
 */
uint32_t SWITCH_isPressed(GPIO_Type *GPIOx, uint32_t pinMask);

#endif /* INCLUDES_DRIVERS_LAYER_SWITCH_SWITCH_H_ */
