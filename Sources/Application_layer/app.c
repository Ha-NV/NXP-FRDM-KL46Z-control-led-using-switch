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
 * Prototype
 ******************************************************************************/
/**
 * @brief This function delays the program execution for a specified number of milliseconds.
 * @param ms The number of milliseconds to delay.
 */
static void APP_Delay_ms(uint32_t ms);

static void LED_RedOn()
{
	/* Call functions to turn on Red led */
}

static void LED_RedOff()
{
	/* Call function to turn off Green led */
}

static void LED_GreenOn()
{
	/* Call function to turn on Green led */
}

static void LED_GreenOff()
{
	/* Call function to turn off Green led */
}

static void Switch_IsSwitch1Pressed()
{
	/* Check if switch 1 is pressed */
}

static void Switch_IsSwitch2Press()
{
	/* Check if switch 2 is pressed */
}

static void test_git()
{
	/* Do nothing */
}

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief Initializes the application by initializing LED and Switch components.
 */
void APP_Init(void)
{
	LED_Init();
	Switch_Init();
}

/**
 * @brief Runs the application logic based on the state of the switches.
 */
void APP_Run(void)
{
	if (Switch_IsSw1Pressed())
	{
		LED_RedOn();
		APP_Delay_ms(1000);
		LED_RedOff();
		APP_Delay_ms(1000);
	}
	else
	{
		LED_RedOff();
	}

	if (Switch_IsSw2Pressed())
	{
		LED_GreenOn();
		APP_Delay_ms(2000);
		LED_GreenOff();
		APP_Delay_ms(2000);
	}
	else
	{
		LED_GreenOff();
	}
}

/**
 * @brief This function delays the program execution for a specified number of milliseconds.
 * @param ms The number of milliseconds to delay.
 */
static void APP_Delay_ms(uint32_t ms)
{
	uint32_t count;

	/* Loop until ms becomes 0 */
	while (ms)
	{
		for (count = 0; count < 1500; count++)
		{
			/* No operation */
			__asm("NOP");
		}
		ms--;
	}
} /* EOF */
