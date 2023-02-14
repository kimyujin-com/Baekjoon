#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_VERTICES 101
#define INF 1000

int parent[MAX_VERTICES];

void set_init(int n)
{
	for (int i = 1; i <= n; i++)
		parent[i] = i;
}

int set_find(int curr)
{
	if (parent[curr] == curr) return curr;
	//부모의 값에다 부모의 부모를 넣어라
	else return parent[curr] = set_find(parent[curr]);
}

void set_union(int a, int b)
{
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
		parent[root1] = root2;
}

struct Edge {
	int start, end;
	double weight;
};
typedef struct GraphType {
	int n;//간선의 개수
	int nvertex;//정점의 개수
	struct Edge edges[MAX_VERTICES * MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g)
{
	g->n = g->nvertex = 0;
	for (int i = 0; i < MAX_VERTICES * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

void insert_edge(GraphType* g, int start, int end, int w)
{
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}

int compare(const void* first, const void* second)
{
	if (((struct Edge*)first)->weight > ((struct Edge*)second)->weight)
		return 1;
	else if (((struct Edge*)first)->weight < ((struct Edge*)second)->weight)
		return -1;
	else
		return 0;
}

double kruskal(GraphType* g)
{
	int edge_accepted = 0;
	int i = 0;
	double sum = 0;
	int uset, vset;
	struct Edge e;

	set_init(g->nvertex);
	qsort(g->edges, g->n, sizeof(struct Edge), compare);
	while (edge_accepted < (g->nvertex - 1))
	{
		e = g->edges[i++];
		uset = set_find(e.start);
		vset = set_find(e.end);
		if (uset != vset) {
			edge_accepted++;
			set_union(uset, vset);
			sum += e.weight;
		}
	}
	return sum;
}

typedef struct {
	double x;
	double y;
}Position;

double get_distance(Position* p, int start, int end)
{
	//pow는 제곱근, sqrt는 루트
	return sqrt(pow(p[start].x - p[end].x, 2) + pow(p[start].y - p[end].y, 2));
}

int main(void)
{
	int i, j, k = 0, n;
	double x, y;
	GraphType g;
	Position* p;

	scanf("%d", &n);
	p = (Position*)malloc(sizeof(Position) * n);
	for (i = 0; i < n; i++) {
		scanf("%lf %lf", &x, &y);  
		p[i].x = x;
		p[i].y = y;
	}
	graph_init(&g);
	g.nvertex = n;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++) {
			g.edges[k].start = i;
			g.edges[k].end = j;
			g.edges[k++].weight = get_distance(p, i, j);
			g.n++;
		}
	printf("%.2lf\n", kruskal(&g));
}