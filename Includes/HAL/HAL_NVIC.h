/**
 * @file: HAL_NVIC.h
 * @brief: NVIC Module Hardware Abstraction Layer Header
 * @details: This header file provides an abstraction layer for the NVIC module of the MKL46Z256VLL4 microcontroller.
 *           It includes function declarations to manage and handle external interrupts, offering a simplified interface
 *           for enabling and configuring interrupt requests.
 * @author: Nguyen Dang Nhu Tri
 * @version: 1.0
 * @date: 2024/06/19
 * @copyright: Copyright (c) 2024
 */

#ifndef INCLUDES_HAL_HAL_NVIC_H_
#define INCLUDES_HAL_HAL_NVIC_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*
 *@brief Enable the external interrupt for the specified type.
 *@param  Type: The IRQn_Type enumeration representing the type of the interrupt.
 *@returns No return value
 */
void HAL_NVIC_Enable_External_Interrupt(IRQn_Type Type);

/*
 *@brief Disable the external interrupt for the specified type.
 *@param  Type: The IRQn_Type enumeration representing the type of the interrupt.
 *@returns No return value
 */
void HAL_NVIC_Disable_External_Interrupt(IRQn_Type Type);

#endif /* INCLUDES_HAL_HAL_NVIC_H_ */
