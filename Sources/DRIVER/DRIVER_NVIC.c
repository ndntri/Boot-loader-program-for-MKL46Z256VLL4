/**
 * @file: DRIVER_NVIC.c
 * @brief: NVIC Driver Implementation
 * @details: This file provides the implementation of the driver for the NVIC module of the MKL46Z256VLL4 microcontroller.
 *           It includes functions to manage and handle external interrupts, offering a simplified interface
 *           for enabling and configuring interrupt requests. It also provides the capability to assign a callback function
 *           to handle the interrupt for PORTC and PORTD.
 * @author: Nguyen Dang Nhu Tri
 * @version: 1.0
 * @date: 2024/06/19
 * @copyright: Copyright (c) 2024
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "../Includes/DRIVER/DRIVER_NVIC.h"
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

static void (*IRQHandler_Callback)(void); /* Define a function pointer to handle the interrupt */

/*
 *@brief Enable the external interrupt for the specified type using the HAL (Hardware Abstraction Layer) function.
 *@param  Type: The IRQn_Type enumeration representing the type of the interrupt.
 *@returns No return value
 */
void DRIVER_NVIC_Enable_External_Interrupt(IRQn_Type Type)
{
    HAL_NVIC_Enable_External_Interrupt(Type); /* Enable the external interrupt using the HAL function */
}

/*
 *@brief Assign a callback function to handle the interrupt for UART0.
 *@param  Callback: A pointer to the IRQHandler function that will be called when an interrupt occurs.
 *@returns No return value
 */
void DRIVER_NVIC_UART0_IRQHandler(IRQHandler Callback)
{
    IRQHandler_Callback = Callback; /* Assign the callback function to handle the interrupt */
}

/*
 *@brief The Interrupt Service Routine (ISR) for UART 0.
 *@returns No return value
 */
void UART0_IRQHandler(void)
{
    IRQHandler_Callback(); /* Call the assigned callback function to handle the interrupt */
}

/* EOF */
