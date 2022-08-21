#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int right_max_sum(int A[], int left, int right)
{
	int i, sum = 0, max = INT_MIN;
	for (i = left; i <= right; i++) {
		sum += A[i];
		if (max < sum)
			max = sum;
	}
	return max;
}

int left_max_sum(int A[], int left, int right)
{
	int i, sum = 0, max = INT_MIN;
	for (i = right; i >= left; i--) {
		sum += A[i];
		if (max < sum)
			max = sum;
	}
	return max;
}

int max_sub_array(int A[], int left, int right)
{
	int mid, max = INT_MIN, right_max, left_max, mid_max;
	if (left >= right)
		return A[right];
	else {
		mid = (left + right) / 2;
		right_max = max_sub_array(A, mid + 1, right);
		max = right_max;
		left_max = max_sub_array(A, left, mid);
		if (max < left_max)
			max = left_max;
		mid_max = right_max_sum(A, mid + 1, right) + left_max_sum(A, left, mid);
		if (max < mid_max)
			max = mid_max;
		return max;
	}
}

int main(void)
{
	int i, n;
	int* m;

	scanf("%d", &n);
	m = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &m[i]);
	printf("%d\n", max_sub_array(m, 0, n - 1));
}