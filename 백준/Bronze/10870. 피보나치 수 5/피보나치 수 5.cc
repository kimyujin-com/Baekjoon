#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, i, a = 0, b = 1, c = 1;

	scanf("%d", &n);

	if (n == 0)
		c = a;
	else if (n == 1)
		c = b;
	else 
		for (i = 2; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}

	printf("%d\n", c);
}