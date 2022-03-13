


#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
void interschimba(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
	//de aici e problema ca suprascrii valoarea
	// in main pointerul e tot pe zona lui de memorie initiala
	//deci trebuie modificata tot aia.
}

void ordoneaza(int* a, int* b, int* c) {
	if (*a > *b)interschimba(a, b);
	if (*a > *c)interschimba(a, c);
	if (*b > *c)interschimba(b, c);

}
int main() {
	int n, * a = malloc(sizeof(int)), * b = malloc(sizeof(int)), * c = malloc(sizeof(int)), i;
	scanf("%d", &n);
	//a = 3, b = 4;
	//interschimba(&a, &b);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", a, b, c);
		ordoneaza(a, b, c);
		printf("(%d, %d, %d)\n", *a, *b, *c);
	}
}

