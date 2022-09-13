#include <iostream>

using namespace std;

struct Complexos
{
    double real, imag;
};

void ler(Complexos &);
void imprimir(const Complexos &);
Complexos soma(const Complexos &, const Complexos &);
Complexos produto(const Complexos &, const Complexos &);

int main(){
    Complexos C1, C2;
    cout << "Digite Dois numeros complexos: " << endl;
    ler(C1);
    ler(C2);

    cout << "Seus numeros sao:" << endl;
    imprimir(C1);
    imprimir(C2);

    cout << "A soma eh: " << endl;
    imprimir(soma(C1, C2));
    cout << "O produto eh: " << endl;
    imprimir(produto(C1, C2));

    return 0;
}

void ler(Complexos &C){
    cout << "Real? " << endl;
    cin >> C.real;
    cout << "Imaginario? " << endl;
    cin >> C.imag;
}
void imprimir(const Complexos &C){
    cout << C.real << (C.imag < 0 ? "-" : "+" ) << C.imag << endl;
}
Complexos soma(const Complexos &C1, const Complexos &C2){
    Complexos temp;
    temp.real = C1.real + C2.real;
    temp.imag = C1.imag + C2.imag;
    return temp;
}
Complexos produto(const Complexos &C1, const Complexos &C2){
    //(r1*r2 - i1*i2) + j(r1*i2 + r2*i1)
    Complexos temp;
    temp.real = C1.real * C2.real - C1.imag * C2.imag;
    temp.imag = C1.real * C2.imag + C2.real * C1.imag;
    return temp;
}
