#define _CRT_SECURE_NO_WARNINGS//문제5번
#include <stdio.h>
int main(void)
{
	int h, m;

	scanf("%d %d", &h, &m);//(0 ≤ H ≤ 23, 0 ≤ M ≤ 59)

	if (m >= 45)// 45분 이상일때 -> 시는 변하지 않는다.
		m = m - 45;
	else 
		if (h == 0) {
			h = 23;
			m = 60 - (45 - m);
		}
		else {
			h = h - 1;
			m = 60 - (45 - m);
		}
	printf("%d %d", h, m);
}