#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

# define TRUE 1
# define FALSE 0
#define MAX_STACK_SIZE 50

typedef char element;
typedef struct {
	int top;
	element data[MAX_STACK_SIZE];
}StackType;

void init_stack(StackType* s)
{
	s->top = -1;
}

int is_full(StackType* s)
{
	return s->top == MAX_STACK_SIZE;
}

int is_empty(StackType* s)
{
	return s->top == -1;
}

void push(StackType* s, element item)
{
	if (is_full(s))
		return;
	s->data[++s->top] = item;
}

element pop(StackType* s)
{
	if (is_empty(s))
		return -1;
	return s->data[s->top--];
}

element peek(StackType* s)
{
	if (is_empty(s))
		return -1;
	return s->data[s->top];

}
int is_right(StackType* s, char *q)
{
	while (*q) {
		if (*q == '(')
			push(s, *q);
		else {//*q == ')'
			if (peek(s) == ')' || peek(s) == -1)
				return FALSE;
			pop(s);
		}
		q++;
	}
	if (is_empty(s))
		return TRUE;
	else
		return FALSE;
}

int main()
{
	int i, j = 0, n;
	char *w;
	int* ans;
	StackType s;

	w = (char*)malloc(sizeof(char) * MAX_STACK_SIZE);
	scanf("%d", &n);
	ans = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		ans[i] = 0;
	for (i = 0; i < n; i++) {
		init_stack(&s);
		scanf("%s", w);
		if (is_right(&s, w))
			ans[j++] = TRUE;
		else
			ans[j++] = FALSE;
	}
	for (i = 0; i < n; i++)
		if (ans[i] == TRUE)
			printf("YES\n");
		else
			printf("NO\n");
}