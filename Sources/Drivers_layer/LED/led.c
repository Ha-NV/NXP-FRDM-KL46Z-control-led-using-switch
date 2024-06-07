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

void LED_Init(PORT_Type *PORTx, GPIO_Type *GPIOx, uint32_t pin, uint32_t pinMask)
{
	HAL_PORT_EnableClock(PORTx);

	/* Enable GPIO */
	HAL_GPIO_SetMuxPinLED(PORTx, pin);

	/* Set LED as output */
	HAL_GPIO_SetAsOutput(GPIOx, pinMask);
}

void LED_On(GPIO_Type *GPIOx, uint32_t pinMask)
{
	HAL_GPIO_ClearPin(GPIOx, pinMask);
}

void LED_Off(GPIO_Type *GPIOx, uint32_t pinMask)
{
	HAL_GPIO_SetPin(GPIOx, pinMask);
} /* EOF */
