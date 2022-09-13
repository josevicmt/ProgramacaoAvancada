#include <iostream>

using namespace std;

bool eh_bissexto(int ano)
{
    return ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0);
}

int conta_dias(int dia, int mes, int ano)
{
    //
    int dias[] = { 1, };
}

int main()
{
    //Q1) Programa que recebe valores sucetivos até receber um valor negativo
    /*
    int x; 
    do
    {
        cout << "Insira um número";
        cin >> x;
        cout << x;
    } while (x > 0);
    */
    //Q2) Calculadora recebe dois números e um símbolo, encerra quando não recebe um símbolo válido (+,-,*,/)
    /*
    char simbolo;
    int num1, num2;
    bool erro = false;
    do
    {
        cout << "Numero 1\n";
        cin >> num1;
        cout << "Simbolo\n";
        cin >> simbolo;
        cout << "Numero 2\n";
        cin >> num2;
        cout << "Resultado\n";
        
        switch (simbolo)
        {
        case '-':
            cout << "Numero 1 - Numero 2 = " << num1 - num2 << '\n';
            break;
        case '+':
            cout << "Numero 1 + Numero 2 = " << num1 + num2 << '\n';
            break;
        case '*':
            cout << "Numero 1 * Numero 2 = " << num1 * num2 << '\n';
            break;
        case '/':
            cout << "Numero 1 / Numero 2 = " << num1 / num2 << '\n';
            break;
        default:
            cout << "Simbolo invalido\n";
            erro = true;
            break;
        }
        
        
    } while (!erro);
    */

   //Q3) Advinhar um numero entre 0 e 100
   /*
   srand(time(NULL)); // inicializa seed baseada no clock do computador

   int numero = rand() % 101, palpite, tentativas = 0;

   do
   {
       cout << "Seu palpite\n";
       cin >> palpite;
       if (palpite > numero)
       {
           cout << "Errou pra mais\n";
       }else if (palpite < numero)
       {
           cout << "Errou pra menos\n";
       }
       
   } while (numero != palpite);
   */


    return 0;    
}