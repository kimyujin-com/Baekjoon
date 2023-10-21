#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int n;
int cnt = 0;

void pick(int* items, int itemSize, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, sum = 0;

	lastIndex = bucketSize - k - 1;

	for (i = 0; i <= lastIndex; i++)
		sum += items[bucket[i]];
	if (sum == n) {
		/**for (i = 0; i <= lastIndex; i++)
			if (items[bucket[i]] != 0) {
				if (i == lastIndex)
					printf("%d", items[bucket[i]]);
				else
					printf("%d+", items[bucket[i]]);
			}
		printf("\n");**/
			cnt++;
		return;
	}
	if (k == 0)
		return;

	for (i = 0; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		pick(items, itemSize, bucket, bucketSize, k - 1);
	}
	return;
}

int main()
{
	int i, T;
	int items[3] = { 1, 2, 3 };
	int bucket[10];

	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &n);
		pick(items, 3, bucket, n, n);
		printf("%d\n", cnt);
		cnt = 0;
	}
}