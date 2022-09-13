#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Aluno{
    //Matricula;Nome;Curso;Status;
    uint64_t matricula;
    string nome, curso, status;
};

Aluno criaAluno(const uint8_t &, const string &, const string &, const string &);
void imprimeAluno(const Aluno &);
int main(){
    ifstream arquivo;
    const string texto("lista_alunos.csv");
    string cabecalho,c2;
    int N = 0;
    Aluno *turma = nullptr;

    arquivo.open(texto);
    arquivo >> cabecalho;
    
    // conta a quantidade de alunos
    if (cabecalho=="Matricula;Nome;Curso;Status;"&&arquivo.good()){
        do{
            string linha;
            getline(arquivo, linha);
            N++;
        }while(arquivo.is_open()&&!arquivo.eof());
    } else {
        cerr << "Falha na leitura do arquivo/arquivo incompativel";
    }
    if (N>0) turma =  new Aluno[N];
    else cerr << "Lista de alunos vazia";

    arquivo.seekg(0, arquivo.beg);
    arquivo >> cabecalho;
    
    if (turma!=nullptr){        
        Aluno temp;
        arquivo >> temp.matricula;
        if (arquivo.good() && !temp.matricula==0)
        {
            arquivo.ignore(';', 1);
            for(int i = 0; i < 4; i++){
                string te;
                getline(arquivo, te, ';');
                cout << '=' << te << '-';
            }
            //getline(arquivo, temp.nome);
            ////arquivo >> temp.nome;
            ////arquivo.ignore(';');
            //getline(arquivo, temp.curso);
            ////arquivo.ignore(';');
            //getline(arquivo, temp.status);
            //imprimeAluno(temp);
        }
        cout << " t " << temp.status;
    }

    arquivo.close();
    return 0;
}

Aluno criaAluno(const uint8_t &matricula, const string &nome, const string &curso, const string &status){
    Aluno A;
    A.matricula = matricula;
    A.nome = nome;
    A.curso = curso;
    A.status = status;
    return A;
}

void imprimeAluno(const Aluno &A){
    cout << A.matricula  << A.nome  << A.curso  << A.status << endl;
}
