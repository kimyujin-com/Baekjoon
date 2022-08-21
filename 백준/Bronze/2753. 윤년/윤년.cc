#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int year, ans;

	scanf("%d", &year);

	ans = 0;
	if (year % 4 == 0) {
		if (year % 100 != 0)//100의 배수가 아니면 윤년
			ans = 1;
		else if (year % 400 == 0)//400의 배수이면 윤년
			ans = 1;
	}
	
	printf("%d\n", ans);
}