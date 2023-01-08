#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, num;

	scanf("%d", &num);

	for (i = num; i >= 1; i--)
		printf("%d\n", i);
}