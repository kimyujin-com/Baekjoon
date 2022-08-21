#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, i, total = 1;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		total *= (i + 1);

	printf("%d\n", total);
}