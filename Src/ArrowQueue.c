/*
 * ArrowQueue.c
 *
 *  Created on: 17 de jun de 2019
 *      Author: Ariel
 */
#include "ArrowQueue.h"

#define CAPACITY 8

static struct {
	unsigned head;
	unsigned tail;
	unsigned size;
	arrow_t buffer[CAPACITY];
} queue;

void arrowQueueInit()
{
	queue.head = 0;
	queue.tail = 0;
	queue.size = 0;
}

unsigned arrowQueueEnqueue(arrow_t *item)
{
	if (queue.size < CAPACITY)
	{
		queue.buffer[queue.head].dir = item->dir;
		queue.buffer[queue.head].x = item->x;

		queue.head = (queue.head + 1) % CAPACITY;
		queue.size++;
		return 1;
	}
	return 0;
}

unsigned arrowQueueDequeue(void)
{
	if (queue.size > 0)
	{
		queue.tail = (queue.tail + 1) % CAPACITY;
		queue.size--;
		return 1;
	}
	return 0;
}

unsigned arrowQueuePeekTail(arrow_t *item)
{
	if (queue.size > 0)
	{
		item->dir = queue.buffer[queue.tail].dir;
		item->x = queue.buffer[queue.tail].x;
		return 1;
	}
	return 0;
}

unsigned arrowQueuePeekHead(arrow_t *item)
{
	if (queue.size > 0)
	{
		if (queue.head == 0)
		{
			item->dir = queue.buffer[CAPACITY - 1].dir;
			item->x = queue.buffer[CAPACITY - 1].x;
		}
		else
		{
			item->dir = queue.buffer[queue.head - 1].dir;
			item->x = queue.buffer[queue.head - 1].x;
		}
		return 1;
	}
	return 0;
}

void arrowQueueForEach(void (*callback)(arrow_t *item))
{
	unsigned tail, i;

	for (tail = queue.tail, i = 0; i < queue.size; i++, tail = (tail + 1) % CAPACITY)
	{
		callback(&queue.buffer[tail]);
	}
}
