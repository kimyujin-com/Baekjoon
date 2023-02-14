#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 32002
#define MAX_STACK_SIZE 100001

typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
}GraphNode;
typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	if (u > g->n || v > g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

typedef int element;
typedef struct {
	int top;
	element stack[MAX_STACK_SIZE];
}StackType;

void init(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}
 
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s))
		return;
	s->stack[++s->top] = item;
}

element pop(StackType* s)
{
	if (is_empty(s))
		return -1;
	return s->stack[s->top--];
}

int topo_sort(GraphType* g)
{
	int i;
	StackType s;
	GraphNode* node;

	//진입차수 계산
	int* in_degree = (int*)malloc(g->n * sizeof(int));
	for (i = 1; i <= g->n; i++)
		in_degree[i] = 0;
	for (i = 1; i <= g->n; i++) {
		GraphNode* node = g->adj_list[i];//i에서 나오는 간선들
		while (node != NULL) {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}

	init(&s);
	for (i = 1; i <= g->n; i++)
		if (in_degree[i] == 0) push(&s, i);
	for (i = 1; i <= g->n; i++) {
		while (!is_empty(&s)) {
			int w;
			w = pop(&s);
			printf("%d ", w);
			node = g->adj_list[w];
			while (node != NULL) {
				int u = node->vertex;
				in_degree[u]--;
				if (in_degree[u] == 0) push(&s, u);
				node = node->link;
			}
		} 
	}
	return (i == g->n);
}

int main(void)
{
	int i, N, M;
	int a, b;
	GraphType g;

	scanf("%d %d", &N, &M);
	graph_init(&g);
	g.n = N;
	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		insert_edge(&g, a, b);
	}
	topo_sort(&g);
}