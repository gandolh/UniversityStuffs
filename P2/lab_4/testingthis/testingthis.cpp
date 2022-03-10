#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)


int main()
{
	int** a, n, m, i, j, * freq, length = 1;
	scanf("%d %d", &m, &n);
	a = (int**)malloc(m * sizeof(int*));
	for (i = 0; i < n; i++)
	{
		length = 0;
		freq = (int*)calloc(100, sizeof(int));
		a[i] = (int*)malloc((length + 1) * sizeof(int));
		for (j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			if (freq[x] == 0) {
				//printf("%d", x);
				freq[x] = 1;

				a[i] = (int*)realloc(a[i], (length + 1) * sizeof(int));
				a[i][length] = x;
				length++;

			}
			a[i][length] = NULL;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < a[i][j] != NULL; j++)
			printf("%d;", a[i][j]);
		printf("\n");
	}
	return 0;
}