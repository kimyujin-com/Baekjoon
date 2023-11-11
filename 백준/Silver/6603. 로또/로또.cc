#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int itemSize, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d ", items[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1; // 중복되지 않도록

	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		pick(items, itemSize, bucket, bucketSize, k - 1);
	}
	return;
}

int main()
{
	int *items;
	int* bucket;
	int i, k;

	scanf("%d", &k);
	while (k != 0) {
		items = (int*)malloc(sizeof(int) * k);
		for (i = 0; i < k; i++)
			scanf("%d", &items[i]);
		bucket = (int*)malloc(sizeof(int) * k);
		pick(items, k, bucket, 6, 6);
		printf("\n");
		scanf("%d", &k);
	}
}
