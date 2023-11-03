#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int isSequence(int* a, int left, int size)
{
	int i, sub;

	if (size > 1) {
		for (i = left; i < size - 1; i++) { //2 3 4
			sub = a[i + 1] - a[i];
			if (sub < 0)
				return 0;
		}
	}
	return 1;
}

void selectionSortNew(int A[], int left, int n)
{
	int i, j, minIndex, tmp;
	for (i = 0; i < n - left - 1; i++) {
		minIndex = left;
		for (j = left; j < n - i; j++)
			if (A[j] < A[minIndex])
				minIndex = j;
		tmp = A[j - 1];
		A[j - 1] = A[minIndex];
		A[minIndex] = tmp;
	}
}

int main(void)
{
	int i, n, pivot = -2, tmp, maxIndex;
	int* bucket;

	scanf("%d", &n);
	bucket = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &bucket[i]);

	for (i = 0; i < n; i++) {
		if (isSequence(bucket, i, n)) {
			pivot = i - 1;
			break;
		}
	}
	if (pivot == -1)
		printf("-1\n");
	else {
		if (i == n) {//오름차순 sequence 존재하지 않음 ex)3 1 2 
			tmp = bucket[n - 1];
			bucket[n - 1] = bucket[n - 2];
			bucket[n - 2] = tmp;
		}
		else {//13245 -> 12543
			maxIndex = pivot + 1;
			for (i = pivot + 1; i < n; i++)
				if (bucket[i] < bucket[pivot] && bucket[maxIndex] < bucket[i])
					maxIndex = i;
			tmp = bucket[maxIndex];
			bucket[maxIndex] = bucket[pivot];
			bucket[pivot] = tmp;
			selectionSortNew(bucket, pivot + 1, n);
		}
		for (i = 0; i < n; i++)
			printf("%d ", bucket[i]);
	}
}
//5 1 2 3 4 -> 4 5 3 2 1 