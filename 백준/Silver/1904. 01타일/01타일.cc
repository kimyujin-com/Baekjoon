#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int f(int *F, int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else {
		if (F[n - 2] == 0)
			F[n - 2] = f(F, n - 2);
		if (F[n - 1] == 0)
			F[n - 1] = f(F, n - 1);
		return (F[n - 2] + F[n - 1]) % 15746;
	}
}

int main(void)
{
	int i, n;
	int* F;

	scanf("%d", &n);
	F = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 0; i < n; i++)
		F[i] = 0;
	printf("%d\n", f(F, n));
}