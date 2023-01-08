#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int producer[10002];
int get_d(int num);
int main(void)
{
	int i, j, flag;

	for (i = 0; i <= 10000; i++)
		producer[i] = get_d(i + 1);

	for (j = 1; j <= 10000; j++) {
		flag = 1;
		for (i = 0; i <= 10000; i++)
			if (j == producer[i])
				flag = 0;
		if (flag)
			printf("%d\n", j);
	}
}
int get_d(int num)
{
	int d = num, i;

	for (i = 0; num > 0; i++) {
		d += num % 10;
		num /= 10;
	}

	return d;
}