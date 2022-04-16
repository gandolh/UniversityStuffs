#include <iostream>
#include <string>
using namespace std;

class Emisiune {
public:
    int durata;
    char* nume;
    void afisare() const {
        printf("Emisiune: %s; Durata: %d\n", nume, durata);
    }
    Emisiune(int durata, char* nume)
        :durata(durata) {
        this->nume = new char[256];
        this->nume = nume;
    }
    ~Emisiune() {
        delete[] nume;
    }
};
Emisiune* citire() {
    int durata;
    char* nume = new char[256];
    cin.getline(nume, 256);
    cin >> durata;
    Emisiune* e = new Emisiune(durata, nume);
    //delete[] nume;

    return e;
}
int main() {
    int n, x; //numarul de emisiuni
    cin >> n;
    Emisiune** emisiuni = new Emisiune*;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        Emisiune* e = citire();
        emisiuni[i] = e;
    }
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (emisiuni[i]->durata > x)
            printf("Emisiune: %s; Durata: %d\n", emisiuni[i]->nume, emisiuni[i]->durata);
    }
}