#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int isSequence(int* a, int left, int size)
{
	int i, sub;

	if (size > 1) {
		sub = a[left] - a[left + 1];
		for (i = left; i < size - 1; i++) {
			sub = a[i] - a[i + 1];
			if (sub < 0)
				return 0;
		}
	}
	return 1;
}

void selectionSortNew(int A[], int left, int n)
{
	int i, j, maxIndex, tmp;
	for (i = 0; i < n - left - 1; i++) {
		maxIndex = left;
		for (j = left; j < n - i; j++)
			if (A[maxIndex] < A[j])
				maxIndex = j;
		tmp = A[j - 1];
		A[j - 1] = A[maxIndex];
		A[maxIndex] = tmp;
	}
}

int main(void)
{
	int i, n, pivot = -2, tmp, minIndex;
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
			if (i == n) {//내림차순 sequence 존재하지 않음 ex)3 1 2 
				tmp = bucket[n - 1];
				bucket[n - 1] = bucket[n - 2];
				bucket[n - 2] = tmp;
			}
			else {//12543 -> 13245
				minIndex = pivot + 1;
				for (i = pivot + 1; i < n; i++)
					if (bucket[i] < bucket[minIndex] && bucket[pivot] < bucket[i])
						minIndex = i;
				tmp = bucket[minIndex];
				bucket[minIndex] = bucket[pivot];
				bucket[pivot] = tmp;
				selectionSortNew(bucket, pivot + 1, n);
			}
			for (i = 0; i < n; i++)
				printf("%d ", bucket[i]);
		}
}