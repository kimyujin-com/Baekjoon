#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_digit(char num[]);//자릿수 구하기
int arr[10005];
char a[10000], b[10000];
int main(void)
{
	int aDigit, bDigit, digitDiffer;
	int i, arrSize;
	int sum, bonus = 0;

	scanf("%s %s", &a, &b);

	aDigit = get_digit(a);
	bDigit = get_digit(b);

	if (aDigit >= bDigit) {
		digitDiffer = aDigit - bDigit;
		for (i = aDigit; i >= 0; i--) {
			if (i - digitDiffer >= 0)
				sum = b[i - digitDiffer] - '0' + a[i] - '0' + bonus;
			else
				sum = a[i] - '0' + bonus;
			bonus = 0;
			if (sum >= 10 && i != 0) {
				arr[i] = sum % 10;
				bonus = 1;
			}
			else
				arr[i] = sum;
		}
		arrSize = aDigit + 1;
	}
	else {
		digitDiffer = bDigit - aDigit;
		for (i = bDigit; i >= 0; i--) {
			if (i - digitDiffer >= 0)
				sum = a[i - digitDiffer] - '0' + b[i] - '0' + bonus;
			else
				sum = b[i] - '0' + bonus;
			bonus = 0;
			if (sum >= 10 && i != 0) {
				arr[i] = sum % 10;
				bonus = 1;
			}
			else
				arr[i] = sum;
		}
		arrSize = bDigit + 1;
	}
	for (i = 0; i < arrSize; i++)
		printf("%d", arr[i]);
	printf("\n");
}
int get_digit(char num[])
{
	int i;
	for (i = 0; num[i] != '\0'; i++);
	return i - 1;
}