#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 1000010

typedef int element;
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

void push(StackType* t, element item)
{
	if (is_full(t))
		return;
	t->data[++t->top] = item;
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

int main()
{
	int i, N;
	int tmp[MAX_STACK_SIZE];
	int F[MAX_STACK_SIZE];
	int NGF[MAX_STACK_SIZE];
	StackType s;

	scanf("%d", &N);

	//tmp = (int*)malloc(sizeof(int) * N);
	//F = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &tmp[i]);
		F[tmp[i]]++;
	}

	init_stack(&s);
	//s.data = (int*)malloc(sizeof(int) * N);
	//NGF = (int*)malloc(sizeof(int) * N);
	for (i = N - 1; i >= 0; i--) {
		int num = tmp[i];
		int height = F[num];
		while (!is_empty(&s)) {
			int topNum = tmp[peek(&s)];
			int topHeight = F[topNum];
			if (topHeight <= height)
				pop(&s);
			else break;
		}
		NGF[i] = -1;
		if (!is_empty(&s)) NGF[i] = tmp[peek(&s)];
		push(&s, i);
	}

	for (i = 0; i < N; i++)
		printf("%d ", NGF[i]);
	printf("\n");
}