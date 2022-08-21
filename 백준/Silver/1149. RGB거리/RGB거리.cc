#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int input[1001][4]; //임시
int dp[1001][4];

int min(int x, int y)
{
	return x < y ? x : y;
}

int main(void)
{
	int i, j, N, minIndex;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &input[i][j]);

	for (i = 0; i < 3; i++)
		dp[0][i] = input[0][i];
	for (i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + input[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + input[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + input[i][2];
	}

	minIndex = 0;
	for (i = 0; i < 3; i++)
		if (dp[N - 1][i] < dp[N - 1][minIndex])
			minIndex = i;
	printf("%d\n", dp[N - 1][minIndex]);
}