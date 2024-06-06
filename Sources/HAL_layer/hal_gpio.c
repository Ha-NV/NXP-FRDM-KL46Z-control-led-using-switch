/*
 * HAL_gpio.c
 *
 *  Created on: Jun 2, 2024
 *      Author: Viet Ha
 */

/*******************************************************************************
 * Include
 ******************************************************************************/
# include "..\Includes\HAL_layer\hal_gpio.h"	/* Include the header file for GPIO functionality */

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief Enable the GPIO pin for LED usage.
 *
 * This function configures a specific pin on a given port to be used as an LED output.
 * It sets the pin's MUX field to specify GPIO functionality.
 *
 * @param port Pointer to the PORT_Type structure that contains the port registers.
 * @param pin The pin number to be configured.
 */
void HAL_GPIO_EnablePinLED(PORT_Type *port, uint32_t pin)
{
	port->PCR[pin] = PORT_PCR_MUX(1);
}

/**
 * @brief Enable the GPIO pin for switch usage.
 *
 * This function configures a specific pin on a given port to be used as a switch input.
 * It sets the pin's MUX field to specify GPIO functionality, enables the internal pull-up resistor,
 * and configures the pin as a digital input.
 *
 * @param port Pointer to the PORT_Type structure that contains the port registers.
 * @param pin The pin number to be configured.
 */
void HAL_GPIO_EnablePinSwitch(PORT_Type *port, uint32_t pin)
{
    port->PCR[pin] |= PORT_PCR_MUX(1);
    port->PCR[pin] |= PORT_PCR_PE_MASK;
    port->PCR[pin] |= PORT_PCR_PS_MASK;
}

/**
 * @brief Set the GPIO pin as an output.
 *
 * This function sets a specific pin on a given GPIO port as an output by configuring the corresponding bit in the Port Data Direction Register (PDDR).
 *
 * @param GPIO_port Pointer to the GPIO_Type structure that contains the GPIO port registers.
 * @param pinMask The mask representing the pin(s) to be set as output.
 */
void HAL_GPIO_SetAsOutput(GPIO_Type *GPIO_port, uint32_t pinMask)
{
	GPIO_port->PDDR |= pinMask;
}

/**
 * @brief Set the GPIO pin as an input.
 *
 * This function sets a specific pin on a given GPIO port as an input by clearing the corresponding bit in the Port Data Direction Register (PDDR).
 *
 * @param GPIO_port Pointer to the GPIO_Type structure that contains the GPIO port registers.
 * @param pinMask The mask representing the pin(s) to be set as input.
 */
void HAL_GPIO_SetAsInput(GPIO_Type *GPIO_port, uint32_t pinMask)
{
	GPIO_port->PDDR &= ~pinMask;
}

/**
 * @brief Set the specified GPIO pin.
 *
 * This function sets the specified pin(s) on a given GPIO port by setting the corresponding bits in the Port Set Output Register (PSOR).
 *
 * @param GPIO_port Pointer to the GPIO_Type structure that contains the GPIO port registers.
 * @param pinMask The mask representing the pin(s) to be set.
 */
void HAL_GPIO_SetPin(GPIO_Type *GPIO_port, uint32_t pinMask)
{
	GPIO_port->PSOR |= pinMask;
}

/**
 * @brief Clear the specified GPIO pin.
 *
 * This function clears the specified pin(s) on a given GPIO port by setting the corresponding bits in the Port Clear Output Register (PCOR).
 *
 * @param GPIO_port Pointer to the GPIO_Type structure that contains the GPIO port registers.
 * @param pinMask The mask representing the pin(s) to be cleared.
 */
void HAL_GPIO_ClearPin(GPIO_Type *GPIO_port, uint32_t pinMask)
{
	GPIO_port->PCOR |= pinMask;
}

/**
 * @brief Read the value of the specified GPIO pin.
 *
 * This function reads the value of the specified pin on a given GPIO port by masking the Port Data Input Register (PDIR).
 *
 * @param GPIO_port Pointer to the GPIO_Type structure that contains the GPIO port registers.
 * @param pinMask The mask representing the pin(s) to be read.
 * @return The value of the specified pin.
 */
uint32_t HAL_GPIO_ReadPin(GPIO_Type *GPIO_port, uint32_t pinMask)
{
	return GPIO_port->PDIR & pinMask;
} /* EOF */
