/**
 * @file DRIVER_PORT.c
 * @brief Implementation of PORT driver functions.
 * @details This file implements the driver functions defined in `DRIVER_PORT.h` for
 *          configuring and managing PORT peripherals on the microcontroller. It includes
 *          functions for initializing PORT configurations using `PORT_Config` structures,
 *          clearing interrupt status flags, and reading interrupt status flags.
 *          The functions utilize HAL functions to perform low-level operations and ensure
 *          correct configuration and management of PORT peripherals.
 *
 * @author Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/05
 * @copyright Copyright (c) 2024
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "../Includes/DRIVER/DRIVER_PORT.h"
#include <stddef.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*******************************************************************************
 * Code
 ******************************************************************************/

/*
 *@brief Configures the PORT and its pin based on the provided configuration structure.
 *@param PORT_Config Pointer to a PORT_Config structure that contains the settings for the PORT and pin.
 *@returns None
 */
void DRIVER_PORT_Config(PORT_Config *PORT_Config)
{
	if (NULL != PORT_Config->PORTx && 0 <= PORT_Config->Pin && 31 >= PORT_Config->Pin)
	{
		HAL_PORT_PCR_Pin_Mux_Control(PORT_Config->PORTx, PORT_Config->Pin, PORT_Config->PCR.MUX);
		HAL_PORT_PCR_Interrupt_Configuration(PORT_Config->PORTx, PORT_Config->Pin, PORT_Config->PCR.IRQC);
		HAL_PORT_PCR_Pull_Select(PORT_Config->PORTx, PORT_Config->Pin, PORT_Config->PCR.PS);
		HAL_PORT_PCR_Pull_Enable(PORT_Config->PORTx, PORT_Config->Pin, PORT_Config->PCR.PE);
	}
	else
	{
		/* Invalid PORTx or Pin number */
	}
}

/*
 *@brief Clears the interrupt status flag for a specified pin.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number whose interrupt status flag is to be cleared.
 *@returns None
 */
void DRIVER_PORT_PCR_Clear_Interrupt_Status_Flag(PORT_Type *PORTx, uint8_t Pin)
{
	if (NULL != PORTx && 0 <= Pin && 31 >= Pin)
	{
		HAL_PORT_PCR_Clear_Interrupt_Status_Flag(PORTx, Pin); /* Clear the interrupt status flag using the HAL function */
	}
	else
	{
		/* Invalid PORTx or Pin number */
	}
}

/*
 *@brief Reads the interrupt status flag for a specified pin.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number to read the interrupt status flag.
 *@returns Status of the interrupt flag (detected or not detected).
 */
ISFR_ISF_enum DRIVER_PORT_ISFR_Read_Interrupt_Status_Flag(PORT_Type *PORTx, uint8_t Pin)
{
	ISFR_ISF_enum flagStatus = ISFR_ISF_NOT_DETECTED;
	if (NULL != PORTx && 0 <= Pin && 31 >= Pin)
	{
		flagStatus = HAL_PORT_ISFR_Read_Interrupt_Status_Flag(PORTx, Pin); /* Read the interrupt status flag using the HAL function */
	}
	else
	{
		/* Invalid PORTx or Pin number */
	}

	return flagStatus;
}

/* EOF */
