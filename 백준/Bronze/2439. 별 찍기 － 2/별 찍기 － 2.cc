#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j, num;
	
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		for (j = num; j > i; j--)
			printf(" ");
		for (j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}
}