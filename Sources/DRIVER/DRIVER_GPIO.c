/**
 * @file DRIVER_GPIO.c
 * @brief GPIO Driver Implementation
 * @details This file implements the GPIO driver functions for configuring and controlling GPIO pins on the MKL46Z256VLL4 microcontroller.
 *          It provides higher-level functions that build on the HAL GPIO layer to manage pin configuration, state manipulation,
 *          and utility functions for GPIO operations.
 *          These functions abstract the lower-level HAL functions to provide a more intuitive and easy-to-use interface for GPIO operations.
 *          The driver ensures that all GPIO operations are performed safely and correctly.
 *
 * @author Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/05
 * @copyright Copyright (c) 2024 by Nguyen Dang Nhu Tri.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "../Includes/DRIVER/DRIVER_GPIO.h"
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
 *@brief Configures a GPIO pin with the specified settings.
 *@details Sets the data direction for the GPIO pin and initializes the pin to the specified state.
 *@param GPIO_Config Pointer to a GPIO_Config structure containing the configuration parameters.
 *@returns None
 */
void DRIVER_GPIO_Config(GPIO_Config *GPIO_Config)
{
	if (NULL != GPIO_Config->GPIOx && 0 <= GPIO_Config->Pin && 31 >= GPIO_Config->Pin)
	{
		HAL_GPIO_PDDR_Port_Data_Direction(GPIO_Config->GPIOx, GPIO_Config->Pin, GPIO_Config->PDDR);
		if (HIGH == GPIO_Config->Initial_State_of_Output_Pin)
		{
			HAL_GPIO_PSOR_Port_Set_Output(GPIO_Config->GPIOx, GPIO_Config->Pin, PSOR_PTSO_LOGIC_1); /* Set the pin to high state */
		}
		else if (LOW == GPIO_Config->Initial_State_of_Output_Pin)
		{
			HAL_GPIO_PCOR_Port_Clear_Output(GPIO_Config->GPIOx, GPIO_Config->Pin, PSOR_PTCO_LOGIC_0); /* Set the pin to low state */
		}
		else
		{
			/* Invalid state */
		}
	}
	else
	{
		/* Invalid GPIOx or Pin */
	}
}

/*
 *@brief Sets the output state of a GPIO pin.
 *@details Changes the output state of the specified GPIO pin to either high or low.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to configure.
 *@param PinState The desired state of the pin (HIGH or LOW).
 *@returns None
 */
void DRIVER_GPIO_Output_Pin_State(GPIO_Type *GPIOx, uint8_t Pin, GPIO_PIN_STATE PinState)
{
	if (NULL != GPIOx && 0 <= Pin && 31 >= Pin)
	{
		if (HIGH == PinState)
		{
			HAL_GPIO_PSOR_Port_Set_Output(GPIOx, Pin, PSOR_PTSO_LOGIC_1); /* Set the pin to high state */
		}
		else if (LOW == PinState)
		{
			HAL_GPIO_PCOR_Port_Clear_Output(GPIOx, Pin, PSOR_PTCO_LOGIC_0); /* Set the pin to low state */
		}
		else
		{
			/* Invalid pin state */
		}
	}
	else
	{
		/* Invalid GPIOx or Pin */
	}
}

/*
 *@brief Toggles the state of a GPIO pin.
 *@details Changes the output state of the specified GPIO pin from high to low or low to high.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to toggle.
 *@returns None
 */
void DRIVER_GPIO_PTOR_Toggle_Output(GPIO_Type *GPIOx, uint8_t Pin)
{
	if (NULL != GPIOx && 0 <= Pin && 31 >= Pin)
	{
		HAL_GPIO_PTOR_Toggle_Output(GPIOx, Pin); /* Toggle the state of the specified pin */
	}
	else
	{
		/* Invalid GPIOx or Pin */
	}
}

/*
 *@brief Reads the input state of a GPIO pin.
 *@details Retrieves the current state of the specified GPIO pin (either HIGH or LOW) based on the data input register.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to read.
 *@returns The current state of the pin (HIGH or LOW).
 */
GPIO_PIN_STATE DRIVER_GPIO_PDIR_Read_Input_Pin(GPIO_Type *GPIOx, uint8_t Pin)
{
	GPIO_PIN_STATE pinstatus = PDIR_PDI_LOGIC_0;

	if (NULL != GPIOx && 0 <= Pin && 31 >= Pin)
	{
		pinstatus = HAL_GPIO_PDIR_Data_Input(GPIOx, Pin); /* Read the state of the specified pin */
	}
	else
	{
		/* Invalid GPIOx or Pin */
	}

	return pinstatus; /* Return the state of the pin */
}

/*
 *@brief Reads the output state of a GPIO pin.
 *@details Retrieves the current state of the specified GPIO pin's output (either HIGH or LOW) based on the data output register.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to read.
 *@returns The current state of the pin (HIGH or LOW).
 */
GPIO_PIN_STATE DRIVER_GPIO_PDOR_Read_Output_Pin(GPIO_Type *GPIOx, uint8_t Pin)
{
	GPIO_PIN_STATE pin_status = PDOR_LOGIC_0;

	if (NULL != GPIOx && 0 <= Pin && 31 >= Pin)
	{
		pin_status = HAL_GPIO_PDOR_Read_Output_Pin(GPIOx, Pin); /* Read the state of the specified output pin */
	}
	else
	{
		/* Invalid GPIOx or Pin */
	}

	return pin_status; /* Return the state of the pin */
}

/* EOF */
