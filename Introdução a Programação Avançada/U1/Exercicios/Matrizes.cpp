#include <iostream>

using namespace std;

/// FACA SEUS ACRESCIMOS NO CODIGO AQUI
struct Matriz
{
    int nL, nC;
    double ** dados;
};

Matriz novaMatriz(const int &, const int &);
void leMatriz(Matriz &);
Matriz produtoMatrizes(const Matriz &, const Matriz &);
void imprimeMatriz(const Matriz &);
void liberaMatriz(Matriz &);

/// Nao altere o programa principal
int main(void)
{
  // Declaracao das matrizes
  Matriz A, B, C;

  // Leitura das dimensoes das matrizes
  int NLa, NCa, NLb, NCb;
  do
  {
    cout << "Linhas de A: ";
    cin >> NLa;
  }
  while (NLa <= 0);
  do
  {
    cout << "Colunas de A: ";
    cin >> NCa;
  }
  while (NCa <= 0);
  // Obs: NLb = NCa
  NLb = NCa;
  do
  {
    cout << "Colunas de B: ";
    cin >> NCb;
  }
  while (NCb <= 0);

  // Alocacao das matrizes
  A = novaMatriz(NLa,NCa);
  B = novaMatriz(NLb,NCb);

  // Leitura dos elementos das matrizes A e B
  leMatriz(A);
  leMatriz(B);

  // Produto das matrizes
  C = produtoMatrizes(A,B);

  // Impressao das matrizes
  imprimeMatriz(C);

  // Liberacao da memoria das memorias
  liberaMatriz(A);
  liberaMatriz(B);
  liberaMatriz(C);

  return  0;
}

Matriz novaMatriz(const int &nL, const int &nC){
    Matriz temp;
    if(nL <= 0 || nC <= 0){
        temp.nL = 0;
        temp.nC = 0;
        temp.dados = nullptr;
        return temp;
    }
    temp.nL = nL;
    temp.nC = nC;
    temp.dados = new double*[nL];
    for(int i = 0; i < nL; i++){
        temp.dados[i] = new double[nC];
    }
    return temp;
}

void leMatriz(Matriz &A){
    for(int i = 0; i < A.nL; i++){
        for(int j = 0; j < A.nC; j++){
            cout << '[' << i << ']' << '[' << j << "]: ";
            cin >> A.dados[i][j];
        }
    }
}
Matriz produtoMatrizes(const Matriz &A, const Matriz &B){
    Matriz temp;
    if(A.nL <= 0 || A.nC <= 0 || B.nL <= 0 || B.nC <= 0 || A.nC != B.nL || A.dados == nullptr || B.dados == nullptr)
    {
        temp.nL = 0;
        temp.nC = 0;
        temp.dados = nullptr;
        return temp;
    }
    temp = novaMatriz(A.nL, B.nC);
    for(int i = 0; i < temp.nL; i++)
    {
        for(int j = 0; j < temp.nC; j++)
        {
            temp[i][j] = 0;
            for(int k = 0; k < A.nC; k++)
            {
                temp[i][j] += A.dados[i][k] * B.dados[k][j];
            }
        }
    }
    return temp;
}
void imprimeMatriz(const Matriz &A){
    for(int i = 0; i < A.nL; i++)
    {
        for(int j = 0; j < A.nC; j++)
        {
            cout << A.dados[i][j] << ", ";
        }
        cout << '\n';
    }
}
void liberaMatriz(Matriz &A){
    for(int i = 0; i < A.nL; i++)
    {
        for(int j = 0; j < A.nC; j++)
        {
            delete[] A.dados[i][j];
        }
    }
    delete[] A.dados;
    A.dados = nullptr;
    A.nL = 0;
    A.nC = 0;
}