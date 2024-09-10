/**
 * @file HAL_UART.c
 * @brief  UART Hardware Abstraction Layer (HAL) Implementation
 * @details  Implements functions for configuring UART settings, enabling/disabling transmitter and receiver,
 *           and handling data transmission and reception.
 *           Functions include setting baud rate, stop bits, and checking UART status flags.
 *
 * @author  Nguyen Dang Nhu Tri
 * @version 1.0
 * @date    2024/07/05
 * @copyright Copyright (c) 2024 Nguyen Dang Nhu Tri.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "../Includes/HAL/HAL_UART.h"
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
 *@brief  Set the UART Baud Rate Modulo Divisor
 *@param  UARTx: Pointer to the UART peripheral
 *@param  value: Baud rate modulo divisor value
 *@returns  None
 */
void HAL_UART_BDL_Baud_Rate_Modulo_Divisor(UART_Type *UARTx, uint8_t value)
{
    UARTx->BDL = (UARTx->BDL & ~UART_BDL_SBR_MASK) | UART_BDL_SBR(value);
}

/*
 *@brief  Set the UART Baud Rate Modulo Divisor (High Register)
 *@param  UARTx: Pointer to the UART peripheral
 *@param  value: Baud rate modulo divisor value
 *@returns  None
 */
void HAL_UART_BDH_Baud_Rate_Modulo_Divisor(UART_Type *UARTx, uint8_t value)
{
    UARTx->BDH = (UARTx->BDH & ~UART_BDH_SBR_MASK) | UART_BDH_SBR(value);
}

/*
 *@brief  Select the number of stop bits for UART
 *@param  UARTx: Pointer to the UART peripheral
 *@param  stop_bit: Stop bit selection (BDH_SBNS_enum)
 *@returns  None
 */
void HAL_UART_BDH_Stop_Bit_Number_Select(UART_Type *UARTx, BDH_SBNS_enum stop_bit)
{
    UARTx->BDH = (UARTx->BDH & ~UART_BDH_SBNS_MASK) | UART_BDH_SBNS(stop_bit);
}

/*
 *@brief  Enable or disable the UART transmitter
 *@param  UARTx: Pointer to the UART peripheral
 *@param  state: Transmitter enable state (C2_TE_enum)
 *@returns  None
 */
void HAL_UART_C2_Transmitter_Enable(UART_Type *UARTx, C2_TE_enum state)
{
    UARTx->C2 = (UARTx->C2 & ~UART_C2_TE_MASK) | UART_C2_TE(state);
}

/*
 *@brief  Enable or disable the UART receiver
 *@param  UARTx: Pointer to the UART peripheral
 *@param  state: Receiver enable state (C2_RE_enum)
 *@returns  None
 */
void HAL_UART_C2_Receiverr_Enable(UART_Type *UARTx, C2_RE_enum state)
{
    UARTx->C2 = (UARTx->C2 & ~UART_C2_RE_MASK) | UART_C2_RE(state);
}

/*
 * @brief  Enable or disable the UART receiver interrupt for RDRF
 * @param  UARTx: Pointer to the UART peripheral
 * @param  state: Receiver interrupt enable state (C2_RIE_enum)
 * @returns  None
 */
void HAL_UART_C2_Receiver_Interrupt_Enable_for_RDRF(UART_Type *UARTx, C2_RIE_enum state)
{
    UARTx->C2 = (UARTx->C2 & ~UART_C2_RIE_MASK) | UART_C2_RIE(state);
}

/*
 *@brief  Check the UART receive data register full flag
 *@param  UARTx: Pointer to the UART peripheral
 *@returns  S1_RDRF_enum: Receive data register full flag status
 */
S1_RDRF_enum HAL_UART_S1_Receive_Data_Register_Full_Flag(UART_Type *UARTx)
{
    S1_RDRF_enum flagStatus;

    if (UARTx->S1 & UART_S1_RDRF_MASK)
    {
        flagStatus = S1_RDRF_FULL;
    }
    else
    {
        flagStatus = S1_RDRF_EMPTY;
    }

    return flagStatus;
}

/*
 *@brief  Check the UART transmission complete flag
 *@param  UARTx: Pointer to the UART peripheral
 *@returns  S1_TC_enum: Transmission complete flag status
 */
S1_TC_enum HAL_UART_S1_Transmission_Complete_Flag(UART_Type *UARTx)
{
    S1_TC_enum flagStatus;

    if (UARTx->S1 & UART_S1_TC_MASK)
    {
        flagStatus = S1_TC_COMPLETE;
    }
    else
    {
        flagStatus = S1_TC_ACTIVE;
    }

    return flagStatus;
}

/*
 *@brief  Write to the UART transmit data buffer
 *@param  UARTx: Pointer to the UART peripheral
 *@param  value: Data to be transmitted
 *@returns  None
 */
void HAL_UART_D_Write_transmit_data_buffer(UART_Type *UARTx, uint8_t value)
{
    UARTx->D = value;
}

/*
 *@brief  Read from the UART receive data buffer
 *@param  UARTx: Pointer to the UART peripheral
 *@returns  uint8_t: Received data
 */
uint8_t HAL_UART_D_Read_receive_data_buffer(UART_Type *UARTx)
{
    return UARTx->D;
}

/* EOF */
