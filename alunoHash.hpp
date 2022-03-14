#ifndef alunoHash_hpp
#define alunohash_hpp

#include<cstring>
using std::string;

struct Aluno;

Aluno *criarAlunoHash();
Aluno *inserirAlunoHash(string, string, string, int, int);
Aluno *retornarAluno(Aluno*);
Aluno *retornarNULL();
int compararChave(int, Aluno*);
int retornarMat(Aluno*);
void imprimirAlunoHash(Aluno*);
void apagarAlunoHash(Aluno**);

#endif
