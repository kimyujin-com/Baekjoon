#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, N;
	long long sumOfDivisor = 0;

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		sumOfDivisor += (N / i) * i;
	printf("%lld\n", sumOfDivisor);
}