#define _CRT_SECURE_NO_WARNINGS//평균 이상인 사람 비율 구하기
#include <stdio.h>
double get_average(int studentNum, int s[]);
double get_ratio(int stNum, int s2[], double average);
int main(void)
{
	int n, num, s1[1000], i, j;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		for (j = 0; j < num; j++)
			scanf("%d", &s1[j]);
		printf("%.3f\%\n", get_ratio(num, s1, get_average(num, s1)));
	}
}
double get_average(int studentNum, int s[])
{
	int i, sum = 0;
	double avg;

	for (i = 0; i < studentNum; i++)
		sum += s[i];
	avg = (double)sum / studentNum;

	return avg;
}
double get_ratio(int stNum, int s2[], double average)
{
	int i, cnt = 0;
	double ratio;

	for (i = 0; i < stNum; i++)
		if (average < s2[i])
			cnt++;

	ratio = (double)cnt / stNum * 100;
	return ratio;
}