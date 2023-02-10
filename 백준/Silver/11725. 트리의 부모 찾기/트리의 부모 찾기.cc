#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100001
int visited[MAX_SIZE];
int parent[MAX_SIZE];

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_SIZE];
}QueueType;

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_full(QueueType* q)
{
	return q->rear + 1 == MAX_SIZE;
}

int is_empty(QueueType* q)
{
	return q->rear == q->front;
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		return;
	q->data[q->rear++] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		return -1;
	return q->data[q->front++];
}

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

int main()
{
	int i, N, tmp;
	int a, b;
	QueueType q;
	ListNode** l;

	scanf("%d", &N);
	//초기화
	init_queue(&q);
	l = (ListNode**)malloc(sizeof(ListNode) * (N + 1));
	for (i = 1; i <= N; i++)
		l[i] = (ListNode*)malloc(sizeof(ListNode));
	for (i = 1; i <= N; i++) {
		l[i]->data = NULL;
		visited[i] = 0;
		parent[i] = 0;
	}

	for (i = 0; i < N - 1; i++) {
		scanf("%d %d", &a, &b);
		l[a] = insert_first(l[a], b);
		l[b] = insert_first(l[b], a);
	}

	enqueue(&q, 1);
	visited[1] = 1;
	while (!is_empty(&q)){
		tmp = dequeue(&q);
		for (; l[tmp]->data != NULL; l[tmp] = l[tmp]->link) {
			if (visited[l[tmp]->data] == 0) {
				visited[l[tmp]->data] = 1;
				parent[l[tmp]->data] = tmp;
				enqueue(&q, l[tmp]->data);
			}
		}
	}

	for (i = 2; i <= N; i++)
		printf("%d\n", parent[i]);
}