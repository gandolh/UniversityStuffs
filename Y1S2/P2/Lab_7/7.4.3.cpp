
#include <iostream>
class NrComplex {
public:
    int re, im;
    NrComplex(int a, int b);
    NrComplex(const NrComplex&);
    NrComplex();
    void afisare();
    friend NrComplex inmultire(NrComplex& n1, NrComplex& n2) ;
};
NrComplex::NrComplex(const NrComplex& n) {
    this->re = n.re;
    this->im = n.im;
}
NrComplex::NrComplex() {

}


NrComplex::NrComplex(int a, int b) {
    this->re = a;
    this->im = b;
}
NrComplex inmultire(NrComplex &n1, NrComplex &n2) {
    return NrComplex(
    n1.re* n2.re - n1.im*n2.im,
    n1.re*n2.im + n1.im* n2.re
    );
}

void NrComplex::afisare() {
    std::cout << this->re;
    if (this->im > 0)std::cout << '+';
    std::cout << this->im << 'i';
    std::cout << std::endl;
}
void citire(NrComplex& x) {
    std::cin >> x.re >> x.im;
}
int main() {
    NrComplex a, b;
    citire(a);
    citire(b);
    NrComplex c = inmultire(a, b);
    c.afisare();
}