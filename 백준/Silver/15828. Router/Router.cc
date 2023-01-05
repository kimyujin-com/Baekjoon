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
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % n == q->front);
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

void queue_print(QueueType* q)
{
	if (is_empty(q)) {
		printf("empty");
		return;
	}
	while (!is_empty(q)) {
		printf("%d ", dequeue(q));
	}
}

int main(void)
{
	int k;
	QueueType q;

	init_queue(&q);

	scanf("%d", &n);
	q.data = (int*)malloc(sizeof(int) * ++n);

	scanf("%d", &k);
	while (k != -1) {
		if (k == 0)
			dequeue(&q);
		else
			enqueue(&q, k);
		scanf("%d", &k);
	}
	queue_print(&q);
}