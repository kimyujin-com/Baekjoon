#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, i, cnt = 0, keep, a = 1, b = 1;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		if (cnt < n && n <= cnt + i) {
			keep = i + 1;//분자 분모를 합한 값/ 그룹 넘버에 1을 더한 값
			if (i % 2 != 0) {//갯수가 홀수일 경우
				a = keep + cnt - n;//n-cnt가 소그룹 속 나의 번호
				b = keep - a;
				break;
			}
			else {
				a = n - cnt;//n-cnt가 소그룹 속 나의 번호
				b = keep - a;
				break;
			}
		}
		else
			cnt = cnt + i;
	}

	printf("%d%c%d", a, '/', b);
}