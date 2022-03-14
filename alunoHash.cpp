#include<iostream>
#include<cstring>
#include"alunoHash.hpp"
using namespace std;

struct Aluno{
    string nome;
    string curso;
    string cpf;
    int matricula;
    int idade;
};

Aluno *criarAlunoHash(){
    Aluno *aluno;
    aluno = new Aluno;
    return aluno;
}

Aluno *inserirAlunoHash(string nome, string curso, string cpf, int matricula, int idade){
    Aluno *aluno = new Aluno;

    aluno->nome = nome;
    aluno->curso = curso;
    aluno->cpf = cpf;
    aluno->matricula = matricula;
    aluno->idade = idade;

    return aluno;
}

Aluno *retornarAluno(Aluno *aluno){
    return aluno;
}

Aluno *retornarNULL(){
    return NULL;
}

int compararChave(int matricula, Aluno *aluno){
    if(matricula > aluno->matricula)
        return 1;
    else if(matricula < aluno->matricula)
        return -1;
    return 0;
}

int retornarMat(Aluno *aluno){
    return aluno->matricula;
}

void imprimirAlunoHash(Aluno *aluno){
    cout << "\nDados do Aluno" << endl;
    cout << "Nome: " << aluno->nome << endl;
    cout << "Idade: " << aluno->idade << endl;
    cout << "CPF: " << aluno->cpf << endl;
    cout << "Curso: " << aluno->curso << endl;
    cout << "Matricula: " << aluno->matricula << endl;
}

void apagarAlunoHash(Aluno **aluno){
    delete *aluno;
}
