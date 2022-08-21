#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num1, num2, round1, round2, round3, result;

	scanf("%d %d", &num1, &num2);

	round1 = num1 * (num2 % 10);
	num2 /= 10;
	round2 = num1 * (num2 % 10);
	num2 /= 10;
	round3 = num1 * num2;

	result = round3 * 100 + round2 * 10 + round1;

	printf("%d\n", round1);
	printf("%d\n", round2);
	printf("%d\n", round3);
	printf("%d\n", result);
}