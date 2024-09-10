/**
 * @file main.c
 * @brief Main program file for UART communication and bootloader functionality.
 * @details This file contains the main application logic for UART0 communication and bootloader operations.
 *          The program initializes UART0 for serial communication, configures GPIO pins for red and green LEDs,
 *          and processes incoming commands to control the bootloader process. It handles the reception of SREC
 *          file lines, parses them, and programs the flash memory. The main loop waits for commands from the
 *          UART interface, processes them, and performs the appropriate bootloader actions.
 *
 * @author Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/19
 * @copyright Copyright (c) 2024
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
#include "../Includes/DRIVER/DRIVER_SIM.h"
#include "../Includes/DRIVER/DRIVER_PORT.h"
#include "../Includes/DRIVER/DRIVER_GPIO.h"
#include "../Includes/DRIVER/DRIVER_UART.h"
#include "../Includes/DRIVER/DRIVER_NVIC.h"
#include "SREC.h"
#include "FLASH.h"
#include "BOOT.h"
#include "QUEUE.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define PIN_RED_LED 29
#define PIN_GREEN_LED 5
#define PIN_SWITCH_2 12
#define APPLICATION_ADDRESS 0x0000A000
#define NUMBER_OF_SECTORS_TO_DELETE 50
#define NUMBER_OF_BYTES_WRITTEN_DOWN_AT_ONE_TIME 4
#define SMALLEST_BYTES_COUNT_NUMBER 3 /* If a line record does not contain data, there are 2 address bytes + 1 checksum byte = 3 bytes*/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static volatile uint8_t buffer_index = 0;      /* Index for the current position in index of the queue. */
static volatile char received_data;            /* Variable to store the received UART data. */
static volatile Queue queue[NUMBER_OF_QUEUES]; /* Variable to store line records. */
static volatile uint8_t index_empty = 0;       /* Variable to store empty queue index. */
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*******************************************************************************
 * Code
 ******************************************************************************/

/*
 *@brief Initializes the clock and pins for UART0.
 *@details Configures the UART0 clock source, enables the clock for Port A and UART0, and sets up the pins for UART0 TX and RX functionality.
 *@param None
 *@returns None
 */
void Initialize_Clock_and_Pin_UART0(void)
{
    SIM_Config SIM_UART0_SOPT2_Config = {
        .Declare_SIM_Register = SOPT2_UART0SRC,               /* Selects the clock source for the UART0 as MCGFLLCLK clock */
        .Initialize_SOPT2.UART0SRC = SOPT2_UART0SRC_FLL_PLL}; /* Sets the UART0 clock source to MCGFLLCLK clock */

    SIM_Config SIM_UART0_SCGC5_Config = {
        .Declare_SIM_Register = SCGC5_PORTA,            /* Selects the clock for Port A */
        .Initialize_SCGC5.PORT_A = CLOCK_STATE_ENABLE}; /* Port A Clock Gate Control enabled */

    SIM_Config SIM_UART0_SCGC4_Config = {
        .Declare_SIM_Register = SCGC4_UART_0,           /* Selects the clock for UART0 */
        .Initialize_SCGC4.UART_0 = CLOCK_STATE_ENABLE}; /* UART0 Clock Gate Control enabled */

    PORT_Config PORT_UART0_Pin_tx_Config = {
        .PORTx = (PORT_Type *)PORTA,   /* Port A base address for UART0 TX */
        .Pin = 2,                      /* Pin 2 for UART0 TX */
        .PCR.MUX = PCR_IRQC_MUX_ALT2}; /* Set pin 2 to UART0 TX functionality (ALT2) */

    PORT_Config PORT_UART0_Pin_rx_Config = {
        .PORTx = (PORT_Type *)PORTA,   /* Port A base address for UART0 RX */
        .Pin = 1,                      /* Pin 1 for UART0 RX */
        .PCR.MUX = PCR_IRQC_MUX_ALT2}; /* Set pin 1 to UART0 RX functionality (ALT2) */

    DRIVER_SIM_Config(&SIM_UART0_SOPT2_Config);    /* Configure UART0 clock source */
    DRIVER_SIM_Config(&SIM_UART0_SCGC5_Config);    /* Enable the clock for Port A */
    DRIVER_PORT_Config(&PORT_UART0_Pin_tx_Config); /* Configure pin 2 for UART0 TX */
    DRIVER_PORT_Config(&PORT_UART0_Pin_rx_Config); /* Configure pin 1 for UART0 RX */
    DRIVER_SIM_Config(&SIM_UART0_SCGC4_Config);    /* Enable the clock for UART0 */
}

/*
 *@brief Initializes UART0 with specified settings.
 *@details Configures UART0 with a baud rate, enables the transmitter and receiver, and initializes the UART0 module.
 *         The configuration includes setting up the baud rate divisor, enabling the UART transmitter and receiver,
 *         and configuring the UART control registers.
 *@param None
 *@returns None
 */
