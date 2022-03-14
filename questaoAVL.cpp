#include<iostream>
#include<cstring>
#include<locale.h>
#include<time.h>

#include"questaoAVL.hpp"
#include"avl.hpp"
#include"alunoAVL.hpp"
using namespace std;

void questaoAVL(void){
    setlocale(LC_ALL, "Portuguese");

    string nome;
    string curso;
    string cpf;
    int matricula;
    int idade;
    int op;
    int aux;

    Arvore *arvore;
    Aluno *aluno;

    arvore = criarArvore();

    do{
        cout << "\n__________MENU DE OPÇÕES__________" << endl;
        cout << "01 - Inserir novo aluno" << endl;
        cout << "02 - Remover dados do aluno" << endl;
        cout << "03 - Atualizar dados do aluno" << endl;
        cout << "04 - Buscar aluno por matricula" << endl;
        cout << "05 - Imprimir alunos cadastrados" << endl;
        cout << "00 - Sair " << endl;
        cout << "Escolha: " << endl;
        cin >> op;

        switch(op){
        case 1:
            cout << "Nome:" << endl;
            cin >> nome;
            cout << "Curso:" << endl;
            cin >> curso;
            cout << "CPF:" << endl;
            cin >> cpf;
            cout << "Matricula:" << endl;
            cin >> matricula;
            cout << "Idade:" << endl;
            cin >> idade;

            aluno = inserirAluno(nome, curso, cpf, matricula, idade);
            aux = inserirArvore(&arvore, &aluno);
            apagarAluno(&aluno);

            if(aux == 1)
                cout << "Cadastrado!!" << endl;
            else
                cout << "Aluno já cadastrado" << endl;
            break;

        case 2:
            cout << "Matricula: " << endl;
            cin >> matricula;

            aluno = inserirAluno("/0", "/0", "/0", matricula, 0);
            aux = removerArvore(&arvore, &aluno);
            if(aux == 1){
                cout << "Removido!!" << endl;
                imprimirAluno(aluno);
                apagarAluno(&aluno);
            }
            else
                cout << "Aluno inexistente" << endl;
            break;

        case 3:
            cout << "Matricula: " << endl;
            cin >> matricula;
            cout << "Nome: " << endl;
            cin >> nome;
            cout << "Curso" << endl;
            cin >> curso;
            cout << "CPF: " << endl;
            cin >> cpf;
            cout << "Idade: " << endl;
            cin >> idade;

            aluno = inserirAluno(nome, curso, cpf, matricula, idade);
            aux = atualizarArvore(&arvore, &aluno);
            if(aux == 1)
                cout << "Atualizado!!" << endl;
            else
                cout << "Aluno inexistente" << endl;
            break;

        case 4:
            cout << "Matricula: " << endl;
            cin >> matricula;

            aluno = inserirAluno("/0", "/0", "/0", matricula, 0);
            aux = pesquisarArvore(&arvore, &aluno);
            if(aux == 1){
                cout << "Encontrado!" << endl;
                imprimirAluno(aluno);
                apagarAluno(&aluno);
            }
            else{
                cout << "Aluno inexistente!" << endl;
            }
            break;

        case 5:
            cout << "Alunos:" << endl;
            imprimirArvore(arvore);
            break;
        case 0:
            cout << endl;
            break;
        default:
            cout << "Opção invalida!" << endl;
        }

    }while(op != 0);

    apagarArvore(&arvore);
}
