#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STACK_SIZE 100000

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		printf("스택 포화 에러\n");
		return;
	}
	else
		s->data[++s->top] = item;
}

element pop(StackType* s)
{
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		return -1;
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		return -1;
	}
	else return s->data[s->top];
}

int main(void)
{
	int i, n, k, sum = 0;
	StackType s;

	init_stack(&s);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k == 0)
			pop(&s);
		else
			push(&s, k);
	}
	while (!is_empty(&s))
		sum += pop(&s);

	printf("%d", sum);
}