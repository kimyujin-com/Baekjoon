#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define is_union 1
#define is_not_union 0

int parent[500001];

void set_init(int n)
{
	for (int i = 0; i < n; i++)
		parent[i] = i;
}

int set_find(int curr)
{
	if (parent[curr] == curr) return curr;
	else return parent[curr] = set_find(parent[curr]);
}

int set_union(int a, int b)
{
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2) {
		if (root1 < root2)
			parent[root1] =root2;
		else
			parent[root2] = root1;
		return is_not_union;
	}
	else
		return is_union;
}

int main(void)
{
	int n, m;
	int a, b;
	int i, ans = -1, flag = 0;

	scanf("%d %d", &n, &m);
	set_init(n);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (!flag && set_union(a, b)) {
			flag = 1;
			ans = i + 1;
		}
	}
	if (ans != -1)
		printf("%d\n", ans);
	else
		printf("0\n");
}