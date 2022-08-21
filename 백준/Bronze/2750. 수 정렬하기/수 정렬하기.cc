#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j, minIndex, keep, n, num[1000];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);

	for (i = 0; i < n - 1; i++) {
		minIndex = i;
		for (j = i; j < n; j++)
			if (num[j] < num[minIndex])
				minIndex = j;
		keep = num[i];
		num[i] = num[minIndex];
		num[minIndex] = keep;
	}

	for (i = 0; i < n; i++)
		printf("%d\n", num[i]);
}