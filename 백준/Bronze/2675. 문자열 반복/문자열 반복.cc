#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, num, i, j, k;
	char ch[20];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %s", &num, ch);
		for (k = 0; ch[k] != '\0'; k++)
			for (j = 0; j < num; j++)
				printf("%c", ch[k]);
		printf("\n");
	}
}