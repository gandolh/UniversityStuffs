#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int* citeste(int* n) {
	int i, * t_copy, * t;
	scanf("%d", n);
	t = (int*)malloc((*n) * sizeof(n));
	t_copy = t;
	for (i = 0; i < *n; i++) {
		scanf("%d", t_copy);
		t_copy++;
	}
	return t;
}


void afiseaza(int n, int* t) {
	int i, * t_copy = t;
	for (i = 0; i < n; i++) {
		printf("%d;", *(t_copy++));
	}
	printf("\n");
}

void afiseaza_invers(int* tab, int n) {
	int* p = tab + (n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d;", *(p--));
	}
	printf("\n");
}

void isMedieAritmetica(int prev, int current, int next) {
	if ((prev + next) * 1.0 / 2 == current)
		return 1;
	return 0;
}

void afiseaza_elem_crt(int n, int* t, int (*fct_crt) (int, int, int)) {
	int i, * t_copy = ++t, ok = 0;

	for (i = 1; i < n - 1; i++) {
		//printf("%d %d %d\n ", *(t_copy - 1), *(t_copy + 1), (*(t_copy - 1) + *(t_copy + 1)) / 2);
		if ((*(t_copy - 1) + *(t_copy + 1)) * 1.0 / 2 == *(t_copy) * 1.0)
		{
			printf("%d;", *t_copy);
			ok = 1;
		}
		t_copy++;
	}
	if (ok)
		printf("\n");
}

int main() {
	int n, * t, i;
	t = citeste(&n);
	afiseaza(n, t);
	afiseaza_elem_crt(n, t, isMedieAritmetica);
	afiseaza_invers(t, n);
	free(t);
}