void Initialize_UART0(void)
{
    UART_Config UART0_Config = {
        .UARTx = (UART_Type *)UART0, /* Base address of the UART0 module */
        .BDL = 0xB,                  /* Baud Rate Divisor LSB (Low Byte) | SBR =  UART clock / (Baud rate * (OSROSR = 17 after reset) )*/
                                     /* SBR = 20971520 /(115200 * 17) = 11 = 0xB  */
        .BDH.SBR = 0x0,              /* Baud Rate Divisor MSB (High Byte) */
        .C2.TE = C2_TE_ENABLED,      /* Enable UART Transmitter */
        .C2.RIE = C2_RIE_ENABLED,    /* Receiver interrupt enabled */
        .C2.RE = C2_RE_ENABLED};     /* Enable UART Receiver */

    DRIVER_UART_Config(&UART0_Config); /* Apply the UART0 configuration */
}

/*
 *@brief Receives a character from UART0.
 *@details Waits until there is data available in the receive data register, then reads and returns the received character.
 *         The function waits for the receive data register full flag to be set, indicating that data is available,
 *         and then reads the data from the receive data buffer.
 *@param None
 *@returns The character received from UART0.
 */
char UART0_receive(void)
{
    while (!DRIVER_UART_S1_Receive_Data_Register_Full_Flag((UART_Type *)UART0))
    {
        /* Wait until the receive data register is full */
    }

    return DRIVER_UART_D_Read_receive_data_buffer((UART_Type *)UART0); /* Read and return the received character */
}

/*
 *@brief Initializes the red LED.
 *@details Configures the system clock for PORTE, sets up the port pin for the red LED as a GPIO output,
 *         and initializes the red LED to be in the high state.
 *@param None
 *@returns None
 */
void Initialize_Red_Led(void)
{
    SIM_Config SIM_Red_Led_Config = {
        .Declare_SIM_Register = SCGC5_PORTE,            /* Selects clock for PORTE */
        .Initialize_SCGC5.PORT_E = CLOCK_STATE_ENABLE}; /* Enable clock for PORTE */

    PORT_Config PORT_Red_Led_Config = {
        .PORTx = (PORT_Type *)PORTE,   /* Base address for PORT E */
        .Pin = PIN_RED_LED,            /* Pin number for the red LED */
        .PCR.MUX = PCR_IRQC_MUX_GPIO}; /* Set pin function to GPIO */

    GPIO_Config GPIO_Red_Led_Config = {
        .GPIOx = (GPIO_Type *)GPIOE,          /* Base address for GPIO E */
        .Pin = PIN_RED_LED,                   /* Pin number for the red LED */
        .PDDR = PDDR_PDD_OUTPUT,              /* Configure pin as output */
        .Initial_State_of_Output_Pin = HIGH}; /* Set initial state to HIGH */

    DRIVER_SIM_Config(&SIM_Red_Led_Config);   /* Configure the clock for PORTE */
    DRIVER_PORT_Config(&PORT_Red_Led_Config); /* Configure the red LED pin as GPIO */
    DRIVER_GPIO_Config(&GPIO_Red_Led_Config); /* Initialize the red LED pin as output with HIGH state */
}

/*
 *@brief Initializes the green LED.
 *@details Configures the system clock for PORTD, sets up the port pin for the green LED as a GPIO output,
 *         and initializes the green LED to be in the high state.
 *@param None
 *@returns None
 */
void Initialize_Green_Led(void)
{
    SIM_Config SIM_Green_Led_Config = {
        .Declare_SIM_Register = SCGC5_PORTD,            /* Selects clock for PORTD */
        .Initialize_SCGC5.PORT_D = CLOCK_STATE_ENABLE}; /* Enable clock for PORTD */

    PORT_Config PORT_Green_Led_Config = {
        .PORTx = (PORT_Type *)PORTD,   /* Base address for PORT D */
        .Pin = PIN_GREEN_LED,          /* Pin number for the green LED */
        .PCR.MUX = PCR_IRQC_MUX_GPIO}; /* Set pin function to GPIO */

    GPIO_Config GPIO_Green_Led_Config = {
        .GPIOx = (GPIO_Type *)GPIOD,          /* Base address for GPIO D */
        .Pin = PIN_GREEN_LED,                 /* Pin number for the green LED */
        .PDDR = PDDR_PDD_OUTPUT,              /* Configure pin as output */
        .Initial_State_of_Output_Pin = HIGH}; /* Set initial state to HIGH */

    DRIVER_SIM_Config(&SIM_Green_Led_Config);   /* Configure the clock for PORTD */
    DRIVER_PORT_Config(&PORT_Green_Led_Config); /* Configure the green LED pin as GPIO */
    DRIVER_GPIO_Config(&GPIO_Green_Led_Config); /* Initialize the green LED pin as output with HIGH state */
}

