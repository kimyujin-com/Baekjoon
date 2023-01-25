#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 26

int visited[MAX_VERTICES][MAX_VERTICES] = { 0, };

int dfs_interactive(char l[26][26], int i, int j)
{
	int cnt = 1;
	visited[i][j] = 1;
	if (!visited[i][j + 1] && l[i][j + 1] == '1')
		cnt += dfs_interactive(l, i, j + 1);
	if (!visited[i + 1][j] && l[i + 1][j] == '1')
		cnt += dfs_interactive(l, i + 1, j);
	if (!visited[i][j - 1] && l[i][j - 1] == '1')
		cnt += dfs_interactive(l, i, j - 1);
	if (!visited[i - 1][j] && l[i - 1][j] == '1')
		cnt += dfs_interactive(l, i - 1, j);
	return cnt;
}

void insertionSort(int* arr, int size) {
	int i, j, key;
	for (i = 1; i < size; i++) {
		key = arr[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사
		for (j = i - 1; j >= 0 && arr[j] > key; j--) // key가 더 큰 값일 때까지 
			arr[j + 1] = arr[j]; // 한 칸 뒤로 이동 
		arr[j + 1] = key; // 알맞은 위치에 key 삽입 
	}
}

int main()
{
	int i, j, k = 0, N;
	char land[26][26] = {'0', };
	char trash;
	int complexNum[625];

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%c", &trash);
		for (j = 1; j <= N; j++)
			scanf("%c", &land[i][j]);
	}

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			if (land[i][j] == '1' && !visited[i][j])
				complexNum[k++] = dfs_interactive(land, i, j);

	insertionSort(complexNum, k);
	printf("%d\n", k);
	for (i = 0; i < k; i++)
		printf("%d\n", complexNum[i]);
}	