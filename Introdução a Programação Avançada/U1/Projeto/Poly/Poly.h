#include <iostream>
#include <string>

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
        inline Poly operator=(const Poly &P){this->recriar(P.getGrau()), this->copia(P)}
        inline Poly operator[](int indice){this->getCoef(indice);};
        inline Poly operator()(double valor){this->getValor(valor);};

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
        inline Poly(int coefGrauZero){cria(0); setCoef(0, coefGrauZero);};
        // construtor por copia
        inline Poly(const Poly &P){cria(P.getGrau); copia(P);};
        // destrutor
        inline ~Poly(){destroi();};
};  