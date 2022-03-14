#ifndef alunoAVL_hpp
#define alunoAVL_hpp

#include<cstring>
using std::string;
struct Aluno;

Aluno *criarAluno(void);
Aluno *inserirAluno(string, string, string, int, int);
void inserirAlunoArvore(Aluno**, Aluno**);
void inserirArvoreAluno(Aluno**, Aluno**);
int retornarChave(Aluno*, Aluno*);
void imprimirAluno(Aluno*);
void apagarAluno(Aluno**);

#endif
