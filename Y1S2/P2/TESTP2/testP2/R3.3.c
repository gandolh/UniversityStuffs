#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


float** fct(float** mat, int n) {
	
	float** new_mat = (float**)malloc(sizeof(float*) * (n + 1));
	for (int i = 0; i < n; i++) {
		new_mat[i] = (float*)malloc(sizeof(float) * (n + 1));
		for (int j = 1; j < n; j+=	2) {
			new_mat[i][j / 2] = mat[i][j];
		}
	}
	return new_mat;
}



float** citire(int *n ) {
	scanf("%d", n);
	float** mat = (float**)malloc(sizeof(float*) * ((*n)+1)); 
	for (int i = 0; i < *n; i++) {
		mat[i] = (float*)malloc(sizeof(float) * ((*n)+1));
		for (int j = 0; j < *n; j++) {
			scanf("%f", &mat[i][j]);

		}
	}
	return mat;

}
void afisare(float **mat, int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%.2f;",mat[i][j]);
		printf("\n");
	}
}
int main()
{
	int n;
	float** mat = citire(&n);
	mat = fct(mat,n);
	afisare(mat,n,n/2);
	return 0;
}