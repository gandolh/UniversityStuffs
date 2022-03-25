#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define URGENT 0
#define ORDINAR 1
typedef struct Mesaj {
	int prioritate; //0 -urgent; 1-ordinar
	char destinatar[50];
	char continut[255];
}Mesaj;

typedef struct Node {
	Mesaj mesaj;
	struct Node* next;
}Node;

typedef struct List {
	Node* head;
}List;

List Initializare() {
	List l;
	l.head = malloc(sizeof(Node));
	l.head = NULL;
	return l;
}

void insertFirst(List* l, Mesaj mesaj) {
	Node* nNode = malloc(sizeof(Node));
	nNode->mesaj = mesaj;
	nNode->next = l->head;
	l->head = nNode; 
}

void insertLast(List* l, Mesaj mesaj) {
	Node* newNode = malloc(sizeof(Node));
	Node* last = malloc(sizeof(Node));
	last = l->head;
	while (last && last->next) {
		last = last->next;
	}
	newNode->mesaj = mesaj;
	newNode->next = NULL;

	if (last != NULL) {
		last->next = newNode;
		last = last->next;
	}
	else {
		last = newNode;
		l->head = newNode;
	}
}

void insertBefore(List* l, Node* ref, Mesaj mesaj) {

	Node* newNode = malloc(sizeof(Node));
	newNode->mesaj = ref->mesaj;
	newNode->next = ref->next;
	ref->next = newNode;
	ref->mesaj = mesaj;
	ref = ref->next;
}




void insertOrdinary(List* l, Mesaj mesaj) {
	Node* nNode = malloc(sizeof(Node));
	Node* current = malloc(sizeof(Node));
	int inserted = 0;
	current = l->head;
	nNode->mesaj = mesaj;
	while (current && current->mesaj.prioritate==URGENT) {
		current = current->next;
	}
	while (current) {
		if (strcmp(mesaj.destinatar,current->mesaj.destinatar)>0) {
			inserted = 1;
			insertBefore(l, current, mesaj);
			break;
		}
		current = current->next;
	}
	
	if (inserted == 0)insertLast(l,mesaj);
}

void trimitere_mesaj(List *l,int prioritate, char* destinatar, char* continut) {
	Mesaj mesaj_curent;
	mesaj_curent.prioritate = prioritate;
	strcpy(mesaj_curent.destinatar, destinatar);
	strcpy(mesaj_curent.continut , continut);
	if (prioritate == 0)insertFirst(l, mesaj_curent);
	else insertOrdinary(l,mesaj_curent);
}

void primire_mesaj(List l,char* destinatar) {
	Node* current = l.head;
	while (current) {
		if (strcmp(current->mesaj.destinatar, destinatar) == 0) {
			printf("%d %s %s\n", current->mesaj.prioritate, current->mesaj.destinatar, current->mesaj.continut);
			break;
		}
		current = current->next;
	}
}

void afisare(List l) {
	Node* current = l.head;
	while (current && current->mesaj.prioritate == URGENT) {
		current = current->next;
	}
	while (current) {
		printf("%d %s %s\n", current->mesaj.prioritate, current->mesaj.destinatar, current->mesaj.continut);
		current = current->next;
	}
}

void printAll(List l) {
	Node* current = l.head;
	while (current) {
		printf("%d %s %s\n", current->mesaj.prioritate, current->mesaj.destinatar, current->mesaj.continut);
		current = current->next;
	}

}
int main() {
	Mesaj Mesaj_temp;
	List l = Initializare();
	trimitere_mesaj(&l,URGENT,"Gusi","Continut exclusiv");
	trimitere_mesaj(&l,URGENT, "Gusi", "encrypted with sha256");
	trimitere_mesaj(&l,URGENT, "Alke", "please,end this..");
	trimitere_mesaj(&l,ORDINAR, "Gusi", "Mai bine dadeam la litere");
	trimitere_mesaj(&l,ORDINAR, "Gusi", "Ce fac cu viata mea?");
	trimitere_mesaj(&l,ORDINAR, "Alexander the great", "ARDEEE MACEDONIA");
	trimitere_mesaj(&l,ORDINAR, "BAlexander the great", "AAAAAAA?");
	char destinatar[50] = "Gusi";
	//primire_mesaj(l, destinatar);
	//afisare(l);
	//printAll(l);






}