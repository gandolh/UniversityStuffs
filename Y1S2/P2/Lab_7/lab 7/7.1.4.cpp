#include <iostream>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

class NrComplex {
    int re, im;
public:
    NrComplex();
    NrComplex(int re,int im);
    NrComplex(const NrComplex&);
    NrComplex(char*);
    friend NrComplex& operator -(const NrComplex&,const NrComplex&);
    NrComplex& operator -=(const NrComplex&);
    //friend ostream& operator << (ostream&, const NrComplex&);
    friend istream& operator >> (istream&, NrComplex&);
    int& operator[](int);
    operator char* () const;
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

NrComplex::NrComplex(char* str) {
    this->re = str[0] - '0';
    this->im = str[2] - '0';
}


NrComplex& operator -(const NrComplex& c1, const NrComplex& c2) {
    return *(new NrComplex(c1.re - c2.re, c1.im - c2.im));
}
NrComplex& NrComplex::operator -=(const NrComplex& c) {
    this->re -= c.re;
    this->im -= c.im;
    return *this;
}

//ostream& operator << (ostream& st, const NrComplex& x) {
//    st << x.re<<' '<<x.im;
//    return st;
//}
istream& operator >> (istream& st, NrComplex& x) {
    st >> x.re >> x.im;
    return st;
}

int& NrComplex::operator[](int index) {
    if (index == 1)return this->re;
    else return this->im;
}

void ConvertStrToInt(int x,char* str) {
    std::sprintf(str, "%d", x);
}

NrComplex::operator char* () const {
    char* complexStr = new char[255];
    char* real = new char[10];
    char* imaginary = new char[10];
    strcpy(complexStr,"");
    ConvertStrToInt(this->re, real);
    ConvertStrToInt(this->im, imaginary);
    strcat(complexStr, real);
    if(this->im>0)
    strcat(complexStr, "+");
    strcat(complexStr, imaginary);
    strcat(complexStr, "i");
    free(real);
    free(imaginary);
    return complexStr;
}
int main() {
    NrComplex a;
    cin >> a;
    char x[20];
    scanf("%s", x);
    char* c = a;
    cout << c << endl;
    a = x;
    cout << a << endl;
    return 0;
}