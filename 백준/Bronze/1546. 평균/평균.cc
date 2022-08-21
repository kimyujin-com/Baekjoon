#define _CRT_SECURE_NO_WARNINGS//점수 속이기
#include <stdio.h>
int get_best(int s[], int num);
void print_avg(int s1[], int num1, int bestSc);
int main(void)
{
	int n, score[1000], bestScore, i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &score[i]);
	bestScore = get_best(score, n);
	print_avg(score, n, bestScore);
}
int get_best(int s[], int num)
{
	int i, best;

	best = s[0];
	for (i = 0; i < num; i++)
		if (best < s[i])
			best = s[i];
	return best;
}
void print_avg(int s1[], int num1, int bestSc)
{
	int i;
	double avg, s2[1000], sum = 0;

	for (i = 0; i < num1; i++) {
		s2[i] = (double)s1[i] / bestSc * 100;
		sum += s2[i];
	}
	avg = (double)sum / num1;

	printf("%f\n", avg);
	return;
}