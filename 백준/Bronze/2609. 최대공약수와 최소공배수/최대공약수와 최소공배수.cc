#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_gcd(int a, int b)
{
	int c;

	c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int get_lcm(int a, int b, int gcd)
{
	return a * b / gcd;
}

int main()
{
	int a, b;
	int gcd, lcm;

	scanf("%d %d", &a, &b);

	if (a > b)
		gcd = get_gcd(a, b);
	else
		gcd = get_gcd(b, a);
	lcm = get_lcm(a, b, gcd);

	printf("%d\n%d\n", gcd, lcm);
}