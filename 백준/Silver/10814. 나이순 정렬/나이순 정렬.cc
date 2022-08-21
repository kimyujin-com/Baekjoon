#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
	char name[101];
	int age;
	int order;
}Person;

void merge(Person* s, int p, int q, int r)
{
	int i, j, k = 0;
	Person* tmp;
	tmp = (Person*)malloc(sizeof(Person) * (r - p + 1));

	i = p, j = q + 1;
	while (i <= q && j <= r) {
		if (s[i].age == s[j].age) {
			/**if (strcmp(s[i].name, s[j].name) == -1)
				tmp[k++] = s[i++];
			else
				tmp[k++] = s[j++];**/
			if (s[i].order < s[j].order)
				tmp[k++] = s[i++];
			else
				tmp[k++] = s[j++];
		}
		else if (s[i].age < s[j].age)
			tmp[k++] = s[i++];
		else
			tmp[k++] = s[j++];
	}
	while (i <= q)
		tmp[k++] = s[i++];
	while (j <= r)
		tmp[k++] = s[j++];

	for (i = 0; i < k; i++)
		s[p++] = tmp[i];
}

void mergeSort(Person* s, int p, int r)
{
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(s, p, q );
		mergeSort(s, q + 1, r);
		merge(s, p, q, r);
	}
}

void printList(Person* p, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d %s\n", p[i].age, p[i].name);
}

int main(void)
{
	Person* p;
	int i, n;

	scanf("%d", &n);
	p = (Person*)malloc(sizeof(Person) * (n + 1));

	for (i = 0; i < n; i++) {
		scanf("%d", &p[i].age);
		scanf("%s", p[i].name);
		p[i].order = i;
	}

	mergeSort(p, 0, n - 1);
	printList(p, n);
}