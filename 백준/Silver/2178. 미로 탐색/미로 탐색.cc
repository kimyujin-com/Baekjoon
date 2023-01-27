#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 102

typedef struct {
	int first, second;
}element;
typedef struct {
	int front, rear;
	element* data;
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

int N, M;
char land[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES][MAX_VERTICES];
int path_cnt[MAX_VERTICES][MAX_VERTICES];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int x, int y)
{
	QueueType q;
	element e;
	int i;
	int next_x, next_y;

	init_queue(&q);
	q.data = (element*)malloc(sizeof(element) * (N + 1) * (M + 1));
	e.first = x; e.second = y;
	enqueue(&q, e);
	path_cnt[x][y] = 1;
	while (!is_empty(&q)) {
		x = get_front(&q).first;
		y = get_front(&q).second;
		dequeue(&q);
		for (i = 0; i < 4; i++) {
			next_x = x + dx[i];
			next_y = y + dy[i];
			if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M)
				if (land[next_x][next_y] == '1' && !visited[next_x][next_y]) {
					e.first = next_x; e.second = next_y;
					enqueue(&q, e);
					visited[next_x][next_y] = 1;
					path_cnt[next_x][next_y] = path_cnt[x][y] + 1;
				}
		}
	}
}

int main(void)
{
	int i, j;
	char trash;

	scanf("%d %d", &N, &M);
	
	for (i = 1; i <= N; i++) {
		scanf("%c", &trash);
		for (j = 1; j <= M; j++)
			scanf("%c", &land[i][j]);
	}
	BFS(1, 1);
	printf("%d\n", path_cnt[N][M]);
}