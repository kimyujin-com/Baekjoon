#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 7

int A[SIZE + 1];
int B[SIZE + 1];
int C[101];

void initArray(int array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		array[i] = 0;
}

void countingSort(int k) {
	int i, j;
	int lengthOfA = sizeof(A) / sizeof(A[0]);

	for (i = 0; i <= k; i++)
		C[i] = 0;
	for (j = 1; j < lengthOfA; j++)
		C[A[j]] += 1;
	for (i = 1; i <= k; i++)
		C[i] = C[i] + C[i - 1];
	for (j = lengthOfA - 1; j >= 1; j--) {
		B[C[A[j]]] = A[j];
		C[A[j]] -= 1;
	}
}
//9C7을 구하기 위해 pick함수를 사용한다.
int pick(int* items, int itemSize, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest, sum = 0;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			sum += items[bucket[i]];
		if (sum == 100)
			for (i = 0; i < SIZE; i++)
				A[i + 1] = items[bucket[i]];
		return sum;
	}

	lastIndex = bucketSize - k - 1;
	if (k == bucketSize)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1; // 중복되지 않도록

	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		sum = pick(items, itemSize, bucket, bucketSize, k - 1);
		if (sum == 100)
			break;
	}
	if (sum == 100)
		return 1;
	return 0;
}

int main()
{
	int items[9], bucket[7];
	int i, max = -1;

	for (i = 0; i < 9; i++)
		scanf("%d", &items[i]);

	initArray(A, SIZE + 1);
	initArray(B, SIZE + 1);
	initArray(C, 101);

	pick(items, sizeof(items) / sizeof(int), bucket, 7, 7);

	for (i = 1; i <= SIZE; i++)
		if (A[i] > max)
			max = A[i];
	countingSort(max);
	for (i = 1; i <= SIZE; i++)
		printf("%d\n", B[i]);
}
