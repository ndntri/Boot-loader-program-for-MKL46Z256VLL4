/**
 * @file HAL_PORT.c
 * @brief This file contains HAL functions for configuring PORT peripherals on the microcontroller.
 * @details It provides functions to configure pin muxing, pull-up/pull-down resistors,
 *          interrupt configurations, and handling interrupt status flags.
 *          This file supports various operations on PORT peripherals using specific enums and structures.
 * @author Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/05
 * @copyright Copyright (c) 2024
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "../Includes/HAL/HAL_PORT.h"
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
 *@brief Configures the pin mux control settings.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number to configure.
 *@param Mux_Type MUX type to be set (e.g., analog, GPIO, alternate functions).
 *@returns None
 */
void HAL_PORT_PCR_Pin_Mux_Control(PORT_Type *PORTx, uint8_t Pin, PCR_MUX_enum Mux_Type)
{
	PORTx->PCR[Pin] = (PORTx->PCR[Pin] & ~PORT_PCR_MUX_MASK) | PORT_PCR_MUX(Mux_Type);
}

/*
 *@brief Configures the pull-up or pull-down resistor enable state.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number to configure.
 *@param Pull_State Pull-up or pull-down resistor enable state (enable or disable).
 *@returns None
 */
void HAL_PORT_PCR_Pull_Enable(PORT_Type *PORTx, uint8_t Pin, PCR_PE_enum Pull_State)
{
	PORTx->PCR[Pin] = (PORTx->PCR[Pin] & ~PORT_PCR_PE_MASK) | PORT_PCR_PE(Pull_State);
}

/*
 *@brief Selects the pull-up or pull-down resistor type.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number to configure.
 *@param Pull_Select Pull-up or pull-down resistor selection.
 *@returns None
 */
void HAL_PORT_PCR_Pull_Select(PORT_Type *PORTx, uint8_t Pin, PCR_PS_enum Pull_Select)
{
	PORTx->PCR[Pin] = (PORTx->PCR[Pin] & ~PORT_PCR_PS_MASK) | PORT_PCR_PS(Pull_Select);
}
/*
 *@brief Configures the interrupt or DMA request settings for a pin.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number to configure.
 *@param Config Interrupt or DMA request configuration.
 *@returns None
 */
void HAL_PORT_PCR_Interrupt_Configuration(PORT_Type *PORTx, uint8_t Pin, PCR_IRQC_enum Config)
{
	PORTx->PCR[Pin] = (PORTx->PCR[Pin] & ~PORT_PCR_IRQC_MASK) | PORT_PCR_IRQC(Config);
}

/*
 *@brief Clears the interrupt status flag for a pin.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number whose interrupt status flag is to be cleared.
 *@returns None
 */
void HAL_PORT_PCR_Clear_Interrupt_Status_Flag(PORT_Type *PORTx, uint8_t Pin)
{
	PORTx->PCR[Pin] |= 0x1000000u; /* Write 1 to clear the interrupt status flag */
}

/*
 *@brief Reads the interrupt status flag for a pin.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number to read the interrupt status flag.
 *@returns Status of the interrupt flag (detected or not detected).
 */
ISFR_ISF_enum HAL_PORT_ISFR_Read_Interrupt_Status_Flag(PORT_Type *PORTx, uint8_t Pin)
{
	ISFR_ISF_enum status = ISFR_ISF_NOT_DETECTED;

	if (PORTx->ISFR & (1 << Pin))
	{
		status = ISFR_ISF_DETECTED;
	}
	else
	{
		/* Do nothing */
	}

	return status;
}

/* EOF */
