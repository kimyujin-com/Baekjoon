#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_DEQUE_SIZE 100

typedef int element;
typedef struct {
	int front, rear;
	element data[MAX_DEQUE_SIZE];
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
	return ((q->rear + 1) % MAX_DEQUE_SIZE == q->front);
}

void push_back(DequeType* q, element item)
{
	if (is_full(q))
		return;
	q->rear = (q->rear + 1) % MAX_DEQUE_SIZE;
	q->data[q->rear] = item;
}

element pop_front(DequeType* q)//dequeue
{
	if (is_empty(q))
		return -1;
	q->front = (q->front + 1) % MAX_DEQUE_SIZE;
	return q->data[q->front];
}

element get_front(DequeType* q)//peek
{
	if (is_empty(q))
		return -1;
	return q->data[(q->front + 1) % MAX_DEQUE_SIZE];
}

void push_front(DequeType* q, element val)
{
	if (is_full(q))
		return;
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

element pop_back(DequeType* q)
{
	int prev;
	if (is_empty(q))
		return -1;
	prev = q->rear;
	q->rear = (q->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	return q->data[prev];
}

int main()
{
	int N, M;
	int i, j, cnt = 0, totalCnt = 0;
	int* box;
	DequeType d;

	init_deque(&d);
	scanf("%d %d", &N, &M);

	box = (int*)malloc(sizeof(int) * M);
	for (i = 0; i < N; i++)
		push_back(&d, i + 1);
	for (i = 0; i < M; i++)
		scanf("%d", &box[i]);
	for (i = 0; i < M; i++) {
		cnt = 0;
		for (j = (d.front + 1) % MAX_DEQUE_SIZE; j != (d.rear + 1) % MAX_DEQUE_SIZE; j = (j + 1) % MAX_DEQUE_SIZE)
			if (box[i] == d.data[j]) {
				if (j % MAX_DEQUE_SIZE == (d.front + 1) % MAX_DEQUE_SIZE)
					pop_front(&d);
				else if ((j - d.front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE <= (d.rear - j + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE) {
					while (j % MAX_DEQUE_SIZE != (d.front + 1) % MAX_DEQUE_SIZE) {
						push_back(&d, pop_front(&d));
						cnt++;
					}
					pop_front(&d);
				}
				else {
					while (j % MAX_DEQUE_SIZE != d.rear % MAX_DEQUE_SIZE) {
						push_front(&d, pop_back(&d));
						cnt++;
					}
					push_front(&d, pop_back(&d));
					cnt++;
					pop_front(&d);
				}
				break;
			}
		totalCnt += cnt;
	}
	printf("%d", totalCnt);
}