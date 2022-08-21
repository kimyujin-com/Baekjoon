#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* A, int n)
{
	int i, j, tmp;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (A[j] < A[j + 1]) {
				tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;
			}
}

void printList(int* a, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d", a[i]);
	printf("\n");
}

int calculateDigit(int n)
{
	int digit = 0;
	while (n > 0) {
		digit++;
		n /= 10;
	}
	return digit;
}

int main(void)
{
	int i = 0, n, digit, tmpN;
	int* box;

	scanf("%d", &n);

	digit = calculateDigit(n);
	box = (int*)malloc(sizeof(int) * digit);
	tmpN = n;
	while (tmpN > 0) {
		box[i++] = tmpN % 10;
		tmpN /= 10;
	}

	bubbleSort(box, digit);
	printList(box, digit);
}