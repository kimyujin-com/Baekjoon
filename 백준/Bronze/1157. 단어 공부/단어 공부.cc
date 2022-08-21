#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char str[1000010];
int arr[200];
int main()
{
	int i, N, M = 0, flag = 0;
	scanf("%s", str);
	i = 0;
	while (str[i])
	{
		arr[str[i]]++;
		i++;
	}
	for (i = 65; i <= 90; i++)
	{
		if (M < arr[i] + arr[i + 32])
			N = i, M = arr[i] + arr[i + 32], flag = 0;
		else if (M == arr[i] + arr[i + 32])
			flag = 1;
	}
	if (flag)
		printf("?");
	else
		printf("%c", N);
	return 0;
}