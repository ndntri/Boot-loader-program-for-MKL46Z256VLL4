/**
 * @file HAL_GPIO.c
 * @brief GPIO Hardware Abstraction Layer (HAL) Driver
 * @details This file provides functions for configuring and controlling General-Purpose Input/Output (GPIO) pins.
 *          It includes functions for setting pin direction, reading and writing pin states, toggling pins, and configuring pull-up/pull-down resistors.
 *          This layer abstracts the hardware details and provides a consistent API for GPIO operations.
 *
 * @author Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/05
 * @copyright Copyright (c) 2024 by Nguyen Dang Nhu Tri.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "../Includes/HAL/HAL_GPIO.h"
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
 *@brief Configures the data direction of a GPIO pin.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to configure.
 *@param Direction The desired data direction for the pin (input or output).
 *@returns None
 */
void HAL_GPIO_PDDR_Port_Data_Direction(GPIO_Type *GPIOx, uint8_t Pin, PDDR_PDD_enum Direction)
{
    if (PDDR_PDD_OUTPUT == Direction)
    {
        GPIOx->PDDR |= (1 << Pin); /* Set the pin as output */
    }
    else if (PDDR_PDD_INPUT == Direction)
    {
        GPIOx->PDDR &= ~(1 << Pin); /* Set the pin as input */
    }
    else
    {
        /* Do nothing */
    }
}

/*
 *@brief Sets the output state of a GPIO pin to high.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to configure.
 *@param PinState The desired pin state (not used in this function).
 *@returns None
 */
void HAL_GPIO_PSOR_Port_Set_Output(GPIO_Type *GPIOx, uint8_t Pin, PSOR_PTSO_enum PinState)
{
    GPIOx->PSOR |= (1 << Pin); /* Set the pin to high state */
}

/*
 *@brief Clears the output state of a GPIO pin to low.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to configure.
 *@param PinState The desired pin state (not used in this function).
 *@returns None
 */
void HAL_GPIO_PCOR_Port_Clear_Output(GPIO_Type *GPIOx, uint8_t Pin, PCOR_PTCO_enum PinState)
{
    GPIOx->PCOR |= (1 << Pin); /* Set the pin to low state */
}

/*
 *@brief Toggles the output state of a GPIO pin.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to toggle.
 *@returns None
 */
void HAL_GPIO_PTOR_Toggle_Output(GPIO_Type *GPIOx, uint8_t Pin)
{
    GPIOx->PTOR = (GPIOx->PTOR & ~GPIO_PTOR_PTTO_MASK) | GPIO_PTOR_PTTO(Pin);
}

/*
 *@brief Reads the data input state of a GPIO pin.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to read.
 *@returns The current state of the pin (logic 0 or logic 1).
 */
PDIR_PDI_enum HAL_GPIO_PDIR_Data_Input(GPIO_Type *GPIOx, uint8_t Pin)
{
    PDIR_PDI_enum bitstatus = PDIR_PDI_LOGIC_0;

    if ((GPIOx->PDIR >> Pin) & 1)
    {
        bitstatus = PDIR_PDI_LOGIC_1; /* The pin is in high state */
    }
    else
    {
        /* The pin is in low state */
    }

    return bitstatus; /* Return the state of the pin */
}

/*
 *@brief Reads the output state of a GPIO pin.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to read.
 *@returns The current output state of the pin (logic 0 or logic 1).
 */
PDOR_Output_Pin_State HAL_GPIO_PDOR_Read_Output_Pin(GPIO_Type *GPIOx, uint8_t Pin)
{
    PDOR_Output_Pin_State pin_status = PDOR_LOGIC_0;

    if (GPIOx->PDOR & (1 << Pin))
    {
        pin_status = PDOR_LOGIC_1; /* The pin is in high state */
    }
    else
    {
        /* The pin is in low state */
    }

    return pin_status; /* Return the state of the pin */
}

/* EOF */
