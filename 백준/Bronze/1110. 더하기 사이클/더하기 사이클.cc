#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num, cnt = 0, sum = 0, keep;

	scanf("%d", &num);
	
	keep = num;
	do {
		sum = num / 10 + num % 10;
		num = (num % 10) * 10 + sum % 10;
		cnt++;
	} while (keep != num);

	printf("%d\n", cnt);
}