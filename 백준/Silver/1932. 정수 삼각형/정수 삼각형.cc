#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, n, max = 0;
	int** box, ** input;

	scanf("%d", &n);

	box = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		box[i] = (int*)malloc(sizeof(int) * (i + 1));
	input = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		input[i] = (int*)malloc(sizeof(int) * (i + 1));

	for (i = 0; i < n; i++)
		for (j = 0; j < i + 1; j++)
			input[i][j] = 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < i + 1; j++)
			scanf("%d", &box[i][j]);

	input[0][0] = box[0][0];
	for (i = 1; i < n; i++)
		for (j = 0; j < i + 1; j++) {
			if (j - 1 >= 0 && j <= i - 1)
				if (input[i - 1][j - 1] < input[i - 1][j])
					input[i][j] += input[i - 1][j];
				else
					input[i][j] += input[i - 1][j - 1];
			else if (j - 1 >= 0)
				input[i][j] += input[i - 1][j - 1];
			else if (j <= i - 1)
				input[i][j] += input[i - 1][j];
			input[i][j] += box[i][j];
		}
	for (i = 0; i < n; i++)
		if (input[n - 1][i] > max)
			max = input[n - 1][i];
	printf("%d\n", max);
}