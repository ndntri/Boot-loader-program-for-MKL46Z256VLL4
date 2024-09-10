/**
 * @file DRIVER_UART.c
 * @brief  UART Driver Implementation
 * @details  Implements high-level UART driver functions for configuration, status checking, and data handling.
 *           Functions include configuring UART peripherals, checking status flags, and managing data buffers.
 *
 * @author  Nguyen Dang Nhu Tri
 * @version 1.0
 * @date    2024/07/05
 * @copyright Copyright (c) 2024 Nguyen Dang Nhu Tri.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "../Includes/DRIVER/DRIVER_UART.h"
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
 *@brief  Configure the UART peripheral
 *@param  UART_Config: Pointer to the UART configuration structure
 *@returns  None
 */
void DRIVER_UART_Config(UART_Config *UART_Config)
{
    if (NULL != UART_Config->UARTx)
    {
        HAL_UART_BDL_Baud_Rate_Modulo_Divisor(UART_Config->UARTx, UART_Config->BDL);
        HAL_UART_BDH_Baud_Rate_Modulo_Divisor(UART_Config->UARTx, UART_Config->BDH.SBR);
        HAL_UART_BDH_Stop_Bit_Number_Select(UART_Config->UARTx, UART_Config->BDH.SBNS);
        HAL_UART_C2_Transmitter_Enable(UART_Config->UARTx, UART_Config->C2.TE);
        HAL_UART_C2_Receiver_Interrupt_Enable_for_RDRF(UART_Config->UARTx, UART_Config->C2.RIE);
        HAL_UART_C2_Receiverr_Enable(UART_Config->UARTx, UART_Config->C2.RE);
    }
    else
    {
        /* UARTx pointer is NULL */
    }
}

/*
 *@brief  Check if the UART receive data register is full
 *@param  UARTx: Pointer to the UART peripheral
 *@returns  S1_RDRF_enum: Receive data register full flag status
 */
S1_RDRF_enum DRIVER_UART_S1_Receive_Data_Register_Full_Flag(UART_Type *UARTx)
{
    S1_RDRF_enum flagStatus = S1_RDRF_EMPTY;

    if (NULL != UARTx)
    {
        flagStatus = HAL_UART_S1_Receive_Data_Register_Full_Flag(UARTx);
    }
    else
    {
        /* UARTx pointer is NULL */
    }

    return flagStatus;
}

/*
 *@brief  Check if the UART transmission is complete
 *@param  UARTx: Pointer to the UART peripheral
 *@returns  S1_TC_enum: Transmission complete flag status
 */
S1_TC_enum DRIVER_UART_S1_Transmission_Complete_Flag(UART_Type *UARTx)
{
    S1_TC_enum flagStatus = S1_TC_ACTIVE;

    if (NULL != UARTx)
    {
        flagStatus = HAL_UART_S1_Transmission_Complete_Flag(UARTx);
    }
    else
    {
        /* UARTx pointer is NULL */
    }

    return flagStatus;
}

/*
 *@brief  Write data to the UART transmit data buffer
 *@param  UARTx: Pointer to the UART peripheral
 *@param  value: Data to be transmitted
 *@returns  None
 */
void DRIVER_UART_D_Write_transmit_data_buffer(UART_Type *UARTx, uint8_t value)
{
    if (NULL != UARTx)
    {
        HAL_UART_D_Write_transmit_data_buffer(UARTx, value);
    }
    else
    {
        /* UARTx pointer is NULL */
    }
}

/*
 *@brief  Read data from the UART receive data buffer
 *@param  UARTx: Pointer to the UART peripheral
 *@returns  uint8_t: Received data
 */
uint8_t DRIVER_UART_D_Read_receive_data_buffer(UART_Type *UARTx)
{
    uint8_t data = 0;

    if (NULL != UARTx)
    {
        data = HAL_UART_D_Read_receive_data_buffer(UARTx);
    }
    else
    {
        /* UARTx pointer is NULL */
    }

    return data;
}

/* EOF */
