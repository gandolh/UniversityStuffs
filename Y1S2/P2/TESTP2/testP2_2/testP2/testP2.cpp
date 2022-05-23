
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
class Club {
private:
    char* nume;
    int an;
    char** numeMembri;
public:
    Club();
    Club(const Club& );
    Club(const char*, int, const char*);
    ~Club();
    friend std::ostream& operator <<(std::ostream&,const Club&);
    friend bool operator <(const Club&, const Club&);
    void operator +=(const char*);
    int GetNumarMembri();
    friend void ShowByYear(Club[],int);
};

Club::Club() {
    nume = new char[10];
    strcpy(nume, "undefined");
    numeMembri = new char* [2];
    numeMembri[0] = new char[10];
    strcpy(numeMembri[0],"undefined");
    numeMembri[1] = NULL;
    an = 0;
}

Club::Club(const Club&) {

}


Club::Club(const char* nume,int an, const char* numeMembri) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->an = an;
    char* temporaryStr= new char[strlen(numeMembri)+1];
    strcpy(temporaryStr,numeMembri);
    int numarMembri = 0;
    char* p = strtok(temporaryStr,",");
    while(p){
        numarMembri++;
        p = strtok(NULL, ",");
    }
   // std::cout << numarMembri;
    this->numeMembri = new char* [numarMembri];

     numarMembri = 0;
    strcpy(temporaryStr, numeMembri);
     p = strtok(temporaryStr, ",");
    while (p) {
        this->numeMembri[numarMembri] = new char[strlen(p)+2];
        strcpy(this->numeMembri[numarMembri],p);
        numarMembri++;
        p = strtok(NULL, ",");
    }
    this->numeMembri[numarMembri] = NULL;
    //char* p = strtok(numeMembri,",");
   // this->numeMembri = new char* [ + 1];
}

Club::~Club() {
    // o sa eliberez eu memoria candva

   /* if (this->nume != NULL)
        delete this->nume;*/

   /* if (this->numeMembri != NULL) {
        for (int i = 0; this->numeMembri[i]; i++)
            delete[] this->numeMembri[i];
        delete[] this->numeMembri;
    }*/

}


int Club::GetNumarMembri() {
    int nr = 0;
    for (int i = 0; this->numeMembri[i]; i++)
        nr++;
    return nr;
}

void Club::operator+=(const char* nouMembru) {
    int size = this->GetNumarMembri();
  
    char** new_numeMembri= new char*[size+1];
    int i;
    for (i = 0; numeMembri[i]; i++) {
        new_numeMembri[i] = new char[strlen(numeMembri[i])+1];
        strcpy(new_numeMembri[i],numeMembri[i]);
    }

    new_numeMembri[i] = new char[strlen(nouMembru) + 1];
    strcpy(new_numeMembri[i], nouMembru);
    new_numeMembri[++i] = NULL;
    
    //char** old_NumeMembri = numeMembri;
    this->numeMembri = new_numeMembri;
    //delete[] old_NumeMembri;

}

bool operator <( Club& c1 ,  Club& c2) {

    return c1.GetNumarMembri() < c2.GetNumarMembri();
}

void ShowByYear(Club cluburi[], int numarCluburi) {
    //for (int i = 0; i < numarCluburi; i++) {
    //    for(int j=i+1;j<numarCluburi;j++)
    //        if (cluburi[i] < cluburi[j]) {
    //            std::swap(cluburi[i],cluburi[j]);
    //        }
    //}
    //std::cout << "afisare pe ani:\n";
    //std::cout << cluburi[0].an<<":";
    //for (int i = 0; i < numarCluburi -1; i++) {
    //    if (cluburi[i].an == cluburi[i + 1].an) {
    //        std::cout << cluburi[i].nume;
    //    }
    //    else {
    //        std::cout << cluburi[i].an << ":" << cluburi[i].nume;
    //    }
    //}
}



std::ostream& operator <<(std::ostream& out, const Club& club) {
    out << club.an << " " << club.nume << std::endl;
    out << "Lista membri:\n";
    for (int i = 0; club.numeMembri[i]; i++)
        out << club.numeMembri[i] << " ";

    out << "\n================\n";
    return out;
}

int main()
{

   /* Club a("Florida",2002,"Alex, Gheorghe, Mihai, Stefan");
    std::cout << a;*/

    Club cluburi[4] = { Club("Florida",2002,"Alex, Gheorghe"), Club("Madagascar",2002,"Teodor, Raluca, Iasmina, Corina")
    ,Club("LASA-MA PAPA LA MARE",2007,"Teo, Ra, Book, Sol") };
    for (int i = 0; i < 2; i++)
        std::cout << cluburi[i];

    std::cout << (cluburi[0] < cluburi[1]);


    char nume1[255], nume2[255], nume3[255];
    std::cout << "\n=======================\n";
    std::cin >> nume1 >> nume2 >> nume3;
    cluburi[0] += nume1;
    cluburi[0] += nume2;
    cluburi[1] += nume3;
    std::cout << "\n\n\n";
    for (int i = 0; i < 2; i++)
        std::cout << cluburi[i];

    std::cout << (cluburi[0] < cluburi[1]);


    //ShowByYear(cluburi,3);
}

