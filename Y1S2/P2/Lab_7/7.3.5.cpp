#include <iostream>
#pragma warning(disable:4996)

using namespace std;
class NrComplex {
private:
    static int numereComplexe;
public:
    int re, im;
    NrComplex();
    NrComplex(int a, int b);
    NrComplex(const NrComplex&);
    int getRe() const;
    int getIm() const;
    void afisare() const;
    static NrComplex adunare(NrComplex& n1, NrComplex& n2);
    static void afisareNrInstante();

};

int NrComplex::numereComplexe = 0;
NrComplex::NrComplex() {
    numereComplexe++;

}
NrComplex::NrComplex(int a, int b) {
    this->re = a;
    this->im = b;
    numereComplexe++;
}

NrComplex::NrComplex(const NrComplex& x) {
    this->re = x.re;
    this->im = x.im;
    numereComplexe++;
}
int NrComplex::getRe() const {
    return re;
}
int NrComplex::getIm() const {
    return im;
}

void NrComplex::afisareNrInstante() {
    cout << numereComplexe;
}

NrComplex NrComplex::adunare(NrComplex& n1, NrComplex& n2) {
    auto nrComplex = new NrComplex;
    nrComplex->re = n1.getRe() + n2.getRe();
    nrComplex->im = n1.getIm() + n2.getIm();
    return *nrComplex;
}

void NrComplex::afisare() const {
    cout << this->re;
    if (this->im > 0)cout << '+';
    cout << this->im<<'i';
    cout << endl;
}
void citire(NrComplex& x) {
    int re, im;
    cin >> re >> im;
    x.re = re;
    x.im = im;
}
int main() {
    NrComplex a, b;
    citire(a);
    citire(b);
    NrComplex c = NrComplex::adunare(a, b);
    c.afisare();
    NrComplex::afisareNrInstante();
}