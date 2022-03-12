#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	int** a = malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		a[i] = malloc(m * sizeof(int));
		for (j = 0; j < m; j++)
			a[i][j] = i + j;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d;", a[i][j]);
		printf("\n");
	}
	printf("transpusa\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf("%d;", a[j][i]);
		printf("\n");
	}

}