#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
int is_prime[MAX];

void check_prime_num()
{
	int i, j;

	is_prime[1] = 0;// 1은 소수에 포함되지 않는다. 
	for (i = 2; i < MAX; i++)
		is_prime[i] = 1;
	for (i = 2; i < MAX; i++)
		if (is_prime[i] == 0)
			continue;
		else
			for (j = 2 * i; j < MAX; j += i)
				is_prime[j] = 0;
}

int main()
{
	int i, n, N, cnt = 0;

	scanf("%d", &N);

	check_prime_num();

	for (i = 0; i < N; i++) {
		scanf("%d", &n);
		if (is_prime[n] == 1)
			cnt++;
	}
	printf("%d\n", cnt);
}