/**
 * @file DRIVER_SIM.c
 * @brief  Driver functions for the SIM module.
 * @details This file contains functions for configuring and managing clock gating and clock sources for various
 *          SIM peripherals based on user-defined settings. Functions include configuring UART, Port modules,
 *          Flash memory, DMA Mux, I2S, PIT, TPM, ADC0, and system options.
 *
 * @author  Nguyen Dang Nhu Tri
 * @version 1.0
 * @date    2024/07/05
 * @copyright Copyright (c) 2024 Nguyen Dang Nhu Tri.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "../Includes/DRIVER/DRIVER_SIM.h"
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
 *@brief  Configures SIM registers based on the provided configuration.
 *@param  SIM_Config  Pointer to a SIM_Config structure that contains the register to be configured and the settings.
 *@returns  None
 */
void DRIVER_SIM_Config(SIM_Config *SIM_Config)
{
    switch (SIM_Config->Declare_SIM_Register)
    {
    case SCGC4_UART_0:
    {
        HAL_SIM_SCGC4_UART0_Clock_Gate_Control(SIM_Config->Initialize_SCGC4.UART_0); /* Configure UART0 Clock Gate Control */
        break;
    }
    case SCGC4_UART_1:
    {
        HAL_SIM_SCGC4_UART1_Clock_Gate_Control(SIM_Config->Initialize_SCGC4.UART_1); /* Configure UART1 Clock Gate Control */
        break;
    }
    case SCGC4_UART_2:
    {
        HAL_SIM_SCGC4_UART2_Clock_Gate_Control(SIM_Config->Initialize_SCGC4.UART_2); /* Configure UART2 Clock Gate Control */
        break;
    }
    case SCGC5_PORTA:
    {
        HAL_SIM_SCGC5_Port_A_Clock_Gate_Control(SIM_Config->Initialize_SCGC5.PORT_A); /* Configure Port A Clock Gate Control */
        break;
    }
    case SCGC5_PORTB:
    {
        HAL_SIM_SCGC5_Port_B_Clock_Gate_Control(SIM_Config->Initialize_SCGC5.PORT_B); /* Configure Port B Clock Gate Control */
        break;
    }
    case SCGC5_PORTC:
    {
        HAL_SIM_SCGC5_Port_C_Clock_Gate_Control(SIM_Config->Initialize_SCGC5.PORT_C); /* Configure Port C Clock Gate Control */
        break;
    }
    case SCGC5_PORTD:
    {
        HAL_SIM_SCGC5_Port_D_Clock_Gate_Control(SIM_Config->Initialize_SCGC5.PORT_D); /* Configure Port D Clock Gate Control */
        break;
    }
    case SCGC5_PORTE:
    {
        HAL_SIM_SCGC5_Port_E_Clock_Gate_Control(SIM_Config->Initialize_SCGC5.PORT_E); /* Configure Port E Clock Gate Control */
        break;
    }
    case SCGC6_FTF:
    {
        HAL_SIM_SCGC6_Flash_Memory_Clock_Gate_Control(SIM_Config->Initialize_SCGC6.FTF); /* Configure Flash Memory Clock Gate Control */
        break;
    }
    case SCGC6_DMAMUX:
    {
        HAL_SIM_SCGC6_DMA_Mux_Clock_Gate_Controll(SIM_Config->Initialize_SCGC6.DMAMUX); /* Configure DMA Mux Clock Gate Control */
        break;
    }
    case SCGC6_I2S:
    {
        HAL_SIM_SCGC6_I2S_Clock_Gate_Control(SIM_Config->Initialize_SCGC6.I2S); /* Configure I2S Clock Gate Control */
        break;
    }
    case SCGC6_PIT_module:
    {
        HAL_SIM_SCGC6_PIT_Clock_Gate_Control(SIM_Config->Initialize_SCGC6.PIT_module); /* Configure PIT Clock Gate Control */
        break;
    }
    case SCGC6_TPM_0:
    {
        HAL_SIM_SCGC6_TPM0_Clock_Gate_Control(SIM_Config->Initialize_SCGC6.TPM_0); /* Configure TPM0 Clock Gate Control */
        break;
    }
    case SCGC6_TPM_1:
    {
        HAL_SIM_SCGC6_TPM1_Clock_Gate_Control(SIM_Config->Initialize_SCGC6.TPM_1); /* Configure TPM1 Clock Gate Control */
        break;
    }
    case SCGC6_TPM_2:
    {
        HAL_SIM_SCGC6_TPM2_Clock_Gate_Control(SIM_Config->Initialize_SCGC6.TPM_2); /* Configure TPM2 Clock Gate Control */
        break;
    }
    case SCGC6_ADC_0:
    {
        HAL_SIM_SCGC6_ADC0_Clock_Gate_Control(SIM_Config->Initialize_SCGC6.ADC_0); /* Configure ADC0 Clock Gate Control */
        break;
    }
    case SOPT2_PLLFLLSEL:
    {
        HAL_SIM_SOPT2_PLL_or_FLL_clock_select(SIM_Config->Initialize_SOPT2.PLLFLLSEL); /* Configure PLL/FLL Clock Selection */
        break;
    }
    case SOPT2_UART0SRC:
    {
        HAL_SIM_SOPT2_UART0SRC_Clock_Source_Select(SIM_Config->Initialize_SOPT2.UART0SRC); /* Configure UART0 Clock Source Selection */
        break;
    }
    default:
    {
        /* Do nothing if the register is not recognized */
        break;
    }
    }
}

/* EOF */
