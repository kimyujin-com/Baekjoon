#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int t, h, w, n, i, unit, floor;

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		scanf("%d %d %d", &h, &w, &n);//층 수, 방 수, 몇 번째 손님

		if (n % h > 0) {
			unit = n / h + 1;//xxyy에서 yy구하기
			floor = n % h;//xxyy에서 xx구하기
		}
		else {
			unit = n / h;
			floor = h;
		}

		if (unit < 10)
			printf("%d0%d\n", floor, unit);
		else
			printf("%d%d\n", floor, unit);
	}
}