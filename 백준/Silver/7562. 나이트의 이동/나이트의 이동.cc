#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 301

typedef struct {
	int first, second;
}element;
typedef struct {
	int front, rear;
	element data[MAX_VERTICES * MAX_VERTICES];
}QueueType;

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

void enqueue(QueueType* q, element item)
{
	q->data[++q->rear] = item;
}

element dequeue(QueueType* q)
{
	return q->data[++q->front];
}

element get_front(QueueType* q)
{
	return q->data[q->front + 1];
}

int I;
int visited[MAX_VERTICES][MAX_VERTICES] = { 0, };
int path_cnt[MAX_VERTICES][MAX_VERTICES] = { 0, };
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int start_x, start_y, end_x, end_y;

void BFS(int x, int y)
{
	int i, flag;
	int next_x, next_y;
	QueueType q;
	element e;

	init_queue(&q);
	e.first = x; e.second = y;
	enqueue(&q, e);
	path_cnt[x][y] = 1;
	while (!is_empty(&q)) {
		x = get_front(&q).first;
		y = get_front(&q).second;
		if (x == end_x && y == end_y)
			break;
		dequeue(&q);
		for (i = 0; i < 8; i++) {
			flag = 0;
			next_x = x + dx[i];
			next_y = y + dy[i];
			if (next_x >= 0 && next_x < I && next_y >= 0 && next_y < I)
				if (!visited[next_x][next_y]) {
					e.first = next_x; e.second = next_y;
					enqueue(&q, e);
					visited[next_x][next_y] = 1;
					path_cnt[next_x][next_y] = path_cnt[x][y] + 1;
					if (next_x == end_x && next_y == end_y) {
						flag = 1;
						break;
					}
				}
			if (flag)
				break;
		}
	}
}

int main(void)
{
	int i, j, k, n;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &I);
		for (j = 0; j < I; j++)
			for (k = 0; k < I; k++) {
				visited[j][k] = 0;
				path_cnt[j][k] = 0;
			}
		scanf("%d %d", &start_x, &start_y);
		scanf("%d %d", &end_x, &end_y);
		BFS(start_x, start_y);
		printf("%d\n", path_cnt[end_x][end_y] - 1);
	}
}