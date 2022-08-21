#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int f(long long int* M, int n)
{
	if (n >= 1 && n <= 3)
		return 1;
	else if (n == 4 || n == 5)
		return 2;
	else {
		if (M[n - 5] == 0)
			M[n - 5] = f(M, n - 5);
		if (M[n - 1] == 0)
			M[n - 1] = f(M, n - 1);
		return M[n - 5] + M[n - 1];
	}
}

int main(void)
{
	int i, n, N;
	long long int M[101] = { 0, };

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &N);
		printf("%lld\n", f(M, N));
	}
}