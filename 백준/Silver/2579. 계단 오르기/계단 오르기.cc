#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int f(int* stairs, int** input, int k, int n, int cnt)
{
	int tmp1, tmp2;
	if (k == n - 3) {//최종칸에서 두 칸 전
		if (input[k + 2][1] == 0)
			input[k + 2][1] = f(stairs, input, k + 2, n, 0);
		return input[k + 2][1] + stairs[k];
	}
	else if (k == n - 2) {//최종칸에서 한 칸 전
		if (input[k + 1][0] == 0)
			input[k + 1][0] = f(stairs, input, k + 1, n, 0);
		return input[k + 1][0] + stairs[k];
	}
	else if (k == n - 1)//최종칸
		return stairs[n - 1];
	else {
		if (cnt == 1) {//이미 두 칸 연속
			if (input[k + 2][1] == 0)
				input[k + 2][1] = f(stairs, input, k + 2, n, 0);
			return input[k + 2][1] + stairs[k];
		}
		else {
			if (k == -1) {
				if (input[k + 1][0] == 0)
					input[k + 1][0] = f(stairs, input, k + 1, n, 0);
				tmp1 = input[k + 1][0];
			}
			else {
				if (input[k + 1][0] == 0)
					input[k + 1][0] = f(stairs, input, k + 1, n, 1);
				tmp1 = input[k + 1][0] + stairs[k];
			}
			if (input[k + 2][1] == 0)
				input[k + 2][1] = f(stairs, input, k + 2, n, 0);
			if (k == -1)
				tmp2 = input[k + 2][1];
			else
				tmp2 = input[k + 2][1] + stairs[k];
			if (tmp1 < tmp2) {
				//printf("걀버%d %d 2:%d 1:%d\n", k, k + 2, tmp2, tmp1);
				return tmp2;
			}
			else {
				//printf("걀버%d %d 1:%d 2:%d\n", k, k + 1, tmp1, tmp2);
				return tmp1;
			}
		}
	}
}

int main(void)
{
	int i, j, n;
	int* stairs, ** input;

	scanf("%d", &n);
	stairs = (int*)malloc(sizeof(int) * n);
	input = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		input[i] = (int*)malloc(sizeof(int) * 2);
	for (i = 0; i < n; i++)
		for (j = 0; j < 2; j++)
			input[i][j] = 0;

	for (i = 0; i < n; i++)
		scanf("%d", &stairs[i]);
	if (n == 1)
		printf("%d\n", stairs[0]);
	else if (n == 2)
		printf("%d\n", stairs[0] + stairs[1]);
	else
		printf("%d\n", f(stairs, input, -1, n, 0));
}
/*
5
1
4
3
1
9
정답: 16*/