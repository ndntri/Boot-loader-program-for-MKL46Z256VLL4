/**
 * @file DRIVER_SIM.h
 * @brief  Header for the SIM module driver functions.
 * @details This file declares functions for managing clock gating and clock sources for SIM peripherals. It includes
 *          function prototypes for configuring UART, Port modules, Flash memory, DMA Mux, I2S, PIT, TPM, ADC0, and
 *          system options.
 *
 * @author  Nguyen Dang Nhu Tri
 * @version 1.0
 * @date    2024/07/05
 * @copyright Copyright (c) 2024 Nguyen Dang Nhu Tri.
 */

#ifndef INCLUDES_DRIVER_DRIVER_SIM_H_
#define INCLUDES_DRIVER_DRIVER_SIM_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
#include "../HAL/HAL_SIM.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*
 *@brief  Enumerates the available SIM register fields.
 *@details  Includes registers for clock gating and clock source selection.
 */
typedef enum SIM_Register
{
    NONE,

    /* SCGC4 Register */
    SCGC4_UART_0, /* SCGC4 Register for UART0 Clock Gate Control */
    SCGC4_UART_1, /* SCGC4 Register for UART1 Clock Gate Control */
    SCGC4_UART_2, /* SCGC4 Register for UART2 Clock Gate Control */

    /* SCGC5 Register */
    SCGC5_PORTA, /* SCGC5 Register for Port A Clock Gate Control */
    SCGC5_PORTB, /* SCGC5 Register for Port B Clock Gate Control */
    SCGC5_PORTC, /* SCGC5 Register for Port C Clock Gate Control */
    SCGC5_PORTD, /* SCGC5 Register for Port D Clock Gate Control */
    SCGC5_PORTE, /* SCGC5 Register for Port E Clock Gate Control */

    /* SCGC6 Register */
    SCGC6_FTF,        /* SCGC6 Register for Flash Memory Clock Gate Control */
    SCGC6_DMAMUX,     /* SCGC6 Register for DMA Mux Clock Gate Control */
    SCGC6_I2S,        /* SCGC6 Register for I2S Clock Gate Control */
    SCGC6_PIT_module, /* SCGC6 Register for PIT Clock Gate Control */
    SCGC6_TPM_0,      /* SCGC6 Register for TPM0 Clock Gate Control */
    SCGC6_TPM_1,      /* SCGC6 Register for TPM1 Clock Gate Control */
    SCGC6_TPM_2,      /* SCGC6 Register for TPM2 Clock Gate Control */
    SCGC6_ADC_0,      /* SCGC6 Register for ADC0 Clock Gate Control */

    /* SOPT2 Register */
    SOPT2_PLLFLLSEL, /* SOPT2 Register for PLL/FLL Clock Selection */
    SOPT2_UART0SRC   /* SOPT2 Register for UART0 Clock Source Selection */
} SIM_Register;

/*
 *@brief  Defines the fields for SCGC4 System Clock Gating Control Register.
 *@details  Includes fields for UART0, UART1, and UART2 clock gating.
 */
typedef struct SIM_System_Clock_Gating_Control_Register_4
{
    CLOCK_STATE_enum UART_0; /* UART0 Clock Gate Control */
    CLOCK_STATE_enum UART_1; /* UART1 Clock Gate Control */
    CLOCK_STATE_enum UART_2; /* UART2 Clock Gate Control */
} SIM_SCGC4_field;

/*
 *@brief  Defines the fields for SCGC5 System Clock Gating Control Register.
 *@details  Includes fields for Port A to Port E clock gating.
 */
typedef struct SIM_SCGC5_System_Clock_Gating_Control_Register_5
{
    CLOCK_STATE_enum PORT_A; /* Port A Clock Gate Control */
    CLOCK_STATE_enum PORT_B; /* Port B Clock Gate Control */
    CLOCK_STATE_enum PORT_C; /* Port C Clock Gate Control */
    CLOCK_STATE_enum PORT_D; /* Port D Clock Gate Control */
    CLOCK_STATE_enum PORT_E; /* Port E Clock Gate Control */
} SIM_SCGC5_field;
/*
 *@brief  Defines the fields for SCGC6 System Clock Gating Control Register.
 *@details  Includes fields for Flash Memory, DMA Mux, I2S, PIT, TPM0, TPM1, TPM2, and ADC0 clock gating.
 */
typedef struct SIM_SCGC6_System_Clock_Gating_Control_Register_6
{
    CLOCK_STATE_enum FTF;        /* Flash Memory Clock Gate Control */
    CLOCK_STATE_enum DMAMUX;     /* DMA Mux Clock Gate Control */
    CLOCK_STATE_enum I2S;        /* I2S Clock Gate Control */
    CLOCK_STATE_enum PIT_module; /* PIT Clock Gate Control */
    CLOCK_STATE_enum TPM_0;      /* TPM0 Clock Gate Control */
    CLOCK_STATE_enum TPM_1;      /* TPM1 Clock Gate Control */
    CLOCK_STATE_enum TPM_2;      /* TPM2 Clock Gate Control */
    CLOCK_STATE_enum ADC_0;      /* ADC0 Clock Gate Control */
} SIM_SCGC6_field;

/*
 *@brief  Defines the fields for SOPT2 System Options Register 2.
 *@details  Includes fields for PLL/FLL clock selection and UART0 clock source selection.
 */
typedef struct SIM_SOPT2_System_Options_Register_2
{
    SOPT2_PLLFLLSEL_enum PLLFLLSEL; /* PLL/FLL Clock Selection */
    SOPT2_UART0SRC_enum UART0SRC;   /* UART0 Clock Source Selection */
} SIM_SOPT2_field;

/*
 *@brief  Configures the SIM registers and their fields.
 *@details  Includes registers for SCGC4, SCGC5, SCGC6, and SOPT2 with their respective fields.
 */
typedef struct SIM_Config
{
    SIM_Register Declare_SIM_Register; /* Register Selection */
    SIM_SCGC4_field Initialize_SCGC4;  /* SCGC4 System Clock Gating Control Register */
    SIM_SCGC5_field Initialize_SCGC5;  /* SCGC5 System Clock Gating Control Register */
    SIM_SCGC6_field Initialize_SCGC6;  /* SCGC6 System Clock Gating Control Register */
    SIM_SOPT2_field Initialize_SOPT2;  /* SOPT2 System Options Register */
} SIM_Config;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*
 *@brief  Configures SIM registers based on the provided configuration.
 *@param  SIM_Config  Pointer to a SIM_Config structure that contains the register to be configured and the settings.
 *@returns  None
 */
void DRIVER_SIM_Config(SIM_Config *SIM_Config);

#endif /* INCLUDES_DRIVER_DRIVER_SIM_H_ */
