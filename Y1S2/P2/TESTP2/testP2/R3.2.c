#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX_SIZE 256

typedef struct listaIndexi {
	int length;
	int* arr;
}listaIndexi;

void initListaIndexi(listaIndexi *vfrec) {
	for (int i = 0; i < 256; i++) {
		vfrec[i].length = -1;
		vfrec[i].arr = (int*)malloc(sizeof(int) * MAX_SIZE);
	}
}


listaIndexi* getListaIndexi(int *n) {
	listaIndexi* vfrec= (listaIndexi*)malloc(256*sizeof(listaIndexi)); //ASCII number of chars
	initListaIndexi(vfrec);
	scanf("%d", n);
	//printf("%d",*n);
	char* str = (char*)malloc(sizeof(char) * MAX_SIZE);
	for (int i = 0; i < *n; i++) {
		scanf("%s",str);
		for (int j = 0; str[j]; j++)
			if(vfrec[str[j]].arr[vfrec[str[j]].length] != i+1)
			vfrec[str[j]].arr[++vfrec[str[j]].length] = i+1;
	}
	return vfrec;
}

void afisare(listaIndexi* vfrec) {
	for (int i = 'a'; i <= 'z'; i++) {
		if (vfrec[i].length != -1) {
			printf("%c-", i);
			for (int j = 0; j <= vfrec[i].length; j++)
				printf("%d,", vfrec[i].arr[j]);
			printf("\n");
		}

	}

	for (int i = 'A'; i <= 'Z'; i++) {
		if (vfrec[i].length != -1) {
			printf("%c-", i);
			for (int j = 0; j <= vfrec[i].length; j++)
				printf("%d,", vfrec[i].arr[j]);
			printf("\n");
		}

	}


}



int main()
{
	int n;
	listaIndexi* vfrec = getListaIndexi(&n);
	afisare(vfrec);
	return 0;

}