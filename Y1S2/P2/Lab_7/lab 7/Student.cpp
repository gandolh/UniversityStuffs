class Student {
private:
	char* nume;
	int an;
	bool sex;
public:
	Student();
	Student(char*, int, bool);
	Student(const Student&);
	~Student();
protected:
};

Student::Student() {}
Student::Student(char* Nume, int An, bool Sex) :nume(Nume), an(An), sex(Sex) {}
Student::Student(const Student& s) : nume(s.nume), an(s.an), sex(s.sex) {}
Student::~Student() {
	delete[] nume;
}