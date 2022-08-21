#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int check(char c[]);
int main(void)
{
	int n, i, total = 0;
	char ch[1000];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", ch);
		if (check(ch) == 0)
			total += 1;
	}
	
	printf("%d\n", total);
}
int check(char c[]) {
	int j, k, h, flag = 0;

	for (j = 0; c[j] != '\0'; j++) {
		for (k = j + 1; c[k] != '\0'; k++) {//자신보다 뒤의 알파벳 비교
			if (c[j] == c[k]) {//abaa abcaa
				for (h = j + 1; h < k; h++)//b나 bc 검사
					if (c[j] != c[h])
						return 1;
			}
		}
	}
	return 0;
}