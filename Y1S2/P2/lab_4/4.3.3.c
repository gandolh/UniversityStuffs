#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int palindrom(int nr) {
	int inv = 0, nr_copy = nr;
	while (nr_copy) {
		inv = inv * 10 + nr_copy % 10;
		nr_copy /= 10;
	}
	return inv == nr;
}
int munte(int nr) {
	int stage = 0;

	if (nr % 10 > nr / 10 % 10)return 0;


	while (nr) {
		if (nr % 10 > nr / 10 % 10 && stage == 0) {
			stage = 1;
		}
		else if (stage == 1) {
			if (nr % 10 < nr / 10 % 10 && stage == 1) {
				return 0;
			}
			else {
				stage = 2;
			}
		}
		nr /= 10;
	}
	if (stage == 2)
		return 1;
	return 0;
}
int cautare(int* t, int n, int (*criteriu)(int)) {
	int i, index = -1;
	for (i = 0; i < n; i++)
		if (criteriu(t[i]) == 1)
			index = i;
	return index;
}

int main() {
	int n, i, * t;
	scanf("%d", &n);
	t = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &t[i]);
	}
	printf("%d\n%d", cautare(t, n, palindrom),
		cautare(t, n, munte));
}