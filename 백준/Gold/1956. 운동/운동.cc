#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 401
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
	int V, E;
	int i, j, k;
	int a, b, c;
	int min = INT_MAX;

	scanf("%d %d", &V, &E);
	g.n = V;

	for (i = 1; i <= g.n; i++)
		for (j = 1; j <= g.n; j++)
			g.weight[i][j] = INF;
	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		g.weight[a][b] = c;
	}

	floyd(&g);

	for (k = 1; k <= g.n; k++)
		for (i = 1; i <= g.n; i++)
			if (A[i][k] < INF && A[k][i] < INF)
				if (A[i][k] + A[k][i] < min)
					min = A[i][k] + A[k][i];
	if (min != INT_MAX)
		printf("%d\n", min);
	else
		printf("-1\n");
}