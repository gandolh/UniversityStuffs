#include <iostream>

using namespace std;

class NrComplex {
    int re, im;
public:
    NrComplex();
    NrComplex(int re,int im);
    NrComplex(const NrComplex&);
    friend NrComplex& operator -(const NrComplex&,const NrComplex&);
    NrComplex& operator -=(const NrComplex&);
    friend ostream& operator << (ostream&, const NrComplex&);
    friend istream& operator >> (istream&, NrComplex&);
    int& operator[](int);

};

NrComplex::NrComplex() {
    this->re = 0;
    this->im = 0;
}
NrComplex::NrComplex(int re, int im) {
    this->re = re;
    this->im = im;
}
NrComplex::NrComplex(const NrComplex& n) {
    this->re = n.re;
    this->im = n.im;
}

NrComplex& operator -(const NrComplex& c1, const NrComplex& c2) {
    return *(new NrComplex(c1.re - c2.re, c1.im - c2.im));
}
NrComplex& NrComplex::operator -=(const NrComplex& c) {
    this->re -= c.re;
    this->im -= c.im;
    return *this;
}

ostream& operator << (ostream& st, const NrComplex& x) {
    st << x.re<<' '<<x.im;
    return st;
}
istream& operator >> (istream& st, NrComplex& x) {
    st >> x.re >> x.im;
    return st;
}

int& NrComplex::operator[](int index) {
    if (index == 1)return this->re;
    else return this->im;
}
int main() {
    NrComplex a;
    cin >> a;
    cout << a[1] << endl << a[2];
}