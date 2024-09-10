/**
 * @file BOOT.h
 * @brief Header file for the bootloader functions.
 * @details This header file contains the declaration for the `JumpToApplication` function. It provides
 *          the necessary interface for transitioning control from the bootloader to the main application.
 *          This file ensures that the bootloader can properly execute the application code located at a predefined address.
 * @author  Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/19
 * @copyright Copyright (c) 2024 Nguyen Dang Nhu Tri.
 */

#ifndef INCLUDES_BOOT_H_
#define INCLUDES_BOOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define APPLICATION_ADDRESS 0x0000A000 /* APPLICATION ADDRESS */
/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*
 *@brief Jumps to the application code.
 *@details This function performs a jump to the application code located at `APPLICATION_ADDRESS`.
 *         It sets the Main Stack Pointer (MSP) to the value located at the start of the application code,
 *         then retrieves the application's reset handler address and calls it to start execution.
 */
void JumpToApplication(void);

#endif /* INCLUDES_BOOT_H_ */
