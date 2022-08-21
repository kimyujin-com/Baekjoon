#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, total = 0;
	char ch[100];

	scanf("%s", ch);

	for (i = 0; ch[i] != '\0'; i++) {
		if (ch[i] == 'c') {
			if (ch[i + 1] == '=' || ch[i + 1] == '-')
				total += 0;
			else
				total += 1;
		}
		else if (ch[i] == 'd') {
			if (ch[i + 1] == 'z')
				if (ch[i + 2] == '=')
					total += 0;
				else
					total += 1;
			else if (ch[i + 1] == '-')
				total += 0;
			else
				total += 1;
		}
		else if (ch[i] == 'l' || ch[i] == 'n')
			if (ch[i + 1] == 'j')
				total += 0;
			else
				total += 1;
		else if (ch[i] == 's' || ch[i] == 'z')
			if (ch[i + 1] == '=')
				total += 0;
			else
				total += 1;
		else
			total += 1;
	}
	printf("%d\n", total);
}