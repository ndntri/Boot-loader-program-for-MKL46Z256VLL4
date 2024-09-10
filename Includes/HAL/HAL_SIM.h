
/**
 * @file HAL_SIM.h
 * @brief  Header file for HAL functions for the SIM module.
 * @details This file provides declarations for functions, enums, and structs used for controlling clock gating and
 *          selecting clock sources for various SIM peripherals. It includes function prototypes for configuring UART,
 *          Port modules, Flash memory, DMA Mux, I2S, PIT, TPM, ADC0, and system options.
 *
 * @author  Nguyen Dang Nhu Tri
 * @version 1.0
 * @date    2024/07/05
 * @copyright Copyright (c) 2024 Nguyen Dang Nhu Tri.
 */

#ifndef INCLUDES_HAL_HAL_SIM_H_
#define INCLUDES_HAL_HAL_SIM_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*
 *@brief  Selects the source clock for various peripheral options.
 *@details  Options are MCGFLLCLK clock or MCGPLLCLK/2 clock.
 */
typedef enum SIM_SOPT2_UART0_PLL_FLL_clock_select
{
	SOPT2_PLLFLLSEL_MCGFLLCLK = 0,		/* MCGFLLCLK clock */
	SOPT2_PLLFLLSEL_MCGPLLCLK_DIV2 = 1, /* MCGPLLCLK clock with fixed divide by two */
} SOPT2_PLLFLLSEL_enum;

/*
 *@brief  Selects the clock source for UART0.
 *@details  Options include disabled, FLL/PLL, OSCERCLK, and MCGIRCLK clocks.
 */
typedef enum SIM_SOPT2_UART0_Clock_Source_Select
{
	SOPT2_UART0SRC_DISABLED = 0b00, /* Clock disabled */
	SOPT2_UART0SRC_FLL_PLL = 0b01,	/* MCGFLLCLK clock or MCGPLLCLK/2 clock */
	SOPT2_UART0SRC_OSCERCLK = 0b10, /* OSCERCLK clock */
	SOPT2_UART0SRC_MCGIRCLK = 0b11, /* MCGIRCLK clock */
} SOPT2_UART0SRC_enum;

/*
 *@brief  Defines the state of a clock (enabled or disabled).
 *@details  Options are to enable or disable the clock.
 */
typedef enum CLOCK_STATE_enum
{
	CLOCK_STATE_DISABLE = 0, /* Clock disabled */
	CLOCK_STATE_ENABLE = 1,	 /* Clock enabled */
} CLOCK_STATE_enum;

/*
 *@brief  Defines the state of access (enabled or disabled).
 *@details  Options are to enable or disable access.
 */
typedef enum ACCESS_STATE_enum
{
	ACCESS_STATE_DISABLE = 0, /* Access disabled */
	ACCESS_STATE_ENABLE = 1,  /* Access enabled */
} ACCESS_STATE_enum;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*
 *@brief  Controls the clock gate for UART0 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC4_UART0_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for UART1 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC4_UART1_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for UART2 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC4_UART2_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for Port A module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC5_Port_A_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for Port B module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC5_Port_B_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for Port C module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC5_Port_C_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for Port D module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC5_Port_D_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for Port E module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC5_Port_E_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for the flash memory module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_Flash_Memory_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for the DMA Mux module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_DMA_Mux_Clock_Gate_Controll(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for the I2S module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_I2S_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for the PIT module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_PIT_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for the TPM0 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_TPM0_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for the TPM1 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_TPM1_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for the TPM2 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_TPM2_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Controls the clock gate for the ADC0 module.
 *@param   state  The desired clock state (ENABLE or DISABLE).
 *@returns None
 */
void HAL_SIM_SCGC6_ADC0_Clock_Gate_Control(CLOCK_STATE_enum state);

/*
 *@brief  Selects the MCGPLLCLK or MCGFLLCLK clock for various peripheral clocking options.
 *@param   select  The clock source to select (MCGPLLCLK or MCGFLLCLK).
 *@returns None
 */
void HAL_SIM_SOPT2_PLL_or_FLL_clock_select(SOPT2_PLLFLLSEL_enum select);

/*
 *@brief  Selects the clock source for the UART0 transmit and receive clock.
 *@param   select  The clock source to select for UART0 (various options).
 *@returns None
 */
void HAL_SIM_SOPT2_UART0SRC_Clock_Source_Select(SOPT2_UART0SRC_enum select);

#endif /* INCLUDES_HAL_HAL_SIM_H_ */
