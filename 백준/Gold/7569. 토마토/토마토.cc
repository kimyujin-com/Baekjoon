#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VERTICES 101

typedef struct {
	int box[MAX_VERTICES][MAX_VERTICES];
}element_int;
typedef struct {
	int n;
	element_int data[MAX_VERTICES];
}Tomatoes;

typedef struct {
	int x, y, z;
}element;
typedef struct {
	int front, rear;
	element data[1000000];
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

Tomatoes t;
QueueType q;
element e;

int cnt = 0;
int M, N, H;
int dx[6] = { -1, 0, 1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

int BFS()
{
	int i;
	int x = 0, y = 0 , z = 0;
	int next_x, next_y, next_z;

	while (!is_empty(&q)) {
		x = get_front(&q).x; y = get_front(&q).y; z = get_front(&q).z;
		dequeue(&q);
		for (i = 0; i < 6; i++) {
			next_x = x + dx[i];
			next_y = y + dy[i];
			next_z = z + dz[i];
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M
				&& next_z >= 0 && next_z < H) {
				if (t.data[next_z].box[next_x][next_y] == 0) {
					t.data[next_z].box[next_x][next_y] = t.data[z].box[x][y] + 1;
					e.x = next_x; e.y = next_y; e.z = next_z;
					enqueue(&q, e);
					cnt--;
				}
			}
		}
	}
	if (cnt == 0)
		return t.data[z].box[x][y] - 1;
	else
		return -1;
}

int main(void)
{
	int i, j, k;

	scanf("%d %d %d", &M, &N, &H);
	init_queue(&q);
	t.n = H;
	for (i = 0; i < H; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < M; k++) {
				scanf("%d", &t.data[i].box[j][k]);
				if (t.data[i].box[j][k] == 1) {
					e.x = j; e.y = k; e.z = i;
					enqueue(&q, e);
				}
				else if (t.data[i].box[j][k] == 0)
					cnt++;
			}
	if (cnt == 0)
		printf("0\n");
	else
		printf("%d\n", BFS());
}