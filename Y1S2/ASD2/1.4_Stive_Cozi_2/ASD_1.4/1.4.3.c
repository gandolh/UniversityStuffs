#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct stack {
	char arr[256];
	int lastIndex;
}Stack;

typedef struct stackInteger {
	int arr[256];
	int lastIndex;
}StackInteger;
char simboluri[] = "+-*/()";

Stack createStack() {
	Stack s;
	s.lastIndex = -1;
	s.arr[0] = '\0';
	return s;
}

StackInteger createStackInteger() {
	StackInteger s;
	s.lastIndex = -1;
	s.arr[0] = 0;
	return s;
}

int getPrioritate(char c) {
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
}

int main() {
	int i;
	Stack s = createStack();
	char* sirNormal = malloc(sizeof(char) * 255);
	char* polonez = malloc(sizeof(char) * 255);
	int result_index = -1;
	gets(sirNormal);
	for (i = 0; sirNormal[i]; i++) {
		if (sirNormal[i] == ' ')continue;
		if (strchr(simboluri, sirNormal[i]) == 0) {
			//printf("%c", sirNormal[i]);
			polonez[++result_index] = sirNormal[i];
		}
		else if (sirNormal[i] != ')') {
			while (s.lastIndex >= 0 && s.arr[s.lastIndex] != '(' && getPrioritate(sirNormal[i]) <= getPrioritate(s.arr[s.lastIndex])) {
				//printf("%c", s.arr[s.lastIndex]);
				polonez[++result_index] = s.arr[s.lastIndex];
				s.lastIndex--;
			}
			s.arr[++s.lastIndex] = sirNormal[i];
		}
		else {
			while (s.lastIndex >= 0 && s.arr[s.lastIndex] != '(') {
				//printf("%c", s.arr[s.lastIndex]);
				polonez[++result_index] = s.arr[s.lastIndex];
				s.lastIndex--;
			}
			s.lastIndex--;
		}

	}
	while (s.lastIndex >= 0) {
		//printf("%c", s.arr[s.lastIndex]);
		polonez[++result_index] = s.arr[s.lastIndex];
		s.lastIndex--;
	}
	polonez[++result_index] = 0;
	//printf("\n%s", polonez);

	StackInteger s1 = createStackInteger();

	for (i = 0; polonez[i]; i++) {
		if (strchr(simboluri, polonez[i]) == 0) {
			s1.arr[++s1.lastIndex] = polonez[i] - '0';
		}
		else {
			s1.lastIndex--;
			switch (polonez[i]) {
			case '-': {
				s1.arr[s1.lastIndex] = s1.arr[s1.lastIndex] - s1.arr[s1.lastIndex+1];
				break;
			}
			case '+': {
				s1.arr[s1.lastIndex] = s1.arr[s1.lastIndex] + s1.arr[s1.lastIndex + 1];

				break;
			}
			case '*': {
				s1.arr[s1.lastIndex] = s1.arr[s1.lastIndex] * s1.arr[s1.lastIndex + 1];

				break;
			}
			case '/': {
				s1.arr[s1.lastIndex] = s1.arr[s1.lastIndex] / s1.arr[s1.lastIndex + 1];

				break;
			}
			}
		}
	}
	printf("%d", s1.arr[0]);
}