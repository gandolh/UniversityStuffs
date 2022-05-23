typedef struct Autovehicul {
    int id;
    char* marca,
        * tipAuto; // din tipAuto[]
    int an;
    char* nrAuto;
    double capacitateMotor;
    int numarLocuri;
    struct Autovehicul* next;
}Autovehicul;

typedef struct Flota {
    char* denumire;
    char* numeReprezentant;
    int nrAutovehicule;
    Autovehicul* autos_head; //lista

} Flota;
