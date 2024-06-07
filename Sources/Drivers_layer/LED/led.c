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
 * @brief Initialize the LED
 *
 * @param PORTx Pointer to the PORT_Type structure
 * @param GPIOx Pointer to the GPIO_Type structure
 * @param pin Pin number
 * @param pinMask Pin mask
 */
void LED_Init(PORT_Type *PORTx, GPIO_Type *GPIOx, uint32_t pin, uint32_t pinMask)
{
	HAL_PORT_EnableClock(PORTx);

	/* Enable GPIO */
	HAL_GPIO_SetMuxPinLED(PORTx, pin);

	/* Set LED as output */
	HAL_GPIO_SetAsOutput(GPIOx, pinMask);
}

/**
 * @brief Turn on the LED.
 *
 * This function clears the specified pin(s) on a given GPIO port to turn on the LED.
 *
 * @param GPIOx Pointer to the GPIO_Type structure that contains the GPIO port registers.
 * @param pinMask The mask representing the pin(s) to be turned on.
 */
void LED_On(GPIO_Type *GPIOx, uint32_t pinMask)
{
	HAL_GPIO_ClearPin(GPIOx, pinMask);
}

/**
 * @brief Turn off the LED.
 *
 * This function sets the specified pin(s) on a given GPIO port to turn off the LED.
 *
 * @param GPIOx Pointer to the GPIO_Type structure that contains the GPIO port registers.
 * @param pinMask The mask representing the pin(s) to be turned off.
 */
void LED_Off(GPIO_Type *GPIOx, uint32_t pinMask)
{
	HAL_GPIO_SetPin(GPIOx, pinMask);
} /* EOF */
