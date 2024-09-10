/**
 * @file: DRIVER_NVIC.h
 * @brief: NVIC Driver Header
 * @details: This header file provides the interface for the driver of the NVIC module of the MKL46Z256VLL4 microcontroller.
 *           It includes function declarations to manage and handle external interrupts, offering a simplified interface
 *           for enabling and configuring interrupt requests. It also provides the capability to assign a callback function
 *           to handle the interrupt for PORTC and PORTD.
 * @author: Nguyen Dang Nhu Tri
 * @version: 1.0
 * @date: 2024/06/19
 * @copyright: Copyright (c) 2024
 */

#ifndef INCLUDES_DRIVER_DRIVER_NVIC_H_
#define INCLUDES_DRIVER_DRIVER_NVIC_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
#include "../HAL/HAL_NVIC.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef void (*IRQHandler)(void);
/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*
 *@brief Enable the external interrupt for the specified type using the HAL (Hardware Abstraction Layer) function.
 *@param  Type: The IRQn_Type enumeration representing the type of the interrupt.
 *@returns No return value
 */
void DRIVER_NVIC_Enable_External_Interrupt(IRQn_Type Type);

/*
 *@brief Assign a callback function to handle the interrupt for UART0.
 *@param  Callback: A pointer to the IRQHandler function that will be called when an interrupt occurs.
 *@returns No return value
 */
void DRIVER_NVIC_UART0_IRQHandler(IRQHandler Callback);

#endif /* INCLUDES_DRIVER_DRIVER_NVIC_H_ */
