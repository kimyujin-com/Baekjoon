#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, cnt;
	int multiple;

	while (scanf("%d", &n) != EOF) {
		cnt = 1;
		multiple = 1;
		while (1) {
			if (multiple % n == 0) { //multiple == n * a + b, (n * a + b) % n == ((n*a) % n + b % n) % n == (b % n) % n
				printf("%d\n", cnt);
				break;
			}
			else {
				multiple = multiple * 10 + 1;
				multiple %= n;//모듈러 연산 적용 (a + b) % n == (a % n + b % n) % n
				cnt++;
			}
		}
	}

}