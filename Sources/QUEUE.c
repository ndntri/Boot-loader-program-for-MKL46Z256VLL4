/**
 * @file QUEUE.c
 * @brief Functions for managing data queues.
 * @details This file contains functions for handling data queues, including operations to find empty
 *          slots in the queue, pop elements from the queue, and initialize the queue state. The
 *          provided functions include searching for empty queue slots, removing the first element,
 *          and setting the initial state of the queue elements.
 * @author  Nguyen Dang Nhu Tri
 * @version 1.0
 * @date 2024/07/19
 * @copyright Copyright (c) 2024 Nguyen Dang Nhu Tri.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "QUEUE.h"
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
 *@brief Finds the index of the first empty queue.
 *@param queue Array of Queue structures.
 *@returns Index of the first empty queue; 255 if all are full.
 */
uint8_t find_queue_empty(volatile Queue queue[])
{
    uint8_t i = 0;        /* For the loop */
    uint8_t result = 255; /* Default result if no empty queue is found */

    for (i = 0; i < NUMBER_OF_QUEUES; i++)
    {
        if (queue[i].state == 0)
        {
            result = i; /* Found an empty queue */
            i = NUMBER_OF_QUEUES;
        }
        else
        {
            /* Do nothing */
        }
    }

    return result;
}

/*
 *@brief Pops the first element from the queue.
 *@param queue Pointer to the Queue structure array.
 */
void pop_queue(Queue *queue)
{
    uint8_t i = 0; /* For the loop */

    /* Check if the first element is active */
    if (queue[0].state == 1)
    {
        queue[0].state = 0; /* Mark the first element as inactive */
        for (i = 1; i < NUMBER_OF_QUEUES; i++)
        {
            /* Shift active elements to the front */
            if (queue[i].state == 1)
            {
                queue[i - 1].state = queue[i].state;
                queue[i].state = 0;
            }
            else
            {
                /* Do Nothing */
            }
        }
    }
    else
    {
        /* Do Nothing */
    }
}

/*
 *@brief Initializes the state of all queues to 0.
 *@param queue Pointer to the Queue structure array.
 */
void initialize_state(volatile Queue *queue)
{
    uint8_t i = 0; /* For the loop */

    for (i = 0; i < NUMBER_OF_QUEUES; i++)
    {
        queue[i].state = 0; /* Set each queue state to 0 */
    }
}