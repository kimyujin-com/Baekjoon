#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num, total, i;
	
	scanf("%d", &num);

	total = 0;
	for (i = 1; i <= num; i++)
		total += i;
	printf("%d\n", total);
}