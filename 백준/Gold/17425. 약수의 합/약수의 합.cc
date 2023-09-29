#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000001
long long sumOfDivisor[MAX];

void get_sumOfDivisor(int n)
{
	int i, j;
	for (i = 0; i < MAX; i++)
		sumOfDivisor[i] = 0;
	for (i = 1; i < MAX; i++) {
		for (j = i; j < MAX; j += i) {
			sumOfDivisor[j] += i;
		}
		sumOfDivisor[i] += sumOfDivisor[i - 1];
	}
}

int main()
{
	int i, j, T, N;

	scanf("%d", &T);
	get_sumOfDivisor(MAX);
	for (j = 0; j < T; j++) {
		scanf("%d", &N);
		printf("%lld\n", sumOfDivisor[N]);
	}
}