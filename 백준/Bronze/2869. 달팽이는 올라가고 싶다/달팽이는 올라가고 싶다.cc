#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int a, b, v, days = 0;

	scanf("%d %d %d", &a, &b, &v);

	if ((v - a) % (a - b) != 0)
		days = (v - a) / (a - b) + 2;
	else
		days = (v - a) / (a - b) + 1;

	printf("%d\n", days);
}