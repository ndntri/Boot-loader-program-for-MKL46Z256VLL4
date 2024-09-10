/**
 * @file BOOT.c
 * @brief Bootloader function to jump to the main application.
 * @details This file contains the `JumpToApplication` function which is used to transition control
 *          from the bootloader to the main application. The function sets up the stack pointer and
 *          starts execution of the application code located at a predefined address.
 *
 * @author  Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/19
 * @copyright Copyright (c) 2024 Nguyen Dang Nhu Tri.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "BOOT.h"
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
 *@brief Jumps to the application code.
 *@details This function performs a jump to the application code located at `APPLICATION_ADDRESS`.
 *         It sets the Main Stack Pointer (MSP) to the value located at the start of the application code,
 *         then retrieves the application's reset handler address and calls it to start execution.
 */
void JumpToApplication(void)
{
    /* Set the Main Stack Pointer (MSP) to the application's stack pointer value */
    uint32_t app_msp = *(volatile uint32_t *)APPLICATION_ADDRESS;
    __set_MSP(app_msp);

    /* Get the application's reset handler address */
    uint32_t app_reset_handler = *(volatile uint32_t *)(APPLICATION_ADDRESS + 4);
    void (*reset_handler)(void) = (void (*)(void))app_reset_handler;

    /* Jump to the application's reset handler */
    reset_handler();
}
