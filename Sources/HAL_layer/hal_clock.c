/*
 * hal_clock.c
 *
 *  Created on: Jun 2, 2024
 *      Author: Viet Ha
 */

# include "..\Includes\HAL_layer\hal_clock.h"

/**
 * @brief Setup clock for PORTC, PORTD, and PORTE.
 *
 * This function enables the clock for PORTC, PORTD, and PORTE.
 */
void HAL_ClockSetup(void)
{
	/* Enable clock for PORTC */
	SIM->SCGC5 |= 1<<11;

	/* Enable clock for PORTD */
	SIM->SCGC5 |= 1<<12;

	/* Enable clock for PORTE */
	SIM->SCGC5 |= 1<<13;
} /* EOF */
