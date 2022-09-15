#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream X("Teste.txt");
    string temp;

    X >> temp;
    cout << temp;
    return 0;
}
