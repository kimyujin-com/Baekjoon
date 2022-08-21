#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, total = 0;
	char ch[15];

	scanf("%s", ch);
	
	for (i = 0; ch[i] != '\0'; i++) {
		if (ch[i] >= 'A' && ch[i] <= 'C')
			total += 3;
		else if (ch[i] >= 'D' && ch[i] <= 'F')
			total += 4;
		else if (ch[i] >= 'G' && ch[i] <= 'I')
			total += 5;
		else if (ch[i] >= 'J' && ch[i] <= 'L')
			total += 6;
		else if (ch[i] >= 'M' && ch[i] <= 'O')
			total += 7;
		else if (ch[i] >= 'P' && ch[i] <= 'S')
			total += 8;
		else if (ch[i] >= 'T' && ch[i] <= 'V')
			total += 9;
		else if (ch[i] >= 'W' && ch[i] <= 'Z')
			total += 10;
	}

	printf("%d\n", total);
}