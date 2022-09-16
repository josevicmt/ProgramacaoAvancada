#ifndef _POLY_H_
#define _POLY_H_


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Poly
{
    private:
        // Grau do polinomio -> polinomio vazio recebe grau < 0, dimensao dos coeficientes e grau+1
        int grau;
        // Ponteiro de Double para representar os coeficientes, coeficente de posicao grau nunca deve ser 0
        double *coefs;//coeficientes
        /*Funcoes adicionadas ao private para evitar manipulacao sem validacoes*/
        // Para alocacao de memoria (grau+1 ou 0) para um novo Poly
        void cria(int g);
        // Copia um Poly para um outro de mesma dimensao
        void copia(const Poly &P);
    public:
        /*Funcoes*/
        // Faz grau receber 0, desaloca memoria do array de coeficientes e faz apontar pra nullptr (funcao extra)
        void destroi();
        // Apaga Poly anterior e faz ele ter nova dimensao
        inline void recriar(int novoGrau){destroi(); cria(novoGrau);};
        // Altera um coeficiente
        void setCoef(int indice, double valor);
        // Retorna o grau do polinomio
        int getGrau() const;
        // Retorna um coeficiente
        double getCoef(int indice) const;
        // Retorna o valor do polinomio para um dado x
        double getValor(double x) const;
        // Retorna true se grau < 0
        bool empty() const;
        // Retorna true se grau = 0 e coefs = nullptr
        bool isZero() const;

        /*Sobrecarga*/
        Poly operator=(const Poly &P) const;
        double operator[](int indice) const;
        double operator()(double valor) const;
        Poly operator+(const Poly &P) const;
        Poly operator-(const Poly &P) const;
        Poly operator-() const;
        Poly operator*(const Poly &P) const;
        Poly operator/(const Poly &P) const;
        Poly operator%(const Poly &P) const;


        /*Leitura e Escrita*/
        friend ostream &operator<<(ostream &X, const Poly &P);
        friend istream &operator>>(istream &X, Poly &P);
        bool salvar(const string &caminho) const;
        bool ler(const string &caminho) const;

        /*Construtores e Destrutores*/
        // Default
        inline Poly(){cria(-1);};
        // Construtor especifico nao habilitado para conversao de tipo
        inline explicit Poly(int novoGrau){cria(novoGrau);};
        // Construtor especifico habilitado para conversao de tipo, polinomio de grau 0 com unico coeficiente sendo o valor que e convertido
        //jinline Poly(int coefGrauZero){cria(0);};
        // construtor por copia
        inline Poly(const Poly &P){cria(P.getGrau()); copia(P);};
        Poly(Poly &&P);
        // destrutor
        inline ~Poly(){destroi();};
};

#endif // _POLY_H_
