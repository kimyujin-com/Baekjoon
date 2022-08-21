#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, i, cnt = 1, keep = 1;

	scanf("%d", &n);

	for (i = 1; i < n; i++) {
		if (cnt < n && n <= cnt + 6 * i) {
			keep = i + 1;
			break;
		}
		else
			cnt = cnt + 6 * i;
	}
	
	printf("%d\n", keep);
}			