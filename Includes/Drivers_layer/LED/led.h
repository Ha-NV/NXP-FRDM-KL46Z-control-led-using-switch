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
#define RED_LED_PIN_MASK (1<<29)
#define GREEN_LED_PIN_MASK (1<<5)
#define RED_LED_PIN (29)
#define GREEN_LED_PIN (5)

/**
 * @brief Initialize the LEDs.
 *
 * This function initializes the LEDs by setting up the clock and enabling GPIO pins for red and green LEDs.
 * It also configures the pins as output for controlling the LEDs.
 */
void LED_Init(void);

/**
 * @brief Turn on the red LED.
 *
 * This function turns on the red LED by clearing the corresponding GPIO pin.
 */
void LED_RedOn(void);

/**
 * @brief Turn off the red LED.
 *
 * This function turns off the red LED by setting the corresponding GPIO pin.
 */
void LED_RedOff(void);

/**
 * @brief Turn on the green LED.
 *
 * This function turns on the green LED by clearing the corresponding GPIO pin.
 */
void LED_GreenOn(void);

/**
 * @brief Turn off the green LED.
 *
 * This function turns off the green LED by setting the corresponding GPIO pin.
 */
void LED_GreenOff(void);

#endif /* INCLUDES_DRIVERS_LAYER_LED_LED_H_ */
