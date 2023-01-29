#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VERTICES 101
# define INF 10000000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void floyd(GraphType* g)
{
	int i, j, k;
	for (i = 1; i <= g->n; i++)
		for (j = 1; j <= g->n; j++)
			A[i][j] = g->weight[i][j];

	for (k = 1; k <= g->n; k++) {
		for (i = 1; i <= g->n; i++)
			for (j = 1; j <= g->n; j++)
				if (i != j)
					if (A[i][k] + A[k][j] < A[i][j])
						A[i][j] = A[i][k] + A[k][j];
	}
}

int main(void)
{
	GraphType g;
	int n, m;
	int i, j;
	int start_city, end_city, cost;

	scanf("%d", &n);
	scanf("%d", &m);

	g.n = n;
	for (i = 1; i <= g.n; i++)
		for (j = 1; j <= g.n; j++)
			g.weight[i][j] = INF;

	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &start_city, &end_city, &cost);
		if (cost < g.weight[start_city][end_city])
			g.weight[start_city][end_city] = cost;
	}

	floyd(&g);

	for (i = 1; i <= g.n; i++) {
		for (j = 1; j <= g.n; j++)
			if (A[i][j] < INF)
				printf("%d ", A[i][j]);
			else
				printf("%d ", 0);
		printf("\n");
	}
}