#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
class Carte {
	char* titlu;
	char* autor;
public:
	Carte();
	Carte(char*,char*);
	Carte(const Carte&);
	~Carte();
	char* getTitlu() const;
};

char* Carte::getTitlu() const {
	return this->titlu;
}

Carte::Carte(char * titlu, char *autor) {
	this->titlu = new char[255];
	this->autor = new char[255];
	strcpy(this->titlu,titlu);
	strcpy(this->autor,autor);
}

Carte::~Carte() {
	delete[] titlu;
	delete[] autor;
}
class Persoana {
	char* nume;
public:
	Persoana();
	Persoana(char*);
	Persoana(const Persoana&);
	~Persoana();
	char* scrieReview(const Carte& c, int numarZile);
};
char* Persoana::scrieReview(const Carte& c, int numarZile) {
	char* review = new char[255];
	strcpy(review, "Reviewul pentru cartrea ");
	strcat(review, c.getTitlu());
	strcat(review, " trebuie terminat in doua saptamani");

	return review;

}

Persoana::Persoana(char* nume) {
	this->nume = new char[255];
	strcpy(this->nume,nume);
}
Persoana::~Persoana() {
	delete[]nume;
}
int main() {
	char* pers_nume = new char[255];
	strcpy(pers_nume, "Grig");
	Persoana* p = new Persoana(pers_nume);
	char* nume_carte = new char[255];
	cin.getline(nume_carte,255);
	Carte* c1 = new Carte(nume_carte, nume_carte);
	cin.getline(nume_carte,255);
	Carte* c2 = new Carte(nume_carte, nume_carte);
	cin.getline(nume_carte,255);
	Carte* c3 = new Carte(nume_carte, nume_carte);
	int n;
	char* result = p->scrieReview(*c1, 2);
	cout << result;
	delete c1, c2, c3,p;
}