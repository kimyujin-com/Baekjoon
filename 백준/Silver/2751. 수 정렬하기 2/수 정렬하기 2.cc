#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**int partition(int* A, int p, int r)
{
	int i = -1, j = 0, k, tmp;
	for (k = 0; k < r + 1; k++)
		if (A[k] > A[r])
			j++;
		else {
			tmp = A[i + 1];
			A[i + 1] = A[k];
			A[k] = tmp;
			i++;
		}
	return i;
}

void quickSort(int* A, int p, int r)
{
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

int main(void)
{
	int i, n;
	int* box;

	scanf("%d", &n);
	box = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &box[i]);
	quickSort(box, 0, n - 1);
	for (i = 0; i < n; i++)
		printf("%d\n", box[i]);
}
**/

void merge(int* A, int p, int q, int r)//☆시작점은 p
{
	int* tmp;
	int i = 0, j, k;
	tmp = (int*)malloc(sizeof(int) * (r - p + 1));

	j = p;
	k = q + 1;
	while (j < q + 1 && k < r + 1)
		if (A[j] < A[k])
			tmp[i++] = A[j++];
		else
			tmp[i++] = A[k++];
	while (j < q + 1)
		tmp[i++] = A[j++];
	while (k < r + 1)
		tmp[i++] = A[k++];

	i = 0;
	for (j = p; j <= r; j++)
		A[j] = tmp[i++];
}

void mergeSort(int* A, int p, int r)
{
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main(void)
{
	int i, n;
	int* box;

	scanf("%d", &n);
	box = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &box[i]);
	mergeSort(box, 0, n - 1);
	for (i = 0; i < n; i++)
		printf("%d\n", box[i]);
}