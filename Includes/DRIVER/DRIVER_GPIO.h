/**
 * @file DRIVER_GPIO.h
 * @brief GPIO Driver Header File
 * @details This file contains the definitions and function prototypes for the GPIO driver layer.
 *          It provides an interface for configuring and controlling GPIO pins on the MKL46Z256VLL4 microcontroller.
 *          The header file defines data structures, enumerations, and function prototypes used by the GPIO driver.
 *
 * @author Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/05
 * @copyright Copyright (c) 2024 by Nguyen Dang Nhu Tri.
 */

#ifndef INCLUDES_DRIVER_DRIVER_GPIO_H_
#define INCLUDES_DRIVER_DRIVER_GPIO_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
#include "../HAL/HAL_GPIO.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*
 *@brief Enumeration for GPIO pin states.
 *@details Defines the possible states of a GPIO pin (low or high).
 */
typedef enum GPIO_PIN_STATE
{
    LOW,  /* The GPIO pin is set to low state */
    HIGH, /* The GPIO pin is set to high state */
} GPIO_PIN_STATE;

/*
 *@brief Structure for configuring GPIO pin settings.
 *@details Contains configuration parameters for initializing a GPIO pin.
 */
typedef struct GPIO_Config
{
    GPIO_Type *GPIOx;                           /* Pointer to the GPIO base address */
    uint8_t Pin;                                /* The pin number to configure */
    PDDR_PDD_enum PDDR;                         /* Port Data Direction Register setting (input or output) */
    GPIO_PIN_STATE Initial_State_of_Output_Pin; /* Initial state of the output pin (low or high) */
} GPIO_Config;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*
 *@brief Configures a GPIO pin with the specified settings.
 *@details Sets the data direction for the GPIO pin and initializes the pin to the specified state.
 *@param GPIO_Config Pointer to a GPIO_Config structure containing the configuration parameters.
 *@returns None
 */
void DRIVER_GPIO_Config(GPIO_Config *GPIO_Config);

/*
 *@brief Sets the output state of a GPIO pin.
 *@details Changes the output state of the specified GPIO pin to either high or low.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to configure.
 *@param PinState The desired state of the pin (HIGH or LOW).
 *@returns None
 */
void DRIVER_GPIO_Output_Pin_State(GPIO_Type *GPIOx, uint8_t Pin, GPIO_PIN_STATE PinState);

/*
 *@brief Toggles the state of a GPIO pin.
 *@details Changes the output state of the specified GPIO pin from high to low or low to high.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to toggle.
 *@returns None
 */
void DRIVER_GPIO_PTOR_Toggle_Output(GPIO_Type *GPIOx, uint8_t Pin);

/*
 *@brief Reads the input state of a GPIO pin.
 *@details Retrieves the current state of the specified GPIO pin (either HIGH or LOW) based on the data input register.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to read.
 *@returns The current state of the pin (HIGH or LOW).
 */
GPIO_PIN_STATE DRIVER_GPIO_PDIR_Read_Input_Pin(GPIO_Type *GPIOx, uint8_t Pin);

/*
 *@brief Reads the output state of a GPIO pin.
 *@details Retrieves the current state of the specified GPIO pin's output (either HIGH or LOW) based on the data output register.
 *@param GPIOx Pointer to the GPIO base address.
 *@param Pin The pin number to read.
 *@returns The current state of the pin (HIGH or LOW).
 */
GPIO_PIN_STATE DRIVER_GPIO_PDOR_Read_Output_Pin(GPIO_Type *GPIOx, uint8_t Pin);
#endif /* INCLUDES_DRIVER_DRIVER_GPIO_H_ */
