/*
 * app.c
 *
 *  Created on: Jun 2, 2024
 *      Author: Viet Ha
 */

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "..\Includes\Application_layer\app.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/
static LED_def RED_LED = {PORTE, GPIOE, 29, 1<<29};
static LED_def GREEN_LED = {PORTD, GPIOD, 5, 1<<5};
static Switch_def SW1 = {PORTC, GPIOC, 3, 1<<3};
static Switch_def SW2 = {PORTC, GPIOC, 12, 1<<12};

/*******************************************************************************
 * Prototype
 ******************************************************************************/
static void LED_RedInit(void);

static void LED_GreenInit(void);

/**
 * @brief Turn on the red LED.
 *
 * This function turns on the red LED by clearing the corresponding GPIO pin.
 */
static void LED_RedOn(void);

/**
 * @brief Turn off the red LED.
 *
 * This function turns off the red LED by setting the corresponding GPIO pin.
 */
static void LED_RedOff(void);

/**
 * @brief Turn on the green LED.
 *
 * This function turns on the green LED by clearing the corresponding GPIO pin.
 */
static void LED_GreenOn(void);

/**
 * @brief Turn off the green LED.
 *
 * This function turns off the green LED by setting the corresponding GPIO pin.
 */
static void LED_GreenOff(void);

static void SW1_Init(void);

static void SW2_Init(void);

static uint32_t isSW1_Pressed(void);

static uint32_t isSW2_Pressed(void);

/**
 * @brief This function delays the program execution for a specified number of milliseconds.
 * @param ms The number of milliseconds to delay.
 */
static void APP_Delay(uint32_t time);
/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief Initializes the application by initializing LED and Switch components.
 */
void APP_Init(void)
{
	LED_RedInit();
	LED_GreenInit();
	SW1_Init();
	SW2_Init();
}

/**
 * @brief Runs the application logic based on the state of the switches.
 */
void APP_Run(void)
{
	if (isSW1_Pressed())
	{
		LED_RedOn();
		APP_Delay(1000);
		LED_RedOff();
		APP_Delay(1000);
	}
	else
	{
		LED_RedOff();
	}

	if (isSW2_Pressed())
	{
		LED_GreenOn();
		APP_Delay(2000);
		LED_GreenOff();
		APP_Delay(2000);
	}
	else
	{
		LED_GreenOff();
	}
}

static void LED_RedInit(void)
{
	LED_Init(RED_LED.port, RED_LED.gpio, RED_LED.pin, RED_LED.pinMask);
}

static void LED_GreenInit(void)
{
	LED_Init(GREEN_LED.port, GREEN_LED.gpio, GREEN_LED.pin, GREEN_LED.pinMask);
}

static void LED_RedOn(void)
{
	LED_On(RED_LED.gpio, RED_LED.pinMask);
}

static void LED_RedOff(void)
{
	LED_Off(RED_LED.gpio, RED_LED.pinMask);
}

static void LED_GreenOn(void)
{
	LED_On(GREEN_LED.gpio, GREEN_LED.pinMask);
}

static void LED_GreenOff(void)
{
	LED_Off(GREEN_LED.gpio, GREEN_LED.pinMask);
}

static void SW1_Init(void)
{
	SWITCH_Init(SW1.port, SW1.gpio, SW1.pin, SW1.pinMask);
}

static void SW2_Init(void)
{
	SWITCH_Init(SW2.port, SW2.gpio, SW2.pin, SW2.pinMask);
}

static uint32_t isSW1_Pressed(void)
{
	return SWITCH_isPressed(SW1.gpio, SW1.pinMask);
}

static uint32_t isSW2_Pressed(void)
{
	return SWITCH_isPressed(SW2.gpio, SW2.pinMask);
}

/**
 * @brief This function delays the program execution for a specified number of milliseconds.
 * @param time The number of milliseconds to delay.
 */
static void APP_Delay(uint32_t time)
{
	uint32_t count;

	/* Loop until ms becomes 0 */
	while (time)
	{
		for (count = 0; count < 1500; count++)
		{
			/* No operation */
			__asm("NOP");
		}
		time--;
	}
} /* EOF */
