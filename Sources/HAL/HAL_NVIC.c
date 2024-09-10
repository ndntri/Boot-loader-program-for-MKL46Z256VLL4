/**
 * @file: HAL_NVIC.c
 * @brief: NVIC Module Hardware Abstraction Layer
 * @details: This file provides an abstraction layer for the NVIC module of the MKL46Z256VLL4 microcontroller.
 *           It includes functions to manage and handle external interrupts, offering a simplified interface
 *           for enabling and configuring interrupt requests.
 * @author: Nguyen Dang Nhu Tri
 * @version: 1.0
 * @date: 2024/06/19
 * @copyright: Copyright (c) 2024
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "../Includes/HAL/HAL_NVIC.h"
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
 *@brief Enable the external interrupt for the specified type.
 *@param  Type: The IRQn_Type enumeration representing the type of the interrupt.
 *@returns No return value
 */
void HAL_NVIC_Enable_External_Interrupt(IRQn_Type Type)
{
    NVIC_EnableIRQ(Type); /* Enable the external interrupt */
}

/*
 *@brief Disable the external interrupt for the specified type.
 *@param  Type: The IRQn_Type enumeration representing the type of the interrupt.
 *@returns No return value
 */
void HAL_NVIC_Disable_External_Interrupt(IRQn_Type Type)
{
    NVIC_DisableIRQ(Type); /* Disable the external interrupt */
}

/* EOF */
