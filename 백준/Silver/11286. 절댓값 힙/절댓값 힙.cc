#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_ELEMENT 100000

typedef int element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

int is_empty(HeapType* h)
{
	return h->heap_size == 0;
}

int is_full(HeapType* h)
{
	return h->heap_size == MAX_ELEMENT;
}

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_min_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (abs(item) <= abs(h->heap[i / 2]))) {
		if (abs(item) == abs(h->heap[i / 2]))
			if (item > h->heap[i / 2])
				break;
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	if (is_empty(h))
		return 0;
	item = h->heap[1];//2
	temp = h->heap[(h->heap_size)--];//-2
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child <= h->heap_size)) {
			if (abs(h->heap[child]) > abs(h->heap[child + 1]))
				child++;
			else if (abs(h->heap[child]) == abs(h->heap[child + 1]))
				if (h->heap[child] > h->heap[child + 1])
					child++;
		}
		if (abs(temp) < abs(h->heap[child])) break;
		else if ((abs(temp) == abs(h->heap[child])) && temp < h->heap[child]) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main(void)
{
	int i, N, k;
	HeapType* heap;

	heap = create();
	init(heap);

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &k);
		if (k != 0)
			insert_min_heap(heap, k);
		else
			printf("%d\n", delete_min_heap(heap));
	}
	free(heap);
}