/*
 *@brief Initializes the Switch 2.
 *@details Configures the system clock for PORTC, sets up the port pin
 *@param None
 *@returns None
 */
void Initialize_Switch_2(void)
{
    SIM_Config SIM_Switch_2_Config = {
        .Declare_SIM_Register = SCGC5_PORTC,            /* Selects clock for PORTC */
        .Initialize_SCGC5.PORT_C = CLOCK_STATE_ENABLE}; /* Enable clock for PORTC */

    PORT_Config PORT_Switch_2_Config = {
        .PORTx = (PORT_Type *)PORTC,   /* Base address for PORT C */
        .Pin = PIN_SWITCH_2,           /* Pin number for the SWITCH 2 */
        .PCR.MUX = PCR_IRQC_MUX_GPIO,  /* Set pin function to GPIO */
        .PCR.PS = PCR_PS_PULL_UP,      /* Set pull select */
        .PCR.PE = PCR_PE_PULL_ENABLE}; /* Set pull enable */

    GPIO_Config GPIO_Switch_2_Config = {
        .GPIOx = (GPIO_Type *)GPIOC, /* Base address for GPIO C */
        .Pin = PIN_SWITCH_2,         /* Pin number for the green  SWITCH 1 */
        .PDDR = PDDR_PDD_INPUT};     /* Configure pin as input */

    DRIVER_SIM_Config(&SIM_Switch_2_Config);   /* Configure the clock for PORTC */
    DRIVER_PORT_Config(&PORT_Switch_2_Config); /* Configure the SWITCH pin as GPIO */
    DRIVER_GPIO_Config(&GPIO_Switch_2_Config); /* Initialize the SWITCH pin as intput */
}

/*
 *@brief Sends a single byte of data via UART0.
 *@details Writes a byte of data to the UART0 transmit data buffer and waits until the transmission is complete.
 *         The function writes the data to the UART transmit data register and then polls the transmission complete flag
 *         to ensure that the data has been fully transmitted.
 *@param data The byte of data to be transmitted.
 *@returns None
 */
void send_bytes(char data)
{
    DRIVER_UART_D_Write_transmit_data_buffer(((UART_Type *)UART0), data); /* Write the data to the UART transmit data buffer */

    while (!DRIVER_UART_S1_Transmission_Complete_Flag((UART_Type *)UART0))
    {
        /* Waiting for the transmission to complete */
    }
}

/*
 *@brief Sends a null-terminated string of characters via UART0.
 *@details Transmits a string of characters one by one using the `send_bytes` function until the null terminator is reached.
 *         The function iterates through each character of the string, sending each character through UART0.
 *@param string Pointer to the null-terminated string to be transmitted.
 *@returns None
 */
void send_string(char *string)
{
    while ('\0' != *string)
    {
        send_bytes(*string); /* Send the current character */
        string++;            /* Move to the next character in the string */
    }
}

/*
 * @brief  UART0 Interrupt Handler
 * @details  Handles the UART0 interrupt triggered when the Receive Data Register Full (RDRF) flag is set.
 *           Reads the received data, processes commands terminated by newline characters, and manages the command queue.
 * @param  None
 * @returns  None
 */
void Implement_UART_0_IRQHandler(void)
{
    if (S1_RDRF_FULL == DRIVER_UART_S1_Receive_Data_Register_Full_Flag((UART_Type *)UART0))
    {
        received_data = DRIVER_UART_D_Read_receive_data_buffer((UART_Type *)UART0); /* Read and return the received character */

        if (received_data == '\n') /* Check if the received data is a newline character (indicating end of command). */
        {
            queue[index_empty].record[buffer_index] = '\0'; /* Null-terminate the command string. */
            queue[index_empty].state = 1;                   /* Enables the state of having data at the element */
            index_empty = find_queue_empty(queue);          /* Find empty queue to save next data*/
            buffer_index = 0;                               /* Reset the buffer index for the next command. */
        }
        else
        {
            queue[index_empty].record[buffer_index++] = received_data; /* Save data to queue */
            if (MAX_LINE_LENGTH_RECORD - 1 <= buffer_index)            /* Check if the buffer index exceeds the buffer length (to avoid overflow). */
            {
                buffer_index = 0; /* Reset the buffer index to handle the next command. */
            }
            else
            {
                /* Do nothing */
            }
        }
    }
    else
    {
        /* Do Nothing */
    }
}

/*
 * @brief  Main function for the bootloader application
 * @details  Initializes peripherals, handles UART0 interrupts, and processes incoming commands for bootloading.
 *           It erases sectors, receives SREC file lines, parses them, and programs the flash memory.
 * @param  None
 * @returns  None
 */
