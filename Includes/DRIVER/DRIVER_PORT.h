/**
 * @file DRIVER_PORT.h
 * @brief Header file for PORT driver functions.
 * @details This header file defines the driver functions for configuring and managing
 *          PORT peripherals on the microcontroller. It includes functions for initializing
 *          PORT configurations, clearing interrupt status flags, and reading interrupt
 *          status flags. It utilizes `PORT_Config` structures and HAL functions for
 *          handling various PORT operations.
 *
 * @author Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/05
 * @copyright Copyright (c) 2024
 */

#ifndef INCLUDES_DRIVER_DRIVER_PORT_H_
#define INCLUDES_DRIVER_DRIVER_PORT_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
#include "../HAL/HAL_PORT.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*
 *@brief Structure for configuring the Pin Control Register fields.
 *@details Contains settings for pull select, pull enable, pin mux control, and interrupt configuration.
 */
typedef struct PORT_PCR_Pin_Control_Register
{
    PCR_PS_enum PS;     /* Pull Select: Configures pull-up or pull-down resistor */
    PCR_PE_enum PE;     /* Pull Enable: Enables or disables the pull-up or pull-down resistor */
    PCR_MUX_enum MUX;   /* Pin Mux Control: Selects the pin function */
    PCR_IRQC_enum IRQC; /* Interrupt Configuration: Configures interrupt or DMA request settings */
} PORT_PCR_field;

/*
 *@brief Structure for configuring a PORT and its pin.
 *@details Includes the PORT base address, pin number, pin control settings, and interrupt status flag.
 */
typedef struct PORT_Config
{
    PORT_Type *PORTx;   /* Pointer to the PORT peripheral base address */
    uint8_t Pin;        /* Pin number to configure */
    PORT_PCR_field PCR; /* Pin Control Register settings */
    ISFR_ISF_enum ISFR; /* Interrupt Status Flag Register status */
} PORT_Config;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*
 *@brief Configures the PORT and its pin based on the provided configuration structure.
 *@param PORT_Config Pointer to a PORT_Config structure that contains the settings for the PORT and pin.
 *@returns None
 */
void DRIVER_PORT_Config(PORT_Config *PORT_Config);

/*
 *@brief Clears the interrupt status flag for a specified pin.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number whose interrupt status flag is to be cleared.
 *@returns None
 */
void DRIVER_PORT_PCR_Clear_Interrupt_Status_Flag(PORT_Type *PORTx, uint8_t Pin);

/*
 *@brief Reads the interrupt status flag for a specified pin.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number to read the interrupt status flag.
 *@returns Status of the interrupt flag (detected or not detected).
 */
ISFR_ISF_enum DRIVER_PORT_ISFR_Read_Interrupt_Status_Flag(PORT_Type *PORTx, uint8_t Pin);

#endif /* INCLUDES_DRIVER_DRIVER_PORT_H_ */
