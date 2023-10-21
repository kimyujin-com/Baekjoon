#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count_digit(int long long n)
{
	if (n == 0)
		return 0;
	return 1 + count_digit(n / 10);
}

int multiple(int n)
{
	int i, result = 1;
	for (i = 1; i <= n; i++)
		result *= 10;
	return result;
}

int main()
{
	int i, digit, sumOfDigit = 0;
	int long long N;

	scanf("%lld", &N);
	digit = count_digit(N);
	for (i = 1; i <= digit - 1; i++)
		sumOfDigit += i * 9 * multiple(i - 1);
	sumOfDigit += digit * (N - multiple(digit - 1) + 1);

	printf("%d\n", sumOfDigit);
}