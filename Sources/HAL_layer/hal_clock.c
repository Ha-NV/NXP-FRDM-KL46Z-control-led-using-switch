/*
 * hal_clock.c
 *
 *  Created on: Jun 2, 2024
 *      Author: Viet Ha
 */

/*******************************************************************************
 * Include
 ******************************************************************************/
# include "..\Includes\HAL_layer\hal_clock.h"

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief Setup clock for PORTx.
 *
 * This function enables the clock for PORTx.
 */
void HAL_PORT_EnableClock(PORT_Type *port)
{
	if (port == PORTA)
	{
		SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	}
	else if (port == PORTB)
	{
		SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
	}
	else if (port == PORTC)
	{
		SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	}
	else if (port == PORTD)
	{
		SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
	}
	else if (port == PORTE)
	{
		SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	}
} /* EOF */
