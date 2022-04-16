#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
class Comisie {
	char* descriere;
	int numarMembri;
	char** numeMembri;
public:
	int lastAddedMember = -1;
	Comisie();
	Comisie(const Comisie&);
	char* getDesc() const;
	int getNrMembri() const;
	char** getNumeMembri() const;
	void setDesc(char* );
	void setNrMembri(int);
	void setNumeMembri(char**);
	~Comisie();
	void afisare();
	void addMembru(char* nume);
};


Comisie::Comisie(const Comisie& com) {
	this->descriere = new char[255];
	strcpy(descriere, com.descriere);
	this->numarMembri = com.numarMembri;
	this->numeMembri = new char*[255];
	for (int i = 0; i < com.numarMembri; i++) {
		this->numeMembri[i] = new char[255];
		strcpy(this->numeMembri[i],  com.numeMembri[i]);
	}
}

Comisie::Comisie() {
	this->descriere = new char[255];
	this->numeMembri = new char* [255];
}
Comisie::~Comisie() {
	delete[] this->descriere;
	for (int i = 0; i < this->numarMembri; i++)
		delete[] this->numeMembri[i];
	delete[] this->numeMembri;

}
void  Comisie::addMembru(char* nume) {
	++this->lastAddedMember;
	this->numeMembri[this->lastAddedMember] = new char[255];
	strcpy(this->numeMembri[this->lastAddedMember],nume);
}
char* Comisie::getDesc() const {
	return this->descriere;
}
int		Comisie::getNrMembri() const {
	return this->numarMembri;
}
char** Comisie::getNumeMembri() const {
	return this->numeMembri;
}
void Comisie::setDesc(char * desc) {
	this->descriere = new char[255];
	strcpy(this->descriere , desc);
}
void Comisie::setNrMembri(int numarMembri) {
	this->numarMembri = numarMembri;
}
void Comisie::setNumeMembri(char ** numeMembri) {
	//delete[] this->numeMembri;
	this->numeMembri = new char* [255];
	for (int i = 0; i < this->numarMembri; i++) {
		delete[] this->numeMembri;
		this->numeMembri[i] = new char[255];
		strcpy(this->numeMembri[i], numeMembri[i]);
	}
}


class Examen {
	char* oraInceput;
	Comisie* comisie;
public:
	Examen();
	Examen(char* ora, Comisie* comisie);
	Examen(const Examen&);
	~Examen();
	void afisare();
	friend int numarare(Examen** exs, int  n, char* numeMembru);
};

Examen::Examen(char* ora, Comisie* comisie) {
	this->oraInceput = new char[255];
	strcpy(oraInceput,ora);
	this->comisie = new Comisie;
	memcpy(this->comisie,comisie,sizeof(Comisie));
}

Examen::~Examen() {
	delete[] this->oraInceput;
}

Examen** citire(int n) {
	int m;
	char* oraInceput = new char[7];
	char* desc = new char[255];
	char* numeMembru = new char[255];
	Examen** ex = new Examen* [n];
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cin.getline(oraInceput, 7);
		cin.getline(desc,255);
		cin >> m;
		Comisie* comisie = new Comisie;
		comisie->setDesc(desc);
		comisie->setNrMembri(m);
		cin.ignore();
		for (int j = 0; j < m; j++) {
			cin.getline(numeMembru,255);
			comisie->addMembru(numeMembru);
		}
		ex[i] = new Examen(oraInceput, comisie);
	}
	return ex;
}
void afisare(Examen** exs, int nrExamene) {

}
int numarare(Examen** exs, int  n, char* numeMembru) {
	int nr = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < exs[i]->comisie->getNrMembri(); j++)
			if (strcmp(exs[i]->comisie->getNumeMembri()[j], numeMembru)==0)
				nr++;
	}
	return nr;
}


int main() {

	int n;
	cin >> n;
	Examen**  ex =citire(n);
	char* nume = new char[255];
	strcpy(nume,"Irina Tia");
	//cout << numarare(ex,n,nume);
	cout << nume;
}