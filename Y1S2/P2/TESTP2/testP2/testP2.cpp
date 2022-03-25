#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)





int** citire(int* n, int* m) {
	scanf("%d %d", n, m);
	int** mat = (int**)malloc(sizeof(int*) * ((*n) + 1));
	for (int i = 0; i < *n; i++) {
		mat[i] = (int*)malloc(sizeof(int) * ((*m) + 1));
		for (int j = 0; j < *m; j++) {
			scanf("%d", &mat[i][j]);

		}
	}
	return mat;

}
void afisare(int** mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d;", mat[i][j]);
		printf("\n");
	}
}



int cifImpare(int n) {
	int sum = 0;
	while (n) {
		if (n % 2 == 1 || n%2== -1)sum++;
		n /= 10;

	}
	return sum;
}
void modifyCifrePare(int** a, int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d;", cifImpare (a[i][j]));
		printf("\n");
	}
};

void modifyABS(int** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d;", a[i][j] > 0 ? a[i][j] : -a[i][j]);
		printf("\n");
	}
};

void modifyMatrix(int** a, int n, int m, void (*fct_p)(int**, int, int)) {
	fct_p(a, n, m);
}

int main()
{
	//printf("%d", -15 % 2);
	int n, m;
	int** mat = citire(&n, &m);
	modifyMatrix(mat, n, m, modifyCifrePare);
	printf("\n");
	modifyMatrix(mat, n, m, modifyABS);
	return 0;
}