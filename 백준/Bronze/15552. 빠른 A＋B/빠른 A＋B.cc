#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, num, sum, num1, num2;

	scanf("%d", &num);
    

	for (i = 0; i < num; i++) {
        scanf("%d %d", &num1, &num2);
		sum = num1 + num2;
		printf("%d\n", sum);
	}
}