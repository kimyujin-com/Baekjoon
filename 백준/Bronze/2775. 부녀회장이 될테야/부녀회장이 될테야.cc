#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, i, j;//입력받는 변수
	int floor, k, h = 0;

	scanf("%d", &n);
	
	while (h < n) {
		scanf("%d", &i);//층
		scanf("%d", &j);//호수

		int room[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
		floor = 0;
		while (floor < i) {
			for (k = 2; k <= j; k++)
				room[k] += room[k - 1];
			floor++;
		}
		printf("%d\n", room[j]);
		h++;
	}
}