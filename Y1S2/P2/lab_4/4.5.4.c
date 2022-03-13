#include <stdio.h>
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

void findMinMax(int n, int* t, int* minn, int* maxx) {
	int i;
	*minn = *t, * maxx = *t;
	int* t_copy = t;
	for (i = 0; i < n; i++, t_copy++) {
		if (*t_copy > *maxx)*maxx = *t_copy;
		if (*t_copy < *minn)*minn = *t_copy;
	}
}

int main() {
	int n, * t, i, minn, maxx;
	t = citeste(&n);
	findMinMax(n, t, &minn, &maxx);
	printf("min=%d\nmax=%d", minn, maxx);
	free(t);
}