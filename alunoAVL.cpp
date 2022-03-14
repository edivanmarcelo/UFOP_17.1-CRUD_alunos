#include<iostream>
#include<cstdio>
#include<cstring>
#include"alunoAVL.hpp"
using namespace std;

struct Aluno{
    string nome;
    string curso;
    string cpf;
    int matricula;
    int idade;
};

Aluno *criarAluno(void){
    Aluno *aluno = new Aluno;
    return aluno;
}

Aluno *inserirAluno(string nome, string curso, string cpf, int matricula, int idade){
    Aluno *aluno = new Aluno;

    aluno->nome = nome;
    aluno->curso = curso;
    aluno->cpf = cpf;
    aluno->matricula = matricula;
    aluno->idade = idade;

    return aluno;
}

void inserirAlunoArvore(Aluno **arvore, Aluno **aluno){
    *arvore = *aluno;
    *aluno = NULL;
}

void inserirArvoreAluno(Aluno **arvore, Aluno **aluno){
    (*aluno)->nome = (*arvore)->nome;
    (*aluno)->curso = (*arvore)->curso;
    (*aluno)->cpf = (*arvore)->cpf;
    (*aluno)->idade = (*arvore)->idade;
    (*aluno)->matricula = (*arvore)->matricula;
}

int retornarChave(Aluno *arvore, Aluno *aluno){
    if(arvore->matricula > aluno->matricula)
        return 1;
    else if(arvore->matricula < aluno->matricula)
        return -1;
    else
        return 0;
}

void imprimirAluno(Aluno *aluno){
    cout << "\nDados do Aluno" << endl;
    cout << "Nome: " << aluno->nome << endl;
    cout << "Idade: " << aluno->idade << endl;
    cout << "CPF: " << aluno->cpf << endl;
    cout << "Curso: " << aluno->curso << endl;
    cout << "Matricula: " << aluno->matricula << endl;
}

void apagarAluno(Aluno **aluno){
    delete *aluno;
}
