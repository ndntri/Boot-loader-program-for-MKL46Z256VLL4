/**
 * @file HAL_GPIO.h
 * @brief GPIO Hardware Abstraction Layer (HAL) Header File
 * @details This header file defines the public API for the GPIO Hardware Abstraction Layer (HAL) driver.
 *          It includes function declarations for GPIO pin configuration, state manipulation, and utility functions.
 *          This file provides the interface for GPIO operations such as setting pin direction, reading/writing pin states,
 *          toggling pin states, and configuring pull-up/pull-down resistors.
 *          It is designed to abstract hardware-specific details and provide a consistent API for GPIO operations.
 * @author Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/05
 * @copyright Copyright (c) 2024 by Nguyen Dang Nhu Tri.
 */

#ifndef INCLUDES_HAL_HAL_GPIO_H_
#define INCLUDES_HAL_HAL_GPIO_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*
 *@brief Enumeration for GPIO Port Data Direction Register settings.
 *@details Defines the direction of GPIO pins for general-purpose input or output.
 */
typedef enum GPIO_PDDR_PDD_Port_Data_Direction_Register
{
    PDDR_PDD_INPUT, /* Pin is configured as general-purpose input, for the GPIO function. */
    PDDR_PDD_OUTPUT /* Pin is configured as general-purpose output, for the GPIO function. */
} PDDR_PDD_enum;

/*
 *@brief Enumeration for GPIO Port Set Output register settings.
 *@details Defines the actions for setting the output state of a GPIO pin.
 */
typedef enum GPIO_PSOR_PTSO_Port_Set_Output
{
    PSOR_PTSO_NOT_CHANGE, /* Corresponding bit in PDORn does not change. */
    PSOR_PTSO_LOGIC_1,    /* Corresponding bit in PDORn is set to logic 1. */
} PSOR_PTSO_enum;

/*
 *@brief Enumeration for GPIO Port Clear Output register settings.
 *@details Defines the actions for clearing the output state of a GPIO pin.
 */
typedef enum GPIO_PSOR_PTCO_Port_Clear_Output
{
    PSOR_PTCO_NOT_CHANGE, /* Corresponding bit in PDORn does not change. */
    PSOR_PTCO_LOGIC_0,    /* Corresponding bit in PDORn is cleared to logic 0. */
} PCOR_PTCO_enum;

/*
 *@brief Enumeration for GPIO Port Data Input register settings.
 *@details Defines the possible logic levels for a GPIO pin's data input.
 */
typedef enum GPIO_PDIR_PDI_Port_Data_Input
{
    PDIR_PDI_LOGIC_0, /* Pin logic level is logic 0, or is not configured for use by digital function. */
    PDIR_PDI_LOGIC_1, /* Pin logic level is logic 1. */
} PDIR_PDI_enum;

/*
 *@brief Enumeration for GPIO Port Data Output register settings.
 *@details Defines the possible output states for a GPIO pin.
 */
typedef enum GPIO_PDOR_Output_Pin_State
{
    PDOR_LOGIC_0, /* Pin logic level is logic 0. */
    PDOR_LOGIC_1, /* Pin logic level is logic 1. */
} PDOR_Output_Pin_State;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*
 *@brief Configures the data direction of a GPIO pin.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to configure.
 *@param Direction The desired data direction for the pin (input or output).
 *@returns None
 */
void HAL_GPIO_PDDR_Port_Data_Direction(GPIO_Type *GPIOx, uint8_t Pin, PDDR_PDD_enum Direction);

/*
 *@brief Sets the output state of a GPIO pin to high.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to configure.
 *@param PinState The desired pin state (not used in this function).
 *@returns None
 */
void HAL_GPIO_PSOR_Port_Set_Output(GPIO_Type *GPIOx, uint8_t Pin, PSOR_PTSO_enum PinState);

/*
 *@brief Clears the output state of a GPIO pin to low.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to configure.
 *@param PinState The desired pin state (not used in this function).
 *@returns None
 */
void HAL_GPIO_PCOR_Port_Clear_Output(GPIO_Type *GPIOx, uint8_t Pin, PCOR_PTCO_enum PinState);

/*
 *@brief Toggles the output state of a GPIO pin.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to toggle.
 *@returns None
 */
void HAL_GPIO_PTOR_Toggle_Output(GPIO_Type *GPIOx, uint8_t Pin);

/*
 *@brief Reads the data input state of a GPIO pin.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to read.
 *@returns The current state of the pin (logic 0 or logic 1).
 */
PDIR_PDI_enum HAL_GPIO_PDIR_Data_Input(GPIO_Type *GPIOx, uint8_t Pin);

/*
 *@brief Reads the output state of a GPIO pin.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to read.
 *@returns The current output state of the pin (logic 0 or logic 1).
 */
PDOR_Output_Pin_State HAL_GPIO_PDOR_Read_Output_Pin(GPIO_Type *GPIOx, uint8_t Pin);

#endif /* INCLUDES_HAL_HAL_GPIO_H_ */
