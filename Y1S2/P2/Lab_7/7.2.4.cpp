#include <iostream>
#include <string>
using namespace std;

class Emisiune {
public:
    int durata;
    char* nume;
    void afisare() const {
        printf("Emisiune: %s; Durata: %d\n", nume,durata);
    }
    Emisiune(int durata, char* nume)
        :durata(durata){
        this->nume = new char[256];
        this->nume = nume;
    }
    ~Emisiune(){
        delete[] nume;
    }
};
Emisiune* citire() {
    int durata;
    char* nume = new char[256];
    cin.getline(nume,256);
    cin >> durata;
    Emisiune* e = new Emisiune(durata,nume);
    //delete[] nume;

    return e;
}
int main() {
    int n; //numarul de emisiuni
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin.get();
        Emisiune* e = citire();
        e->afisare();
        delete e;
    }
}