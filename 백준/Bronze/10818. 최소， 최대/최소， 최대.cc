#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int str[1000000];
int getBest(int num, int s[]);
int getWorst(int num, int s[]);
int main(void)
{
	int i, n;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &str[i]);
	
	printf("%d %d\n", getWorst(n, str), getBest(n, str));
}
int getBest(int num, int s[]) {
	int i, best = -1000001;
	for (i = 0; i < num; i++)
		if (best < s[i])
			best = s[i];
	return best;
}
int getWorst(int num, int s[]) {
	int i, worst = 1000001;
	for (i = 0; i < num; i++)
		if (s[i] < worst)
			worst = s[i];
	return worst;
}