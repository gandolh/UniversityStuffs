#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

typedef struct stack {
	int* arr;
	int last_index;
	int limit;
	int nrElem;
} Stack;

Stack create_stack(int limit) {
	Stack s;
	s.last_index = 0;
	s.arr = malloc(sizeof(int) * limit);
	s.limit = limit - 1;
	s.arr[0] = 0;
	s.nrElem = 0;
	return s;
}

int min(int a, int b) {
	return a < b ? a : b;
}
void push(Stack* s, int x) {
	if (s->last_index <= s->limit) {
		s->arr[s->last_index] = x;
		s->last_index++;
	}
	s->nrElem++;
}
int pop(Stack* s) {
	s->last_index--;
	s->arr[s->last_index] = 0;
	s->nrElem--;
}

void print(Stack* s) {
	int i;
	if (s->nrElem >= s->limit)
		printf("Limit exceeded\n");
	for (i = min(s->last_index, s->limit - 1) - 1; i >= 0; i--) {
		printf("%d\n", s->arr[i]);
	}

}

