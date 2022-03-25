#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Produs {
	int cod;
	int status; // 0 - new ; 1 - modified; 2 - deleted
}Produs;

typedef struct Node {
	Produs produs;
	struct Node* prev;
	struct Node* next;
}Node;

typedef struct List {
	Node* head;
}List;

void print(List l, int printType) {
	/*
	 printType
	 0  - ALL
	 1 - newAdded
	 2 - modified
	 3 - deleted
	*/
	Node* current = l.head;
	switch (printType) {
	case 0: {
		printf("ALL:");
		while (current) {
			printf("cod: %d status: %d | ", current->produs.cod, current->produs.status);
			current = current->next;
		}
		printf("\n");
		break;
	}
	case 1: {
		printf("new added:\n");
		while (current) {
			if (current->produs.status == 0)
				printf("cod: %d | ", current->produs.cod);
			current = current->next;
		}
		printf("\n");
		break;
	}
	case 2: {
		printf("modified:\n");
		while (current) {
			if (current->produs.status == 1)
				printf("cod: %d | ", current->produs.cod);
			current = current->next;
		}
		printf("\n");
		break;
	}
	case 3: {
		printf("deleted:\n");
		while (current) {
			if (current->produs.status == 2)
				printf("cod: %d | ", current->produs.cod);
			current = current->next;
		}
		printf("\n");
		break;
	}

	}


}


void InsertFront(List* l, Produs produs) {

	Node* newNode = malloc(sizeof(Node));
	newNode->produs = produs;
	newNode->next = l->head;
	newNode->prev = NULL;
	l->head = newNode;
}

void InsertLast(List* l, Produs produs) {
	Node* newNode = malloc(sizeof(Node));
	Node* last = malloc(sizeof(Node));
	last = l->head;
	while (last && last->next) {
		last = last->next;
	}
	newNode->produs = produs;
	newNode->next = NULL;

	newNode->prev = last;
	if (last != NULL) {
		last->next = newNode;
		last = last->next;
	}
	else {
		last = newNode;
		l->head = newNode;
	}
}

void insertBefore(List* l, Node* ref, Produs produs) {

	Node* newNode = malloc(sizeof(Node));
	newNode->produs = ref->produs;
	newNode->next = ref->next;
	newNode->prev = ref;
	ref->next = newNode;
	ref->produs = produs;
	ref = ref->next;
}

void insertAfter(List* l, Node* ref, Produs produs) {

	Node* newNode = malloc(sizeof(Node));
	newNode->produs = produs;
	newNode->next = ref->next;
	newNode->prev = ref;
	ref->next = newNode;
	ref = ref->next;
}


void debug_insert(List* l, int cod) {

	Node* current = l->head;
	while (current) {
		if (current->produs.cod == cod)break;
		current = current->next;
	}
	Produs produs_temp;
	produs_temp.cod = 12;
	produs_temp.status = 0;
	InsertFront(l, produs_temp);
	InsertLast(l, produs_temp);
	insertBefore(l, current, produs_temp);
	current = current->next;
	produs_temp.cod = 165;
	insertBefore(l, current, produs_temp);
	current = current->next;
	produs_temp.cod = 99;
	insertBefore(l, current, produs_temp);
	current = current->next;
	produs_temp.cod = 12;
	insertAfter(l, current, produs_temp);
	produs_temp.cod = 165;
	insertAfter(l, current, produs_temp);
	produs_temp.cod = 99;
	insertAfter(l, current, produs_temp);
}

void insert(List* l, Produs produs) {
	int inserted = 0;
	for (Node* current = l->head; current; current = current->next) {
		if (current->produs.cod > produs.cod) {
			insertBefore(l, current, produs);
			inserted = 1;
			break;
		}
	}
	if (inserted == 0)
		InsertLast(l, produs);
}

void removeWithCod(List* l, int cod) {
	Node* current = l->head;
	while (current) {
		if (current->produs.cod == cod) {
			//if (current != l->head)
			//	current->prev->next = current->next;
			//else
			//	l->head = current->next;

			//free(current);
			//break;
			current->produs.status = 2;
		}
		current = current->next;
	}
}

void UpdateWithCod(List* l, int cod, Produs newProduct) {
	Node* current = l->head;
	while (current) {
		if (current->produs.cod == cod) {
			current->produs = newProduct;
			current->produs.status = 1;
			break;
		}
		current = current->next;
	}
}

int main() {
	List l;
	int n, x, i, cod;
	Produs produs_temp;
	produs_temp.status = 0;
	l.head = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		produs_temp.cod = x;
		//InsertFront(&l, produs_temp);
		//InsertLast(&l, produs_temp);
		insert(&l, produs_temp);
	}

	scanf("%d", &cod);
	//debug_insert(&l, cod);
	removeWithCod(&l, cod);
	produs_temp.cod = 121;
	UpdateWithCod(&l, cod + 1, produs_temp);
	//	print(l, 0);
	//	print(l, 1);
	//	print(l, 2);
	//	print(l, 3);
}