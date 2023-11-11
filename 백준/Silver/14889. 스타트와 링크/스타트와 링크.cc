#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int S[21][21];
int check[22];
int N;
int minGap = 10000000000;

void DFS(int cnt, int pos) // x는 카운트 수, pos는 다음 값
{
	int i;

	if (cnt == N / 2) // 카운트수가 총 인원 수의 1/2이 되면 능력치합 계산
	{
		int start, link;
		start = 0;
		link = 0;

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (check[i] == true && check[j] == true) start += S[i][j];
				if (check[i] == false && check[j] == false) link += S[i][j];
			}

		int temp = abs(start - link);
		if (minGap > temp) minGap = temp;

		return;
	}

	//멤버는 start에 포함되거나 link에 포함되거나 -> 오직 두 가지 케이스만 존재
	for (i = pos; i <= N; i++)
	{
		check[i] = true;
		DFS(cnt + 1, i + 1);
		check[i] = false;
	}
}

int main()
{
	int i, j;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			scanf("%d", &S[i][j]);

	DFS(0, 1);

	printf("%d\n", minGap);
}
