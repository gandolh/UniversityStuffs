#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define fata 0
#define baiat 1

class Student {
private:
	int an;
	char* nume;
public:
	bool gen;
	Student();
	Student(char*, int, bool);
	Student(const Student&);
	~Student();
protected:
};

class OrganizatieStudenteasca {
private:
	int numarMaximStudenti;
	int numarStudenti;
public:
	char* nume;
	int count;
	Student** membri;
	OrganizatieStudenteasca();
	OrganizatieStudenteasca(char*, int , int ,Student**);
	OrganizatieStudenteasca(const OrganizatieStudenteasca&);
	~OrganizatieStudenteasca();
	void addMembru(Student* stud);
	void removeMembru(const Student&);
};

OrganizatieStudenteasca** citire(int n);
void  afisare(OrganizatieStudenteasca**, int n);
void numarare(OrganizatieStudenteasca**, int n);


#define MAX_SIZE 256
using namespace std;
Student::Student() {}
Student::Student(char* Nume, int An, bool Sex) :nume(Nume), an(An), gen(Sex) {}
Student::Student(const Student& s) : nume(s.nume), an(s.an), gen(s.gen) {}
Student::~Student() {
	delete[] nume;
}

OrganizatieStudenteasca::OrganizatieStudenteasca() { }
OrganizatieStudenteasca::OrganizatieStudenteasca(char* nume, int numarMaximStudent, int numarStudenti, Student** membri)
	:nume(nume), numarMaximStudenti(numarMaximStudent), numarStudenti(numarStudenti), membri(membri) {}
OrganizatieStudenteasca::OrganizatieStudenteasca(const OrganizatieStudenteasca& os)
	: nume(os.nume), numarMaximStudenti(os.numarMaximStudenti), numarStudenti(os.numarStudenti), membri(os.membri) {}
OrganizatieStudenteasca::~OrganizatieStudenteasca() {
	delete[] nume;
	//STERGE ARRAY MEMBRII
}

void OrganizatieStudenteasca::addMembru( Student* stud) {

	this->membri[++count] = stud;

}

OrganizatieStudenteasca** citire(int n) {
	OrganizatieStudenteasca** osVector = new OrganizatieStudenteasca*;
	for(int i=0;i<n;i++){
		char* nume = new char[MAX_SIZE];
		int nr_max_studenti, nr_studenti;
		cin.ignore();
		cin.getline(nume,MAX_SIZE);
		cin >> nr_max_studenti >> nr_studenti;
		Student** Membri = new Student*;
		OrganizatieStudenteasca *os = new OrganizatieStudenteasca(nume, nr_max_studenti, nr_studenti, Membri);
		os->count = -1;
		for (int j = 0; j < nr_studenti; j++) {
			char* nume= new char[MAX_SIZE];
			int an;
			char gender;
			cin.ignore();
			cin.getline(nume, MAX_SIZE);
			cin >> an;
			cin >> gender;
			Student* Membru = new Student(nume,an, gender=='F' ? fata: baiat);
			os->addMembru(Membru);
		}
		osVector[i] = os;
	}

	return osVector;
}

void afisare(char* nume) {
	cout << nume;
}

void numarare(OrganizatieStudenteasca** os , int n) {
	int max = -1;
	char* numeOrg = new char[MAX_SIZE];
	for (int i = 0; i < n; i++) {
		int nr = 0;
		OrganizatieStudenteasca organizatie = *os[i];
		for (int j = 0; j < organizatie.count; j++)
			if (organizatie.membri[i]->gen == fata)
				nr++;
		if (nr > max) { max = nr; 
		strcpy(numeOrg, organizatie.nume);
		}
	}
	afisare(numeOrg);
	delete[] numeOrg;
}



int main() {
	int n;
	cin >> n;
	OrganizatieStudenteasca** osVector  = citire(n);
	numarare(osVector, n);
}