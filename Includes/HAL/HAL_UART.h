/**
 * @file HAL_UART.h
 * @brief  UART Hardware Abstraction Layer (HAL) Header File
 * @details  Provides function prototypes and type definitions for UART configuration and control.
 *           Includes functions for setting baud rate, managing control registers, and checking UART status.
 *
 * @author  Nguyen Dang Nhu Tri
 * @version 1.0
 * @date    2024/07/05
 * @copyright Copyright (c) 2024 Nguyen Dang Nhu Tri.
 */

#ifndef INCLUDES_HAL_HAL_UART_H_
#define INCLUDES_HAL_HAL_UART_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*
 *@brief  UART number enumeration
 *@details  This enumeration defines the UART module numbers.
 */
typedef enum UART_NUMBER
{
    UART_NUMBER_0, /* UART number 0 */
    UART_NUMBER_1, /* UART number 1 */
    UART_NUMBER_2  /* UART number 2 */
} UART_NUMBER;

/*
 *@brief  UART BDH Stop Bit Number Select enumeration
 *@details  This enumeration defines the stop bit configurations for the UART BDH register.
 */
typedef enum UART_BDH_Stop_Bit_Number_Select
{
    BDH_SBNS_ONE = 0b00, /* One stop bit. */
    BDH_SBNS_TWO = 0b01  /* Two stop bits. */
} BDH_SBNS_enum;
/*
 *@brief  UART C2 Transmitter Enable enumeration
 *@details  This enumeration defines the enable/disable states for the UART transmitter.
 */
typedef enum UART_C2_Transmitter_Enable
{
    C2_TE_DISABLED = 0, /* Transmitter disabled */
    C2_TE_ENABLED = 1   /* Transmitter enabled */
} C2_TE_enum;

/*
 *@brief  UART C2 Receiver Enable enumeration
 *@details  This enumeration defines the enable/disable states for the UART receiver.
 */
typedef enum UART_C2_Receiverr_Enable
{
    C2_RE_DISABLED = 0, /* Receiver disabled */
    C2_RE_ENABLED = 1   /* Receiver enabled */
} C2_RE_enum;

/*
 * @brief  UART Control Register 2 (C2) Receiver Interrupt Enable enumeration
 * @details  This enumeration defines the states for enabling or disabling
 *           the receiver interrupt.
 */
typedef enum
{
    C2_RIE_DISABLED = 0, /* Receiver interrupt disabled */
    C2_RIE_ENABLED = 1   /* Receiver interrupt enabled */
} C2_RIE_enum;

/*
 *@brief  UART S1 RDRF Receive Data Register Full Flag enumeration
 *@details  This enumeration defines the states of the receive data buffer.
 */
typedef enum UART_S1_RDRF_Receive_Data_Register_Full_Flag
{
    S1_RDRF_EMPTY = 0, /* Receive data buffer empty */
    S1_RDRF_FULL = 1   /* Receive data buffer full */
} S1_RDRF_enum;

/*
 *@brief  UART S1 TC Transmission Complete Flag enumeration
 *@details  This enumeration defines the states of the transmission completion flag.
 */
typedef enum UART_S1_TC_Transmission_Complete_Flag
{
    S1_TC_ACTIVE = 0,  /* Transmitter active (sending data, a preamble, or a break) */
    S1_TC_COMPLETE = 1 /* Transmitter idle (transmission activity complete) */
} S1_TC_enum;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*
 *@brief  Set the UART Baud Rate Modulo Divisor
 *@param  UARTx: Pointer to the UART peripheral
 *@param  value: Baud rate modulo divisor value
 *@returns  None
 */
void HAL_UART_BDL_Baud_Rate_Modulo_Divisor(UART_Type *UARTx, uint8_t value);

/*
 *@brief  Set the UART Baud Rate Modulo Divisor (High Register)
 *@param  UARTx: Pointer to the UART peripheral
 *@param  value: Baud rate modulo divisor value
 *@returns  None
 */
void HAL_UART_BDH_Baud_Rate_Modulo_Divisor(UART_Type *UARTx, uint8_t value);

/*
 *@brief  Select the number of stop bits for UART
 *@param  UARTx: Pointer to the UART peripheral
 *@param  stop_bit: Stop bit selection (BDH_SBNS_enum)
 *@returns  None
 */
void HAL_UART_BDH_Stop_Bit_Number_Select(UART_Type *UARTx, BDH_SBNS_enum stop_bit);

/*
 *@brief  Enable or disable the UART transmitter
 *@param  UARTx: Pointer to the UART peripheral
 *@param  state: Transmitter enable state (C2_TE_enum)
 *@returns  None
 */
void HAL_UART_C2_Transmitter_Enable(UART_Type *UARTx, C2_TE_enum state);

/*
 *@brief  Enable or disable the UART receiver
 *@param  UARTx: Pointer to the UART peripheral
 *@param  state: Receiver enable state (C2_RE_enum)
 *@returns  None
 */
void HAL_UART_C2_Receiverr_Enable(UART_Type *UARTx, C2_RE_enum state);

/*
 *@brief  Enable or disable the UART Receiver Interrupt
 *@param  UARTx: Pointer to the UART peripheral
 *@param  state: Receiver Interrupt enable state (C2_RE_enum)
 *@returns  None
 */
void HAL_UART_C2_Receiver_Interrupt_Enable_for_RDRF(UART_Type *UARTx, C2_RIE_enum state);

/*
 *@brief  Check the UART receive data register full flag
 *@param  UARTx: Pointer to the UART peripheral
 *@returns  S1_RDRF_enum: Receive data register full flag status
 */
S1_RDRF_enum HAL_UART_S1_Receive_Data_Register_Full_Flag(UART_Type *UARTx);

/*
 *@brief  Check the UART transmission complete flag
 *@param  UARTx: Pointer to the UART peripheral
 *@returns  S1_TC_enum: Transmission complete flag status
 */
S1_TC_enum HAL_UART_S1_Transmission_Complete_Flag(UART_Type *UARTx);

/*
 *@brief  Write to the UART transmit data buffer
 *@param  UARTx: Pointer to the UART peripheral
 *@param  value: Data to be transmitted
 *@returns  None
 */
void HAL_UART_D_Write_transmit_data_buffer(UART_Type *UARTx, uint8_t value);

/*
 *@brief  Read from the UART receive data buffer
 *@param  UARTx: Pointer to the UART peripheral
 *@returns  uint8_t: Received data
 */
uint8_t HAL_UART_D_Read_receive_data_buffer(UART_Type *UARTx);

#endif /* INCLUDES_HAL_HAL_UART_H_ */
