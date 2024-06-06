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
#define SW1_PIN_MASK (1<<3)
#define SW2_PIN_MASK (1<<12)
#define SW1_PIN (3)
#define SW2_PIN (12)

/**
 * @brief Initialize the switches.
 *
 * This function initializes the switches by setting up the clock and enabling GPIO pins for switch 1 and switch 2.
 * It also configures the pins as input for reading the switch states.
 */
void Switch_Init(void);

/**
 * @brief Check if switch 1 is pressed.
 *
 * This function checks if switch 1 is pressed by reading the GPIO pin.
 *
 * @return 1 if switch 1 is pressed, 0 otherwise.
 */
uint8_t Switch_IsSw1Pressed(void);

/**
 * @brief Check if switch 2 is pressed.
 *
 * This function checks if switch 2 is pressed by reading the GPIO pin.
 *
 * @return 1 if switch 2 is pressed, 0 otherwise.
 */
uint8_t Switch_IsSw2Pressed(void);

#endif /* INCLUDES_DRIVERS_LAYER_SWITCH_SWITCH_H_ */
