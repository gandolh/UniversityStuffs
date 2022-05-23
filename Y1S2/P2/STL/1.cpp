```#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <set>
#pragma warning(disable : 4996)
using namespace std;

class Patinoar {
private:
    string nume;
    int varsta;
    vector<string> competitii;
public:
    Patinoar();
    Patinoar(const Patinoar&);
    Patinoar(string, int, vector<string>&);
    ~Patinoar();
    void afisare();
    friend void showInRange(int , int , vector<Patinoar>&);
    friend set<string> showUniqueCompetitions(vector<Patinoar>&);
    friend bool comparePatinoare(Patinoar& , Patinoar& );
    friend void showPatinoari(vector<Patinoar>&,set<string>);
};


Patinoar::Patinoar() {
    nume = "";
    varsta = 0;
    for (int i = 0; i < 255; i++)
        competitii[i] = "";
}

Patinoar::Patinoar(const Patinoar& patinoar) {
    this->nume = patinoar.nume;
    this->varsta = patinoar.varsta;
    this->competitii = patinoar.competitii;
}

Patinoar::Patinoar(string nume, int varsta, vector<string>& competitii) {
    this->nume = nume;
    this->varsta = varsta;
    this->competitii = competitii;
}

Patinoar::~Patinoar() {}


void Patinoar::afisare() {
    cout << nume << " " << varsta << " ";
    for (int i = 0; i< competitii.size(); i++)
        cout << competitii[i]<<" ";
    cout << endl;
}

void showInRange(int st, int dr, vector<Patinoar>& patinoari) {
    for (Patinoar x : patinoari) {
        if(x.varsta >= st &&  x.varsta <= dr)
        x.afisare();

    }
}

set<string> showUniqueCompetitions(vector<Patinoar>& patinoari) {
    set<string> uniqueCompetitions;
 
    for (Patinoar x : patinoari) {
        for (int i = 0; i < x.competitii.size(); i++)
            uniqueCompetitions.insert(x.competitii[i]);
    }
    for (string x : uniqueCompetitions)
        cout << x<<" ";

    return uniqueCompetitions;
}


bool comparePatinoare(Patinoar& p1, Patinoar& p2)
{
    if (p1.varsta < p2.varsta)
        return false;
    if (p1.varsta == p2.varsta)
        if (p1.competitii.size() < p2.competitii.size())
            return false;
    return true;
}


void showPatinoari(vector<Patinoar>& patinoari, set<string> uniqueCompetitions) {
    for (string uniqueCompetition : uniqueCompetitions) {
        cout << uniqueCompetition << ": ";
        cout << endl;
        for (Patinoar patinoar : patinoari) {
            for (string competitie : patinoar.competitii) {
                if (competitie == uniqueCompetition)
                    patinoar.afisare();
            }
        }
        cout << endl;
    }
}

    
int main()
{
    vector<Patinoar> patinoari;
    patinoari.reserve(100);
    int n;
    char input[255];
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++) {
        cin.getline(input,255);
        char* p = strtok(input, ";");
        string nume;
        nume = p;
        int varsta;
        char varsta_str[255];
        p = strtok(NULL, ";");
        strcpy(varsta_str, p);
        varsta = atoi(varsta_str);
        vector<string> competitii;
        int k = -1;
        p = strtok(NULL, ";");
        p = strtok(p, ",");
        while (p) {
            competitii.push_back(p);
            p = strtok(NULL, ",");
        }
      
        Patinoar pa = Patinoar(nume, varsta, competitii);
        patinoari.push_back(pa);
    }
    int st, dr;
    cin >> st >> dr;
    cout << "afisare in interval varsta" << endl;
    showInRange(st,dr,patinoari);
    cout << "Competitii distincte:" << endl;
    set<string> uniqueCompetitions = showUniqueCompetitions(patinoari);
    cout << endl;
    sort(patinoari.begin(),patinoari.end(),comparePatinoare);
    cout << "Elemente sortate" << endl;
    for (Patinoar x : patinoari)
        x.afisare();
    cout << "Afisare patinoar:" << endl;
    showPatinoari(patinoari,uniqueCompetitions);
    

}
```