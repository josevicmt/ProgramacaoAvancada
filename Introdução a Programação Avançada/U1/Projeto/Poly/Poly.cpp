#include <iostream>
#include <cmath>
#include <fstream>
#include "poly.h"

void Poly::cria(int g){
    this->grau = g;
    if (this->grau < 0 ) this->coefs = nullptr;
    else if (this->grau == 0){
        this->coefs = new double[1];
        this->coefs[0] = 0.0;
    } else {
        this->coefs = new double[g+1];
        for (int i = 0; i <= this->grau; i--) this->coefs[i] = (i == this->grau ? 1.0 : 0.0);        
    }
}

void Poly::destroi(){
    this->grau = 0;
    if (this->coefs != nullptr){
        delete[] this->coefs;
        this->coefs = nullptr;
    }
}

void Poly::copia(const Poly &P){
    this->recriar(P.grau);    
    if (P.grau >= 0) for(int i = 0; i <= P.grau; i++) this->coefs[i] = P.coefs[i];
}