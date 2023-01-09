#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1000

typedef int element;
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
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

int main()
{
	int i, j, ansIndex = 0;
	int n, N, M, k;
	int cnt = 0, flag = 0, tmp = 0;
	QueueType q, q2;
	int* ans;

	scanf("%d", &n);
	ans = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		init_queue(&q);
		init_queue(&q2);
		scanf("%d %d", &N, &M);
		for (j = 0; j < N; j++)
			enqueue(&q2, 65 + j);
		for (j = 0; j < N; j++) {
			scanf("%d", &k);
			enqueue(&q, k);
		}
		cnt = 0;
		while (1) {
			flag = 0;
			for (j = q.front + 2; j <= q.rear; j++)
				if (q.data[q.front + 1] < q.data[j]) {
					flag = 1;
					enqueue(&q, dequeue(&q));
					enqueue(&q2, dequeue(&q2));
					break;
				}
			if (!flag) {
				tmp = q2.data[q.front + 1];
				dequeue(&q);
				dequeue(&q2);
				cnt++;
				if (tmp == 65 + M) {
					ans[ansIndex++] = cnt;
					break;
				}
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%d\n", ans[i]);
}