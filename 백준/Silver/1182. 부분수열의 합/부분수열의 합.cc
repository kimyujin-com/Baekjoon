#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int S)
{
	int i, lastIndex, smallest, sum = 0, cnt = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			sum += items[bucket[i]];
		if (sum == S)
			return 1;
	}

	if (k == 0) 
		return cnt;

	lastIndex = bucketSize - k - 1;
	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1; // 중복되지 않도록

	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		cnt += pick(items, itemSize, bucket, bucketSize, k - 1, S);
	}
	return cnt;
}

int main()
{
	int *items;
	int* bucket;
	int i, N, S, cnt = 0;

	scanf("%d", &N);
	scanf("%d", &S);
	items = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		scanf("%d", &items[i]);
	bucket = (int*)malloc(sizeof(int) * N);
	for (i = 1; i <= N; i++)
		cnt += pick(items, N, bucket, i, i, S);
	printf("%d\n", cnt);
}
