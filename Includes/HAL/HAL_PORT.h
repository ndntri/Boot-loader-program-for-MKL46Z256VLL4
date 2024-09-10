/**
 * @file HAL_PORT.h
 * @brief Header file for the PORT HAL (Hardware Abstraction Layer) functions.
 * @details This header file defines the functions, enums, and structures for configuring
 *          PORT peripherals on the microcontroller. It includes functions for pin muxing,
 *          configuring pull-up/pull-down resistors, setting interrupt configurations, and
 *          handling interrupt status flags. It also defines structures for representing
 *          PORT configurations and interrupt status.
 *
 * @author Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/05
 * @copyright Copyright (c) 2024
 */

#ifndef INCLUDES_HAL_HAL_PORT_H_
#define INCLUDES_HAL_HAL_PORT_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*
 *@brief Specifies the pin mux control options.
 *@details Options include selecting analog, GPIO, or alternate functions.
 */
typedef enum PORT_PCR_MUX_Pin_Mux_Control
{
    PCR_IRQC_MUX_ANALOG, /* Analog function is selected */
    PCR_IRQC_MUX_GPIO,   /* General Purpose Input/Output function is selected */
    PCR_IRQC_MUX_ALT2,   /* Alternate function 2 is selected */
    PCR_IRQC_MUX_ALT3,   /* Alternate function 3 is selected */
    PCR_IRQC_MUX_ALT4,   /* Alternate function 4 is selected */
    PCR_IRQC_MUX_ALT5,   /* Alternate function 5 is selected */
    PCR_IRQC_MUX_ALT6,   /* Alternate function 6 is selected */
    PCR_IRQC_MUX_ALT7    /* Alternate function 7 is selected */
} PCR_MUX_enum;

/*
 *@brief Specifies the pull-up or pull-down resistor options.
 *@details Selects between pull-down resistor or pull-up resistor.
 */
typedef enum PORT_PCR_PS_Pull_Select
{
    PCR_PS_PULL_DOWN = 0, /* Pull-down resistor is selected */
    PCR_PS_PULL_UP = 1    /* Pull-up resistor is selected */
} PCR_PS_enum;

/*
 *@brief Specifies whether the pull-up or pull-down resistor is enabled.
 *@details Enables or disables the pull-up or pull-down resistor.
 */
typedef enum PORT_PCR_PE_Pull_Enable
{
    PCR_PE_PULL_DISABLE = 0, /* Pull-up or pull-down resistor is disabled */
    PCR_PE_PULL_ENABLE = 1   /* Pull-up or pull-down resistor is enabled */
} PCR_PE_enum;

/*
 *@brief Specifies the interrupt or DMA request configuration.
 *@details Options include selecting different edges for DMA requests or interrupts, and levels for interrupt generation.
 */
typedef enum PORT_PCR_IRQC_Interrupt_Configuration
{
    PCR_IRQC_INTERRUPT_DMA_DISABLED = 0b0000u, /* No interrupt or DMA request is generated */
    PCR_IRQC_DMA_RISING_EDGE = 0b0001u,        /* DMA request on rising edge */
    PCR_IRQC_DMA_FALLING_EDGE = 0b0010u,       /* DMA request on falling edge */
    PCR_IRQC_DMA_EITHER_EDGE = 0b0011u,        /* DMA request on either edge */
    PCR_IRQC_INTERRUPT_LOGIC_ZERO = 0b1000u,   /* Interrupt when logic zero */
    PCR_IRQC_INTERRUPT_RISING_EDGE = 0b1001u,  /* Interrupt on rising edge */
    PCR_IRQC_INTERRUPT_FALLING_EDGE = 0b1010u, /* Interrupt on falling edge */
    PCR_IRQC_INTERRUPT_EITHER_EDGE = 0b1011u,  /* Interrupt on either edge */
    PCR_IRQC_INTERRUPT_LOGIC_ONE = 0b1100u     /* Interrupt when logic one */
} PCR_IRQC_enum;

/*
 *@brief Specifies the interrupt status flag.
 *@details Indicates whether an interrupt has been detected or not.
 */
typedef enum PORT_ISFR_Interrupt_Status_Flag_Register
{
    ISFR_ISF_NOT_DETECTED = 0, /* Interrupt was not detected */
    ISFR_ISF_DETECTED = 1      /* Interrupt was detected */
} ISFR_ISF_enum;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*
 *@brief Configures the pin mux control settings.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number to configure.
 *@param Mux_Type MUX type to be set (e.g., analog, GPIO, alternate functions).
 *@returns None
 */
void HAL_PORT_PCR_Pin_Mux_Control(PORT_Type *PORTx, uint8_t Pin, PCR_MUX_enum Mux_Type);

/*
 *@brief Configures the pull-up or pull-down resistor enable state.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number to configure.
 *@param Pull_State Pull-up or pull-down resistor enable state (enable or disable).
 *@returns None
 */
void HAL_PORT_PCR_Pull_Enable(PORT_Type *PORTx, uint8_t Pin, PCR_PE_enum Pull_State);

/*
 *@brief Selects the pull-up or pull-down resistor type.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number to configure.
 *@param Pull_Select Pull-up or pull-down resistor selection.
 *@returns None
 */
void HAL_PORT_PCR_Pull_Select(PORT_Type *PORTx, uint8_t Pin, PCR_PS_enum Pull_Select);

/*
 *@brief Configures the interrupt or DMA request settings for a pin.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number to configure.
 *@param Config Interrupt or DMA request configuration.
 *@returns None
 */
void HAL_PORT_PCR_Interrupt_Configuration(PORT_Type *PORTx, uint8_t Pin, PCR_IRQC_enum Config);

/*
 *@brief Clears the interrupt status flag for a pin.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number whose interrupt status flag is to be cleared.
 *@returns None
 */
void HAL_PORT_PCR_Clear_Interrupt_Status_Flag(PORT_Type *PORTx, uint8_t Pin);

/*
 *@brief Reads the interrupt status flag for a pin.
 *@param PORTx Pointer to the PORT peripheral base address.
 *@param Pin Pin number to read the interrupt status flag.
 *@returns Status of the interrupt flag (detected or not detected).
 */
ISFR_ISF_enum HAL_PORT_ISFR_Read_Interrupt_Status_Flag(PORT_Type *PORTx, uint8_t Pin);

#endif /* INCLUDES_HAL_HAL_PORT_H_ */
