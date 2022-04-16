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

