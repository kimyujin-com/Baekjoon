#define _CRT_SECURE_NO_WARNINGS//O X 퀴즈
#include <stdio.h>
int main(void)
{
	int num, i, j, sum, cnt;
	char a[80];

	scanf("%d", &num);

	for (j = 0; j < num; j++) {
		sum = 0;
		cnt = 0;

		scanf(" %s", a);
		for (i = 0; a[i] != '\0'; i++) {
			if (a[i] == 'O') {
				cnt++;
				sum += cnt;
			}
			else
				cnt = 0;
		}
		printf("%d\n", sum);
	}
}