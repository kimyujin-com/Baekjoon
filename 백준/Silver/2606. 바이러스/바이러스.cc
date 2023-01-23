#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 101
#define MAX_STACK_SIZE 2000

int visited[MAX_VERTICES];

typedef int element;
typedef struct {
	int top;
	element data[MAX_STACK_SIZE];
}StackType;

typedef int element;
typedef struct ListNode {
	element vertex;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	int n;
	ListNode* adj_list[MAX_VERTICES];
}ListType;

void init_stack(StackType* s)
{
	s->top = -1;
}

int is_full(StackType* s)
{
	return s->top == MAX_STACK_SIZE;
}

int is_empty(StackType* s)
{
	return s->top == -1;
}

void push(StackType* t, element item)
{
	if (is_full(t))
		return;
	t->data[++t->top] = item;
}

element pop(StackType* s)
{
	if (is_empty(s))
		return -1;
	return s->data[s->top--];
}

element peek(StackType* s)
{
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		return -1;
	}
	else return s->data[s->top];
}

void init(ListType* l)
{
	int v;
	l->n = 0;
	for (v = 0; v < MAX_VERTICES; v++) {
		l->adj_list[v] = NULL;
	}
}

void insert_vertex(ListType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(ListType* g, int start, int end)
{
	if (start > g->n || end > g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->vertex = end;
	node->link = g->adj_list[start];
	g->adj_list[start] = node;
	ListNode* node2 = (ListNode*)malloc(sizeof(ListNode));
	node2->vertex = start;
	node2->link = g->adj_list[end];
	g->adj_list[end] = node2;
}

int dfs_interactive(ListType* n, int v)
{
	ListNode* i;
	int cnt = 0, flag = 0;
	int totalCnt = 0;
	StackType s;

	init_stack(&s);
	push(&s, v);
	while (!is_empty(&s)) {
		flag = 0;
		v = peek(&s);
		for (i = n->adj_list[v]; i; i = i->link)//인접한 정점
			if (!visited[i->vertex]) {
				visited[i->vertex] = ++cnt;
				push(&s, i->vertex);
				totalCnt++;
				flag = 1;
				break;
			}
		if (!flag)
			pop(&s);
	}
	return totalCnt;
}

int main()
{
	int i, start, end;
	int N, M;
	ListType* list;

	scanf("%d %d", &N, &M);
	list = (ListType*)malloc(sizeof(ListType));
	init(list);
	for (i = 0; i < N; i++)
		insert_vertex(list, i);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &start, &end);
		insert_edge(list, start, end);
	}
	for (i = 0; i <= N; i++)
		visited[i] = 0;
	printf("%d\n", dfs_interactive(list, 1) - 1);
	free(list);
}