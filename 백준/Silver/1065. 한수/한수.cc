#define _CRT_SECURE_NO_WARNINGS//각 자리수가 등차수열을 이루는가?
#include <stdio.h>
int get_sequence(int num);
int main(void)
{
	int n, cnt = 99, i;

	scanf("%d", &n);

	if (n > 99)
	{
		for (i = 99; i < n; i++) {
			if (get_sequence(i + 1))//0이 아니면
				cnt++;
		}
	}
	else
		cnt = n;
	printf("%d\n", cnt);
}
int get_sequence(int num)
{
	int i, a[4];

	for (i = 0; num > 0; i++) {
		a[i] = num % 10;
		num /= 10;
	}
	
	if (i == 3)
	{
		if (a[0] - a[1] == a[1] - a[2])
			return 1;// 맞다
		else
			return 0;
	}
	else
		return 0;
}