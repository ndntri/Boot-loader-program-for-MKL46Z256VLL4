/**
 * @file QUEUE.h
 * @brief Header file for queue management functions and data structures.
 * @details This header file defines the data structures and function prototypes for managing
 *          data queues. It includes declarations for functions that handle queue operations such as
 *          finding empty slots, popping elements, and initializing queue states. The file ensures
 *          that the queue operations are performed consistently and correctly across different source
 *          files.
 *
 * @author  Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/19
 * @copyright Copyright (c) 2024 Nguyen Dang Nhu Tri.
 */

#ifndef INCLUDES_QUEUE_H_
#define INCLUDES_QUEUE_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
#include "SREC.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define NUMBER_OF_QUEUES 4 /* NUMBER OF QUEUES */

/*
 * @brief Represents a queue element.
 * @details This structure is used to manage individual elements in a queue.
 */
typedef struct
{
    char record[MAX_LINE_LENGTH_RECORD]; /**< Buffer to store the record data */
    uint8_t state;                       /**< State indicator for the queue element */
} Queue;

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
 *@brief Finds the index of the first empty queue.
 *@param queue Array of Queue structures.
 *@returns Index of the first empty queue; 255 if all are full.
 */
uint8_t find_queue_empty(volatile Queue queue[]);

/*
 *@brief Pops the first element from the queue.
 *@param queue Pointer to the Queue structure array.
 */
void pop_queue(Queue *queue);

/*
 *@brief Initializes the state of all queues to 0.
 *@param queue Pointer to the Queue structure array.
 */
void initialize_state(volatile Queue *queue);

#endif /* INCLUDES_QUEUE_H_ */
