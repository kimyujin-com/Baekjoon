#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int L, int R) {
	int left = L, right = R;
	int pivot = arr[(L + R) / 2];    // pivot 설정 (가운데) 
	int temp;
	do
	{
		while (arr[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
			left++;
		while (arr[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
			right--;
		if (left <= right)    // left가 right보다 왼쪽에 있다면 교환 
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			/*left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동*/
			left++;
			right--;
		}
	} while (left <= right);    // left가 right 보다 오른쪽에 있을 때까지 반복 

  /* recursion */
	if (L < right)
		quickSort(arr, L, right);    // 왼쪽 배열 재귀적으로 반복 

	if (left < R)
		quickSort(arr, left, R);    // 오른쪽 배열 재귀적으로 반복 
}

int main()
{
	int i, n, N;
	int* divisor;

	scanf("%d", &n);
	divisor = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &divisor[i]);

	quickSort(divisor, 0, n - 1);
	printf("%d\n", divisor[0] * divisor[n - 1]);
}