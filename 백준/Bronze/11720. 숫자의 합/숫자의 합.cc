#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, i, sum = 0;
	char ch[100];

	scanf("%d", &n);
	scanf("%s", ch);

	for (i = 0; ch[i] != '\0'; i++)
		sum += ch[i] - 48;

	printf("%d", sum);
}