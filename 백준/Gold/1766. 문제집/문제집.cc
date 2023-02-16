#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 32002
#define MAX_QUEUE_SIZE 100001

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

typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_VERTICES];
	int heap_size;
}HeapType;

HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
	h->heap_size = 0;
}

int is_empty(HeapType* h)
{
	return h->heap_size == 0;
}

void insert_min_heap(HeapType* h, int item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i].key = item;
}

int delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item.key;
}

void topo_sort(GraphType* g)
{
	int i;
	int val;
	GraphNode* node;
	HeapType h;

	int* in_degree = (int*)malloc(sizeof(int) * g->n + 1);
	for (i = 1; i <= g->n; i++)
		in_degree[i] = 0;
	for (i = 1; i <= g->n; i++) {
		node = g->adj_list[i];//i에서 나오는 간선들
		while (node != NULL) {
			val = node->vertex;
			in_degree[val]++;
			node = node->link;
		}
	}
	init(&h);
	for (i = 1; i <= g->n; i++)
		if (in_degree[i] == 0) 
			insert_min_heap(&h, i);
	while (!is_empty(&h)) {
		int out = delete_min_heap(&h);
		printf("%d ", out);
		node = g->adj_list[out];
		while (node != NULL) {
			val = node->vertex;
			in_degree[val]--;// 1 4 2 3
			if (in_degree[val] == 0)
				insert_min_heap(&h, val);
			node = node->link;
		}
		
	}
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