#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5000000

typedef int element; 
typedef struct {
	int front;
	int rear;
	element* data;
}QueueType;

void init_queue(QueueType* q)
{
	q->front = q->rear = -1;
}

int is_full(QueueType* q)
{
	return (q->rear == (MAX_QUEUE_SIZE - 1));
}

int is_empty(QueueType* q)
{
	return (q->rear == q->front);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		return;
	q->data[++q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		return -1;
	else
		return q->data[++q->front];
}

int is_one(QueueType* q)
{
	return (q->rear - q->front == 1);
}

int main()
{
	int i, n;
	QueueType q;

	scanf("%d", &n);
	q.data = (int*)malloc(sizeof(int) * MAX_QUEUE_SIZE);

	init_queue(&q);
	for (i = 0; i < n; i++)
		enqueue(&q, i+1);
	for (i = 0; !is_one(&q); i++)
		if (i % 2 == 0)
			dequeue(&q);
		else
			enqueue(&q, dequeue(&q));
	printf("%d", dequeue(&q));
}