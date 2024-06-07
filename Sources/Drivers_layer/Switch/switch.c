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
 * This function initializes the switches by setting up the clock and enabling GPIO pins for switches.
 * It also configures the pins as input for reading the switch states.
 *
 * @param PORTx Pointer to the PORT_Type structure that contains the port registers.
 * @param GPIOx Pointer to the GPIO_Type structure that contains the GPIO port registers.
 * @param pin The pin number to be configured.
 * @param pinMask The mask representing the pin(s) to be set as input.
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
 * @brief Check if the switch is pressed.
 *
 * This function checks if the switch connected to the specified GPIO pin is pressed.
 *
 * @param GPIOx Pointer to the GPIO_Type structure that contains the GPIO port registers.
 * @param pinMask The mask representing the pin(s) to be checked.
 * @return 1 if the switch is pressed, 0 otherwise.
 */
uint32_t SWITCH_isPressed(GPIO_Type *GPIOx, uint32_t pinMask)
{
	return !HAL_GPIO_ReadPin(GPIOx, pinMask);
} /* EOF */
