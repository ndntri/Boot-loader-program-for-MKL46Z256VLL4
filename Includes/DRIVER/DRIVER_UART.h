/**
 * @file DRIVER_UART.h
 * @brief  UART Driver Header File
 * @details  Contains function prototypes for UART configuration, status checking, and data handling.
 *           Defines functions for UART initialization, checking flags, and managing data buffers.
 *
 * @author  Nguyen Dang Nhu Tri
 * @version 1.0
 * @date    2024/07/05
 * @copyright Copyright (c) 2024 Nguyen Dang Nhu Tri.
 */

#ifndef INCLUDES_DRIVER_DRIVER_UART_H_
#define INCLUDES_DRIVER_DRIVER_UART_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
#include "../HAL/HAL_UART.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*
 *@brief  UART Baud Rate Register High structure
 *@details  This structure defines the fields for the UART BDH register.
 */
typedef struct UART_Baud_Rate_Register_High
{
    uint8_t SBR;        /* Baud Rate Modulo Divisor */
    BDH_SBNS_enum SBNS; /* Stop Bit Number Select */
                        /* Reserved */
} UART_BDH_field;

/*
 *@brief  UART Control Register 2 structure
 *@details  This structure defines the fields for the UART C2 register.
 */
typedef struct UART_Control_Register_2
{
    C2_RE_enum RE;   /* Receiver Enable */
    C2_TE_enum TE;   /* Transmitter Enable */
    C2_RIE_enum RIE; /* Receiver interrupt Enable*/
} UART_C2_field;

/*
 *@brief  UART Status Register 1 structure
 *@details  This structure defines the fields for the UART S1 register.
 */
typedef struct UART_Status_Register_1
{
    S1_RDRF_enum RDRF; /* Receive Data Register Full Flag */
    S1_TC_enum TC;     /* Transmission Complete Flag */
                       /* Reserved */
} UART_S1_field;

/*
 *@brief  UART Configuration structure
 *@details  This structure defines the configuration settings for the UART.
 */
typedef struct UART_Configure
{
    UART_Type *UARTx;   /* Pointer to the UART peripheral */
    uint8_t BDL;        /* UART Baud Rate Register Low */
    UART_BDH_field BDH; /* UART Baud Rate Register High */
    UART_C2_field C2;   /* UART Control Register 2 */
} UART_Config;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*
 *@brief  Configure the UART peripheral
 *@param  UART_Config: Pointer to the UART configuration structure
 *@returns  None
 */
void DRIVER_UART_Config(UART_Config *UART_Config);

/*
 *@brief  Check if the UART receive data register is full
 *@param  UARTx: Pointer to the UART peripheral
 *@returns  S1_RDRF_enum: Receive data register full flag status
 */
S1_RDRF_enum DRIVER_UART_S1_Receive_Data_Register_Full_Flag(UART_Type *UARTx);

/*
 *@brief  Check if the UART transmission is complete
 *@param  UARTx: Pointer to the UART peripheral
 *@returns  S1_TC_enum: Transmission complete flag status
 */
S1_TC_enum DRIVER_UART_S1_Transmission_Complete_Flag(UART_Type *UARTx);

/*
 *@brief  Write data to the UART transmit data buffer
 *@param  UARTx: Pointer to the UART peripheral
 *@param  value: Data to be transmitted
 *@returns  None
 */
void DRIVER_UART_D_Write_transmit_data_buffer(UART_Type *UARTx, uint8_t value);

/*
 *@brief  Read data from the UART receive data buffer
 *@param  UARTx: Pointer to the UART peripheral
 *@returns  uint8_t: Received data
 */
uint8_t DRIVER_UART_D_Read_receive_data_buffer(UART_Type *UARTx);

#endif /* INCLUDES_DRIVER_DRIVER_UART_H_ */
