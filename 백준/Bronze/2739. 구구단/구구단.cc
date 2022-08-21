#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num, result, i;

	scanf("%d", &num);

	for (i = 0; i < 9; i++) {
		result = num * (i + 1);
		printf("%d * %d = %d\n", num, i + 1, result);
	}
}