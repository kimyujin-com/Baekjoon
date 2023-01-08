#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	int front;
	int rear;
	element* data;
}QueueType;

int n;

int is_full(QueueType* q)
{
	return ((q->rear + 1) % n == q->front);
}

int is_empty(QueueType* q)
{
	return q->rear == q->front;
}

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		return;
	q->rear = (q->rear + 1) % n;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		return -1;
	q->front = (q->front + 1) % n;
	return q->data[q->front];
}

int main(void)
{
	int i, k;
	QueueType q;

	scanf("%d %d", &n, &k);
	init_queue(&q);
	q.data = (int*)malloc(sizeof(int) * ++n);

	for (i = 0; i < n; i++)
		enqueue(&q, i + 1);
	printf("<");
	while (!is_empty(&q))
	{
		for (i = 0; i < k - 1; i++)
			enqueue(&q, dequeue(&q));
		if ((q.front + 1) % n == q.rear)
			printf("%d", dequeue(&q));
		else
			printf("%d, ", dequeue(&q));
	}
	printf(">");
}