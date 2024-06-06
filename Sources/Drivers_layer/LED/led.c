/*
 * LED.c
 *
 *  Created on: Jun 2, 2024
 *      Author: Viet Ha
 */

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "..\Includes\Drivers_layer\LED\led.h"

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief Initialize the LEDs.
 *
 * This function initializes the LEDs by setting up the clock and enabling GPIO pins for red and green LEDs.
 * It also configures the pins as output for controlling the LEDs.
 */
void LED_Init(void)
{
	HAL_ClockSetup();

	/* Enable GPIO for PORTE pin 29 (red led) */
	HAL_GPIO_EnablePinLED(PORTE, RED_LED_PIN);
	/* Enable GPIO for PORTD pin 5 (green led) */
	HAL_GPIO_EnablePinLED(PORTD, GREEN_LED_PIN);

	/* Set Red led as output */
	HAL_GPIO_SetAsOutput(GPIOE, RED_LED_PIN_MASK);
	/* Set Green led as output */
	HAL_GPIO_SetAsOutput(GPIOD, GREEN_LED_PIN_MASK);
}

/**
 * @brief Turn on the red LED.
 *
 * This function turns on the red LED by clearing the corresponding GPIO pin.
 */
void LED_RedOn(void)
{
	HAL_GPIO_ClearPin(GPIOE, RED_LED_PIN_MASK);
}

/**
 * @brief Turn off the red LED.
 *
 * This function turns off the red LED by setting the corresponding GPIO pin.
 */
void LED_RedOff(void)
{
	HAL_GPIO_SetPin(GPIOE, RED_LED_PIN_MASK);
}

/**
 * @brief Turn on the green LED.
 *
 * This function turns on the green LED by clearing the corresponding GPIO pin.
 */
void LED_GreenOn(void)
{
	HAL_GPIO_ClearPin(GPIOD, GREEN_LED_PIN_MASK);
}

/**
 * @brief Turn off the green LED.
 *
 * This function turns off the green LED by setting the corresponding GPIO pin.
 */
void LED_GreenOff(void)
{
	HAL_GPIO_SetPin(GPIOD, GREEN_LED_PIN_MASK);
} /* EOF */
