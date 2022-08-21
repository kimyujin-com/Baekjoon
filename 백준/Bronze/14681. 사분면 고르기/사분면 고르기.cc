#define _CRT_SECURE_NO_WARNINGS//문제 4번
#include <stdio.h>
int main(void)
{
	int num1, num2, square;

	scanf("%d %d", &num1, &num2);

	if (num1 > 0 && num2 > 0)
		square = 1;
	else if (num1 < 0 && num2 > 0)
		square = 2;
	else if (num1 < 0 && num2 < 0)
		square = 3;
	else
		square = 4;

	printf("%d\n", square);
}