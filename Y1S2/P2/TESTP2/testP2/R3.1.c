#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int* citire(int *n) {
	scanf("%d", n);
	//printf("%d",*n);
	int* arr = (int*)malloc(sizeof(int) * ((*n) + 1));
	for (int i = 0; i < *n; i++)
		scanf("%d",&arr[i]);
	return arr;
}

int sumCif(int n , int* arr ) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}


int main()
{
	int n;
	int * arr = citire(&n);
	int sumcif = sumCif(n,arr);
	printf(sumcif % 3 == 0 ? "da" : "nu");
	return 0;

}