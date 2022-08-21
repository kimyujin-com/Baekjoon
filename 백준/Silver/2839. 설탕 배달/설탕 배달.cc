#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, n, pack = -1, play;//pack봉지 갯수, play 반복문 최대 횟수

	scanf("%d", &n);

	play = n / 5;

	for (i = play; i >= 0; i--) {
		if ((n - 5 * i) % 3 == 0) {
			pack = i + (n - (5 * i)) / 3;
			break;
		}
	}
	printf("%d\n", pack);
}