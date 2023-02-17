#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
int arr[100001];
int max_tree[300002];
int min_tree[300002];

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int init_max(int start, int end, int index)
{
	int mid;
	if (start == end)
		return (max_tree[index] = arr[start]);
	mid = (start + end) / 2;
	return max_tree[index] = max(init_max(start, mid, index * 2), init_max(mid + 1, end, index * 2 + 1));
}

int init_min(int start, int end, int index)
{
	int mid;
	if (start == end) 
		return min_tree[index] = arr[start];
	mid = (start + end) / 2;
	return min_tree[index] = min(init_min(start, mid, index * 2), init_min(mid + 1, end, index * 2 + 1));
}

int interval_max(int start, int end, int index, int left, int right)
{
	int mid;
	if (start > right || end < left)
		return INT_MIN;
	else if (left <= start && end <= right)
		return max_tree[index];
	else {
		mid = (start + end) / 2;
		return max(interval_max(start, mid, index * 2, left, right), interval_max(mid + 1, end, index * 2 + 1, left, right));
	}
}

int interval_min(int start, int end, int index, int left, int right)
{
	int mid;
	if (start > right || end < left)
		return INT_MAX;
	else if (left <= start && end <= right)
		return min_tree[index];
	else {
		mid = (start + end) / 2;
		return min(interval_min(start, mid, index * 2, left, right), interval_min(mid + 1, end, index * 2 + 1, left, right));
	}
}

int main(void)
{
	int N, M, a, b, n;
	int i, j = 1;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%d", &n);
		arr[j++] = n;
	}

	init_min(1, j, 1);
	init_max(1, j, 1);

	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		printf("%d %d\n", interval_min(1, j, 1, a, b), interval_max(1, j, 1, a, b));
	}
}
