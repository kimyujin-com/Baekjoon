//상근이가 모든 국가를 여행하기 위해
//타야 하는 비행기 종류의 최소 개수를 출력한다.
//비행기를 타는 횟수로 잘못 생각
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j;
	int T, N, M;
	int a, b;

	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		for (j = 0; j < M; j++)
			scanf("%d %d", &a, &b);
		printf("%d\n", N - 1);
	}
}