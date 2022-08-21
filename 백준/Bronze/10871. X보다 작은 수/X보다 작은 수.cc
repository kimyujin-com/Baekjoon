#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, standard, num, n;
	
	scanf("%d %d", &num, &standard);

	for (i = 0; i < num; i++) {
		scanf("%d", &n);
		if (n < standard)
			printf("%d ", n);
	}
}