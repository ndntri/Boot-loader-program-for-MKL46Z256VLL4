/**
 * @file HAL_SIM.c
 * @brief  HAL functions for the SIM module.
 * @details This file provides functions for controlling clock gating and selecting clock sources for various
 *          SIM peripherals. It includes enums, structs, and functions for configuring UART, Port modules,
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
#include "../Includes/HAL/HAL_SIM.h"
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
 *@brief  Controls the clock gate for UART0 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC4_UART0_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC4 = (SIM->SCGC4 & ~SIM_SCGC4_UART0_MASK) | SIM_SCGC4_UART0(state);
}

/*
 *@brief  Controls the clock gate for UART1 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC4_UART1_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC4 = (SIM->SCGC4 & ~SIM_SCGC4_UART1_MASK) | SIM_SCGC4_UART1(state);
}

/*
 *@brief  Controls the clock gate for UART2 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC4_UART2_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC4 = (SIM->SCGC4 & ~SIM_SCGC4_UART2_MASK) | SIM_SCGC4_UART2(state);
}

/*
 *@brief  Controls the clock gate for Port A module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC5_Port_A_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC5 = (SIM->SCGC5 & ~SIM_SCGC5_PORTA_MASK) | SIM_SCGC5_PORTA(state);
}

/*
 *@brief  Controls the clock gate for Port B module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC5_Port_B_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC5 = (SIM->SCGC5 & ~SIM_SCGC5_PORTB_MASK) | SIM_SCGC5_PORTB(state);
}

/*
 *@brief  Controls the clock gate for Port C module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC5_Port_C_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC5 = (SIM->SCGC5 & ~SIM_SCGC5_PORTC_MASK) | SIM_SCGC5_PORTC(state);
}

/*
 *@brief  Controls the clock gate for Port D module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC5_Port_D_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC5 = (SIM->SCGC5 & ~SIM_SCGC5_PORTD_MASK) | SIM_SCGC5_PORTD(state);
}

/*
 *@brief  Controls the clock gate for Port E module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC5_Port_E_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC5 = (SIM->SCGC5 & ~SIM_SCGC5_PORTE_MASK) | SIM_SCGC5_PORTE(state);
}

/*
 *@brief  Controls the clock gate for the flash memory module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_Flash_Memory_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC6 = (SIM->SCGC6 & ~SIM_SCGC6_FTF_MASK) | SIM_SCGC6_FTF(state);
}

/*
 *@brief  Controls the clock gate for the DMA Mux module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_DMA_Mux_Clock_Gate_Controll(CLOCK_STATE_enum state)
{
    SIM->SCGC6 = (SIM->SCGC6 & ~SIM_SCGC6_DMAMUX_MASK) | SIM_SCGC6_DMAMUX(state);
}

/*
 *@brief  Controls the clock gate for the I2S module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_I2S_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC6 = (SIM->SCGC6 & ~SIM_SCGC6_I2S_MASK) | SIM_SCGC6_I2S(state);
}

/*
 *@brief  Controls the clock gate for the PIT module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_PIT_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC6 = (SIM->SCGC6 & ~SIM_SCGC6_PIT_MASK) | SIM_SCGC6_PIT(state);
}

/*
 *@brief  Controls the clock gate for the TPM0 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_TPM0_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC6 = (SIM->SCGC6 & ~SIM_SCGC6_TPM0_MASK) | SIM_SCGC6_TPM0(state);
}

/*
 *@brief  Controls the clock gate for the TPM1 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_TPM1_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC6 = (SIM->SCGC6 & ~SIM_SCGC6_TPM1_MASK) | SIM_SCGC6_TPM1(state);
}

/*
 *@brief  Controls the clock gate for the TPM2 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_TPM2_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC6 = (SIM->SCGC6 & ~SIM_SCGC6_TPM2_MASK) | SIM_SCGC6_TPM2(state);
}

/*
 *@brief  Controls the clock gate for the ADC0 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_ADC0_Clock_Gate_Control(CLOCK_STATE_enum state)
{
    SIM->SCGC6 = (SIM->SCGC6 & ~SIM_SCGC6_ADC0_MASK) | SIM_SCGC6_ADC0(state);
}

/*
 *@brief  Selects the MCGPLLCLK or MCGFLLCLK clock for various peripheral clocking options.
 *@param   select  The clock source to select (MCGPLLCLK or MCGFLLCLK).
 *@returns None
 */
void HAL_SIM_SOPT2_PLL_or_FLL_clock_select(SOPT2_PLLFLLSEL_enum select)
{
    SIM->SOPT2 = (SIM->SOPT2 & ~SIM_SOPT2_PLLFLLSEL_MASK) | SIM_SOPT2_PLLFLLSEL(select);
}

/*
 *@brief  Selects the clock source for the UART0 transmit and receive clock.
 *@param   select  The clock source to select for UART0 (various options).
 *@returns None
 */
void HAL_SIM_SOPT2_UART0SRC_Clock_Source_Select(SOPT2_UART0SRC_enum select)
{
    SIM->SOPT2 = (SIM->SOPT2 & ~SIM_SOPT2_UART0SRC_MASK) | SIM_SOPT2_UART0SRC(select);
}

/* EOF */
