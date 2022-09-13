#include <iostream>

class Poly
{
    private:
        // Grau do polinomio -> polinomio vazio recebe grau < 0
        int grau;
        // Ponteiro de Double para representar os coeficientes, coeficente de posicao grau nunca deve ser 0
        double *coefs;//coeficientes
        // Para alocacao de memoria (grau+1 ou 0) para um novo Poly
        void cria(int g);
        void copia(const Poly &P);//para realocar memoria em construtores por copia

    public:
        /*Funcoes*/
        // Faz grau receber 0, desaloca memoria do array de coeficientes e faz apontar pra nullptr (funcao extra)
        void destroi();
        // Apaga Poly anterior e faz ele ter nova dimensao
        inline void recriar(int novoGrau){destroi(); criar(novoGrau);};
        void setCoef(int indice, double valor);
        int getGrau();
        double getCoef(int indice);
        double getValor(double x);
        bool empty();
        bool isZero();

        /*Construtores e Destrutores*/
        Poly(){cria(-1);};
        explicit Poly(int novoGrau){cria(novoGrau);};
        inline Poly(const Poly &P){cria(P.grau); copia(P.coefs);};
        inline ~Poly(){destroi();};

};  