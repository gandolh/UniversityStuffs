#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int** eliminare(int** mat, int n, int m, int* lungimiLinii) {
	int** newMat;
	int i, j;
	newMat = (int**)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		int k = -1;
		newMat[i] = (int*)malloc(sizeof(int));
		int* vfrec = (int*)calloc(100, sizeof(int));
		for (j = 0; j < m; j++) {
			if (vfrec[mat[i][j]] == 0) {
				k++;
				newMat[i] = (int*)realloc(newMat[i], (k + 2) * sizeof(int));
				vfrec[mat[i][j]] = 1;
				newMat[i][k] = mat[i][j];
			}
		}
		lungimiLinii[i] = k;
	}
	return newMat;
}
int main() {

	int** mat, ** newMat, * lungimi;
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	mat = (int**)malloc(n * sizeof(int*));
	lungimi = (int*)malloc(m * sizeof(int));
	for (i = 0; i < n; i++) {
		mat[i] = (int*)malloc(m * sizeof(int));
		for (j = 0; j < m; j++)
			scanf("%d", &mat[i][j]);
	}
	newMat = eliminare(mat, n, m, lungimi);
	for (i = 0; i < n; i++) {
		for (j = 0; j <= lungimi[i]; j++) {
			printf("%d;", newMat[i][j]);
		}
		printf("\n");
	}
}