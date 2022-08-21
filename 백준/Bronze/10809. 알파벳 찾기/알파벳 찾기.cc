#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int is_in(char ch1[], char a);
int main(void)
{
	char i;
	char ch[100];

	scanf("%s", ch);
	
	for (i = 'a'; i <= 'z'; i++)
		printf("%d ", is_in(ch, i));
}
int is_in(char ch1[], char a)
{
	char i;

	for (i = 0; ch1[i] != '\0'; i++)
		if (ch1[i] == a)
			return i;
	return -1;
}