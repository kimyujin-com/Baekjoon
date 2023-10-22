#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int itemSize, int* bucket, int bucketSize, int k)
{
	int i, j, lastIndex, flag;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d ", items[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;

	for (i = 0; i < itemSize; i++) {
		flag = 0;
		for (j = 0; j < lastIndex + 1; j++)
			if (bucket[j] == i) {
				flag = 1;
				break;
			}
		if (flag) continue;
		bucket[lastIndex + 1] = i;
		pick(items, itemSize, bucket, bucketSize, k - 1);
	}
	return;
}

int main()
{
	int i, N;
	int *items, *bucket;

	scanf("%d", &N);
	items = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		items[i] = i + 1;
	bucket = (int*)malloc(sizeof(int) * N);
	pick(items, N, bucket, N, N);
}