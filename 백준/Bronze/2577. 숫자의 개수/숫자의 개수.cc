#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void printNum(int a[], int length);
int main(void)
{
	int a, b, c, result,arr[10], j, len;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	result = a * b * c;

	j = 0;
	len = 0;
	while (result != 0) {//각 자릿수 숫자들을 배열에 입력하기
		arr[j++] = result % 10;
		result /= 10;
		len++;
	}
	printNum(arr, len);
}
void printNum(int a[], int length)
{
	int i, j, cnt = 0;
	int ar[10];//arr[0] <- 0의 갯수

	for (i = 0; i < 10; i++) {//0부터 9까지의 수 중 갯수 수집하기
		cnt = 0;
		for (j = 0; j < length ; j++)
			if (i == a[j])
				cnt++;
		ar[i] = cnt;
	}
	for (i = 0; i < 10; i++)
		printf("%d\n", ar[i]);
	return;
}