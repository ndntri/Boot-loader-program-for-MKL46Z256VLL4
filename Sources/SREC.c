/**
 * @file  SREC.c
 * @brief Functions for handling Motorola S-records.
 * @details This file contains functions for parsing Motorola S-records (SREC), including verifying records,
 *          converting hexadecimal characters to byte values, and managing data queues. The functions
 *          provided include checking the validity of SREC lines, parsing records into structured data,
 *          and manipulating queues for handling data.
 *
 * @author Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/19
 * @copyright Copyright (c) 2024
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "SREC.h"
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
 *@brief Lookup table for hexadecimal character to byte conversion.
 *@details This table provides a direct mapping from hexadecimal characters ('0'-'9', 'A'-'F', 'a'-'f') to their corresponding byte values.
 *         Each index in the array corresponds to an ASCII value, and the value at that index is the byte representation of the hex character.
 *         This is useful for quick and efficient conversion of hex characters to their numerical byte equivalents.
 */
static const uint8_t hex_lookup[256] = {
    ['0'] = 0, ['1'] = 1, ['2'] = 2, ['3'] = 3, ['4'] = 4, ['5'] = 5, ['6'] = 6, ['7'] = 7, ['8'] = 8, ['9'] = 9, ['A'] = 10, ['B'] = 11, ['C'] = 12, ['D'] = 13, ['E'] = 14, ['F'] = 15, ['a'] = 10, ['b'] = 11, ['c'] = 12, ['d'] = 13, ['e'] = 14, ['f'] = 15};

/*
 *@brief Converts a hexadecimal character to its byte value.
 *@details This function takes a single hexadecimal character as input and returns its corresponding byte value.
 *         If the character is not a valid hexadecimal character, the function returns 0.
 *@param c The hexadecimal character to be converted.
 *@returns The byte value corresponding to the hexadecimal character.
 */
uint8_t hexCharToByte(char c)
{
    uint8_t value = 0;
    switch (c)
    {
    case '0' ... '9':
        value = c - '0';
        break;
    case 'A' ... 'F':
        value = c - 'A' + 10;
        break;
    case 'a' ... 'f':
        value = c - 'a' + 10;
        break;
    default:
        value = 0;
        break;
    }
    return value;
}

/*
 *@brief Converts two hex characters to a byte.
 *@param high The high hex character.
 *@param low The low hex character.
 *@returns The byte value.
 */
uint8_t hex_chars_to_byte(char high, char low)
{
    /* Convert the high and low hex characters to their corresponding nibble values and combine them */
    return (hex_lookup[(unsigned char)high] << 4) | hex_lookup[(unsigned char)low];
}

/*
 *@brief Validates an SREC line record.
 *@param srec_line Pointer to the SREC line record.
 *@returns Byte count if valid; 0 if invalid.
 */
uint8_t Check_Line_Record(volatile char *srec_line)
{
    uint8_t loop = 0;               /* For loop */
    uint8_t checksum_cal = 0;       /* check sum */
    uint8_t checksum_in_record = 0; /* check sum in record */
    uint8_t byteCount_in_record;    /* byte Count in record */
    uint8_t sum = 0;                /* sum of record */
    uint8_t result = 0;             /* return value */
    uint8_t value;                  /* hex chars to byte */
    uint8_t i = 0;                  /* For loop */

    /* Check if the line starts with 'S' */
    if (srec_line[0] == 'S')
    {
        /* Get the byte count from the record */
        byteCount_in_record = hex_chars_to_byte(srec_line[2], srec_line[3]);
        loop = byteCount_in_record * 2;

        /* Sum all bytes in the record */
        for (i = 2; i <= loop; i += 2)
        {
            value = hex_chars_to_byte(srec_line[i], srec_line[i + 1]);
            sum += value;
        }

        /* Calculate the checksum */
        checksum_cal = ~sum;

        /* Get the checksum from the record */
        checksum_in_record = hex_chars_to_byte(srec_line[loop + 2], srec_line[loop + 3]);

        /* Compare the calculated checksum with the checksum in the record */
        if (checksum_cal == checksum_in_record)
        {
            result = byteCount_in_record;
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }

    return result;
}

/*
 *@brief Parses an SREC record and fills the Record structure.
 *@param record Pointer to the SREC record.
 *@param record_struct Pointer to the Record structure to be filled.
 *@param byteCount_in_record The byte count in the record.
 */
void record_parser(volatile char *record, Record *record_struct, uint8_t byteCount_in_record)
{
    uint8_t byteCount_of_data;
    uint32_t address = 0;
    uint8_t i = 0;

    /* Extract the address from the record */
    record_struct->address = (hexCharToByte(record[4]) << 12) | (hexCharToByte(record[5]) << 8) |
                             (hexCharToByte(record[6]) << 4) | hexCharToByte(record[7]);

    /* Calculate the byte count of data */
    byteCount_of_data = byteCount_in_record * 2 - 6;

    /* Parse the data from the record */
    for (i = 0; i < byteCount_of_data; i += 4)
    {
        if (0 == i)
        {
            /* Fill data1 array with bytes from the record */
            record_struct->data1[0] = hex_chars_to_byte(record[8], record[9]);
            record_struct->data1[1] = hex_chars_to_byte(record[10], record[11]);
            record_struct->data1[2] = hex_chars_to_byte(record[12], record[13]);
            record_struct->data1[3] = hex_chars_to_byte(record[14], record[15]);
        }
        else if (4 == i)
        {
            /* Fill data2 array with bytes from the record */
            record_struct->data2[0] = hex_chars_to_byte(record[16], record[17]);
            record_struct->data2[1] = hex_chars_to_byte(record[18], record[19]);
            record_struct->data2[2] = hex_chars_to_byte(record[20], record[21]);
            record_struct->data2[3] = hex_chars_to_byte(record[22], record[23]);
        }
        else if (8 == i)
        {
            /* Fill data3 array with bytes from the record */
            record_struct->data3[0] = hex_chars_to_byte(record[24], record[25]);
            record_struct->data3[1] = hex_chars_to_byte(record[26], record[27]);
            record_struct->data3[2] = hex_chars_to_byte(record[28], record[29]);
            record_struct->data3[3] = hex_chars_to_byte(record[30], record[31]);
        }
        else if (12 == i)
        {
            /* Fill data4 array with bytes from the record */
            record_struct->data4[0] = hex_chars_to_byte(record[32], record[33]);
            record_struct->data4[1] = hex_chars_to_byte(record[34], record[35]);
            record_struct->data4[2] = hex_chars_to_byte(record[36], record[37]);
            record_struct->data4[3] = hex_chars_to_byte(record[38], record[39]);
        }
        else
        {
            /* Do Nothing */
        }
    }
}
