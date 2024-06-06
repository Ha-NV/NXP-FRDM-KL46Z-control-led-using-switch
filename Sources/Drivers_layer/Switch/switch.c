/*
 * switch.c
 *
 *  Created on: Jun 2, 2024
 *      Author: Viet Ha
 */

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "..\Includes\Drivers_layer\Switch\switch.h"

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief Initialize the switches.
 *
 * This function initializes the switches by setting up the clock and enabling GPIO pins for switch 1 and switch 2.
 * It also configures the pins as input for reading the switch states.
 */
void Switch_Init(void)
{
	HAL_ClockSetup();

	/* Enable GPIO for PORTC pin 3 (switch 1)  */
	HAL_GPIO_EnablePinSwitch(PORTC, SW1_PIN);
	/* Enable GPIO for PORTC pin 12 (switch 2)  */
	HAL_GPIO_EnablePinSwitch(PORTC, SW2_PIN);

	/* Set Switch 1 as input */
	HAL_GPIO_SetAsInput(GPIOC, SW1_PIN_MASK);
	/* Set Switch 2 as input */
	HAL_GPIO_SetAsInput(GPIOC, SW2_PIN_MASK);
}

/**
 * @brief Check if switch 1 is pressed.
 *
 * This function checks if switch 1 is pressed by reading the GPIO pin.
 *
 * @return 1 if switch 1 is pressed, 0 otherwise.
 */
uint8_t Switch_IsSw1Pressed(void)
{
	return !HAL_GPIO_ReadPin(GPIOC, SW1_PIN_MASK);
}

/**
 * @brief Check if switch 2 is pressed.
 *
 * This function checks if switch 2 is pressed by reading the GPIO pin.
 *
 * @return 1 if switch 2 is pressed, 0 otherwise.
 */
uint8_t Switch_IsSw2Pressed(void)
{
	return !HAL_GPIO_ReadPin(GPIOC, SW2_PIN_MASK);
} /* EOF */
