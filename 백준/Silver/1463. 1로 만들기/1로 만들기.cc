#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int f(int* M, int n) 
{
	int min = INT_MAX, tmp;

	if (n == 1)
		return 0;
	if (n % 3 == 0) {
		if (M[n / 3] == 0)
			M[n / 3] = f(M, n / 3);
		tmp = M[n / 3] + 1;
		if (tmp < min) min = tmp;
	}
	if (n % 2 == 0) {
		if (M[n / 2] == 0)
			M[n / 2] = f(M, n / 2);
		tmp = M[n / 2] + 1;
		if (tmp < min) min = tmp;
	}
	if (n - 1 > 1) {
		if (M[n - 1] == 0)
			M[n - 1] = f(M, n - 1);
		tmp = M[n - 1] + 1;
		if (tmp < min) min = tmp;
	}
	return min;
}

int main(void)
{
	int i, n;
	int* M;

	scanf("%d", &n);
	M = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		M[i] = 0;
	printf("%d\n", f(M, n));
}