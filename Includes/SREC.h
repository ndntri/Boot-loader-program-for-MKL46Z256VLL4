/**
 * @file SREC.h
 * @brief Header file for SREC handling functions and data structures.
 * @details This header file defines the data structures and function prototypes for handling
 *          Motorola S-records (SREC). It includes the `Record` structure which represents a parsed
 *          S-record and function declarations for operations related to SREC parsing and processing.
 *
 * @author  Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/19
 * @copyright Copyright (c) 2024 Nguyen Dang Nhu Tri.
 */

#ifndef INCLUDES_SREC_H_
#define INCLUDES_SREC_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define MAX_LINE_LENGTH_RECORD 80 /* Define a constant for maximum line length */

/*
 * @brief Represents a parsed Motorola S-record.
 * @details This structure holds the parsed information from a Motorola S-record, including:
 */
typedef struct
{
    uint32_t address;          /**< Address specified in the S-record */
    uint8_t data1[4];          /**< Data bytes from the first segment of the record */
    uint8_t data2[4];          /**< Data bytes from the second segment of the record */
    uint8_t data3[4];          /**< Data bytes from the third segment of the record */
    uint8_t data4[4];          /**< Data bytes from the fourth segment of the record */
    uint8_t byteCount_of_data; /**< Number of data bytes in the record */
    uint8_t priority;          /**< Priority value for managing the record */
} Record;

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*
 *@brief Converts two hex characters to a byte.
 *@param high The high hex character.
 *@param low The low hex character.
 *@returns The byte value.
 */
uint8_t hex_chars_to_byte(char high, char low);

/*
 *@brief Converts a hexadecimal character to its byte value.
 *@details This function takes a single hexadecimal character as input and returns its corresponding byte value.
 *         If the character is not a valid hexadecimal character, the function returns 0.
 *@param c The hexadecimal character to be converted.
 *@returns The byte value corresponding to the hexadecimal character.
 */
uint8_t hexCharToByte(char c);

/*
 *@brief Validates an SREC line record.
 *@param srec_line Pointer to the SREC line record.
 *@returns Byte count if valid; 0 if invalid.
 */
uint8_t Check_Line_Record(volatile char *srec_line);

/*
 *@brief Parses an SREC record and fills the Record structure.
 *@param record Pointer to the SREC record.
 *@param record_struct Pointer to the Record structure to be filled.
 *@param byteCount_in_record The byte count in the record.
 */
void record_parser(volatile char *record, Record *record_struct, uint8_t byteCount_of_data);

#endif /* INCLUDES_SREC_H_ */
