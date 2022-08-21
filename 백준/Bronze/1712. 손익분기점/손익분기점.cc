#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)//총 수입(판매비용C) 총 비용(=고정비용A+가변비용B)
{
	long long a, b, c, ans;

	scanf("%lld %lld %lld", &a, &b, &c);

	if (c <= b)
		printf("-1\n");

	else if (b < c) {
		ans = a / (c - b);
		printf("%lld\n", ans + 1);
	}
}