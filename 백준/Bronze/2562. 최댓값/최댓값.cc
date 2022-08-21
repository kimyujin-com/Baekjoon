#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, num, best = -1, bestIndex;

	for (i = 0; i < 9; i++) {
		scanf("%d", &num);
		if (best < num) {
			best = num;
			bestIndex = i + 1;
		}
	}

	printf("%d\n", best);
	printf("%d\n", bestIndex);
}