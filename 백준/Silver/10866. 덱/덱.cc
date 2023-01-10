#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100000

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;

void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}

int is_empty(DequeType* q)
{
	return q->front == q->rear;
}

int is_full(DequeType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void push_back(DequeType* q, element item)
{
	if (is_full(q))
		return;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element pop_front(DequeType* q)//dequeue
{
	if (is_empty(q))
		return -1;
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element get_front(DequeType* q)//peek
{
	if (is_empty(q))
		return -1;
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void push_front(DequeType* q, element val)
{
	if (is_full(q))
		return;
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element pop_back(DequeType* q)
{
	int prev;
	if (is_empty(q))
		return -1;
	prev = q->rear;
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_back(DequeType* q)
{
	if (is_empty(q))
		return -1;
	return q->data[q->rear];
}

int get_size(DequeType* q)
{
	return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

int main()
{
	int i, n, x;
	char s[20];
	DequeType d;

	init_deque(&d);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", s);
		if (!strcmp(s, "push_front")) {
			scanf("%d", &x);
			push_front(&d, x);
		}
		else if (!strcmp(s, "push_back")) {
			scanf("%d", &x);
			push_back(&d, x);
		}
		else if (!strcmp(s, "pop_front")) { printf("%d\n", pop_front(&d)); }
		else if (!strcmp(s, "pop_back")) { printf("%d\n", pop_back(&d)); }
		else if (!strcmp(s, "size")) { printf("%d\n", get_size(&d)); }
		else if (!strcmp(s, "empty")) { printf("%d\n", is_empty(&d)); }
		else if (!strcmp(s, "front")) { printf("%d\n", get_front(&d)); }
		else if (!strcmp(s, "back")) { printf("%d\n", get_back(&d)); }
	}
}