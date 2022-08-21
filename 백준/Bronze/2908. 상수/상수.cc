#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char num1[4], num2[4];
	int i, numOne = 0, numTwo = 0;
	int n1[3] = {0}, n2[3] = {0};

	scanf("%s %s", num1, num2);

 	for (i = 0; num1[i] != '\0'; i++) {
		n1[i] = num1[2 - i] - '0';
		n2[i] = num2[2 - i] - '0';
	}

	for (i = 0; i < 3; i++) {
		numOne *= 10;
		numTwo *= 10;
		numOne += n1[i];
		numTwo += n2[i];
	}

	if (numOne < numTwo)
		printf("%d\n", numTwo);
	else
		printf("%d\n", numOne);
}