/*
 * app.h
 *
 *  Created on: Jun 2, 2024
 *      Author: Viet Ha
 */

/*******************************************************************************
 * Header guards
 ******************************************************************************/
#ifndef INCLUDES_APPLICATION_LAYER_APP_H_
#define INCLUDES_APPLICATION_LAYER_APP_H_

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "Drivers_layer\LED\led.h"
#include "Drivers_layer\Switch\switch.h"

/*******************************************************************************
 * Prototype
 ******************************************************************************/
/**
 * @brief Initializes the application by initializing LED and Switch components.
 */
void APP_Init(void);

/**
 * @brief Runs the application logic based on the state of the switches.
 */
void APP_Run(void);

#endif /* INCLUDES_APPLICATION_LAYER_APP_H_ */
