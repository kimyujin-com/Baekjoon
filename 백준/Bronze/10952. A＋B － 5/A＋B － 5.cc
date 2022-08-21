#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num1, num2, sum;
	
	scanf("%d %d", &num1, &num2);

	while (num1 != 0 || num2 != 0) {
		sum = num1 + num2;
		printf("%d\n", sum);
		scanf("%d %d", &num1, &num2);
	}
}