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
 * This function initializes the switches by setting up the clock and enabling GPIO pins for switchs.
 * It also configures the pins as input for reading the switch states.
 */
void SWITCH_Init(PORT_Type *PORTx, GPIO_Type *GPIOx, uint32_t pin, uint32_t pinMask)
{
	/* Enable clock for port */
	HAL_PORT_EnableClock(PORTx);

	/* Enable GPIO for switch  */
	HAL_GPIO_SetMuxPinSwitch(PORTx, pin);

	/* Set switch as input */
	HAL_GPIO_SetAsInput(GPIOx, pinMask);
}

/**
 * @brief Check if switch is pressed.
 *
 * This function checks if switch is pressed by reading the GPIO pin.
 *
 * @return 1 if switch is pressed, 0 otherwise.
 */
uint32_t SWITCH_isPressed(GPIO_Type *GPIOx, uint32_t pinMask)
{
	return !HAL_GPIO_ReadPin(GPIOx, pinMask);
} /* EOF */
