#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_greatest_common_divisor(int a, int b)
{
	int i;
	if (a < b) {
		for (i = a ; i > 0; i--)
			if (a % i == 0 && b % i == 0)
				return i;
	}
	else {
		for (i = b ; i > 0; i--)
			if (a % i == 0 && b % i == 0)
				return i;
	}
	return 0;
}

int get_least_common_multiple(int a, int b)
{
	int i;
	if (a < b) {
		for (i = 1;;i++)
			if (a * i % b == 0)
				return a * i;
	}
	else {
		for (i = 1;; i++)
			if (b * i % a == 0)
				return b * i;
	}
	return 0;
}

int main()
{
	int a, b;
	int greatest_common_divisor, least_common_multiple;

	scanf("%d %d", &a, &b);
	greatest_common_divisor = get_greatest_common_divisor(a, b);
	least_common_multiple = get_least_common_multiple(a, b);
	printf("%d\n", greatest_common_divisor);
	printf("%d\n", least_common_multiple);
}