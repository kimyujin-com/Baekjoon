#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000001
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
	int i, n, flag;

	check_prime_num();

	scanf("%d", &n);
	while (n != 0) {
		flag = 0;
		for (i = n - 1; i > 1; i -= 2) 
			if (is_prime[i] == 1 && is_prime[n - i] == 1) {
				printf("%d = %d + %d\n", n, n - i, i);
				flag = 1;
				break;
			}
		if (flag == 0)
			printf(" Goldbach\'s conjecture is wrong.\n");
		scanf("%d", &n);
	}
}