int main(void)
{
    uint8_t i = 1;                 /* For loop */
    uint8_t j = 0;                 /* For loop */
    uint8_t number_of_4_bytes = 0; /* Number of 4 bytes to write to flash */
    uint8_t byte_count = 0;        /* Byte count in record line */
    Record record_struct;          /*  contains information of 1 record line*/

    GPIO_PIN_STATE Red_Led_State = LOW;   /* State of the red LED. */
    GPIO_PIN_STATE Green_Led_State = LOW; /* State of the green LED. */

    Initialize_Clock_and_Pin_UART0(); /* Initialize clock and UART0 pins for communication. */
    Initialize_UART0();               /* Configure UART0 for receiving and sending data. */
    Initialize_Red_Led();             /* Initialize the red LED GPIO pin. */
    Initialize_Green_Led();           /* Initialize the green LED GPIO pin. */
    Initialize_Switch_2();            /* Initialize the Switch pin. */

    DRIVER_NVIC_Enable_External_Interrupt(UART0_IRQn);         /* Enable External Interrupt UART0 */
    DRIVER_NVIC_UART0_IRQHandler(Implement_UART_0_IRQHandler); /* Callback if interruption occurs */

    while (1) /* Main loop to continuously check for incoming commands and process them. */
    {
        if (!DRIVER_GPIO_PDIR_Read_Input_Pin(GPIOC, PIN_SWITCH_2))
        {
            DRIVER_GPIO_Output_Pin_State(GPIOE, PIN_RED_LED, LOW); /* Turn on the RED LED */
            send_string(" \n");
            send_string(" |***************** BOOTLOADER *****************|\r\n");
            send_string(" Preparing............\r\n");
            send_string(" Formatting data:");
            Erase_Multi_Sector(APPLICATION_ADDRESS, NUMBER_OF_SECTORS_TO_DELETE); /* Erase Multi Sector before flash */
            send_string(".....................done!\r\n");
            send_string(" \n");
            send_string(" Please update SREC (file format) now !\r\n");
            send_string(" Updating your firmware: ");
            initialize_state(queue); /* Initialize 'state' to 0*/
            while (1)
            {
                for (i = 0; i < NUMBER_OF_QUEUES; i++)
                {
                    if (queue[i].state == 1)
                    {
                        if (queue[i].record[1] == '1')
                        {
                            byte_count = Check_Line_Record(queue[i].record);
                            if (SMALLEST_BYTES_COUNT_NUMBER <= byte_count)
                            {
                                number_of_4_bytes = byte_count / NUMBER_OF_BYTES_WRITTEN_DOWN_AT_ONE_TIME; /* Because each write to flash is 4 bytes */
                                record_parser(queue[i].record, &record_struct, byte_count);                /* Get data and adress*/
                                for (j = 0; j < number_of_4_bytes; j++)
                                {
                                    if (j == 0)
                                    {
                                        __disable_irq();                                                 /* Disable all interrupts*/
                                        Program_LongWord_8B(record_struct.address, record_struct.data1); /* Program Address and Data (8bit pointer) into Flash Memory */
                                        __enable_irq();                                                  /* Anable all interrupts*/
                                    }
                                    else if (j == 1)
                                    {
                                        record_struct.address += 4;
                                        __disable_irq();
                                        Program_LongWord_8B(record_struct.address, record_struct.data2);
                                        __enable_irq();
                                    }
                                    else if (j == 2)
                                    {
                                        record_struct.address += 4;
                                        __disable_irq();
                                        Program_LongWord_8B(record_struct.address, record_struct.data3);
                                        __enable_irq();
                                    }
                                    else if (j == 3)
                                    {
                                        record_struct.address += 4;
                                        __disable_irq();
                                        Program_LongWord_8B(record_struct.address, record_struct.data4);
                                        __enable_irq();
                                    }
                                    else
                                    {
                                        /* Do Nothing */
                                    }
                                }

                                send_bytes('.');
                            }
                            else
                            {
                                send_string("Update failed\r\n");
                                send_string("Please start over from the beginning!\r\n");
                                queue[i].state = 0; /* Returns empty state ready to receive data */
                                while (1)
                                {
                                    /* Do nothing */
                                }
                            }

                            queue[i].state = 0;
                        }
                        else
                        {
                            queue[i].state = 0;
                        }

                        if (queue[i].record[1] == '9')
                        {
                            send_string(".done!\r\n");
                            send_string("  \n");
                            send_string("           +++++++++++++++++++++++++++++\n");
                            send_string("  \n");
                            send_string(" Please press the Reset Button to run the Application. Thanks :)\r\n");
                            while (1)
                            {
                                /* Do nothing */
                            }
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                }
            }
        }
        else
        {
            while (1)
            {
                JumpToApplication(); /* Jump To Application to run Application */
            }
        }
    }

    return 0;
}
/* EOF */
