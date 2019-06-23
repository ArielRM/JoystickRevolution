/*
 * ArrowQueue.h
 *
 *  Created on: 17 de jun de 2019
 *      Author: Ariel
 */

#ifndef ARROWQUEUE_H_
#define ARROWQUEUE_H_


typedef enum {
	ARROW_DIRECTION_NORTH = 0,
	ARROW_DIRECTION_SOUTH,
	ARROW_DIRECTION_EAST,
	ARROW_DIRECTION_WEST
} arrowDirection_t;

typedef struct {
	unsigned x;
	arrowDirection_t dir;
} arrow_t;

void arrowQueueInit();
unsigned arrowQueueEnqueue(arrow_t *item);
unsigned arrowQueueDequeue(void);
unsigned arrowQueuePeekTail(arrow_t *item);
unsigned arrowQueuePeekHead(arrow_t *item);
void arrowQueueForEach(void (*callback)(arrow_t *item));

#endif /* ARROWQUEUE_H_ */
