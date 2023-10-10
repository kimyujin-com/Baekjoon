#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001
int is_prime[MAX];

void check_prime(int N)
{
	int i, j;

	for (i = 0; i <= N; i++)
		is_prime[i] = 1;
	is_prime[1] = 0;
	for (i = 2; i <= N; i++) {
		if (is_prime[i] == 0)
			continue;
		else {
			for (j = i * 2; j <= N; j += i)
				is_prime[j] = 0;
		}
	}
}

int main()
{
	int i, M, N;

	scanf("%d %d", &M, &N);

	check_prime(N);
	for (i = M; i <= N; i++)
		if (is_prime[i] == 1)
			printf("%d\n", i);
}