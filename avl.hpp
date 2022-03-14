#ifndef avl_hpp
#define avl_hpp

#include"alunoAVL.hpp"
struct Arvore;
struct NoArvore;

Arvore *criarArvore(void);
void apagarArvore(Arvore**);
void apagarNo(NoArvore**);

int calcularFBA(Arvore*);
int calcularFBN(NoArvore*);
int calcularAltura(NoArvore*);

void rotacionarSENo(NoArvore**);
void rotacionarSDNo(NoArvore**);

int balancearENo(NoArvore**);
int balancearDNo(NoArvore**);
int balancerNo(NoArvore**);

int inserirArvore(Arvore**, Aluno**);
int inserirNo(NoArvore**, Aluno**);

int removerArvore(Arvore**, Aluno**);
int removerNo(NoArvore**, Aluno**);
void retirarSucessor(NoArvore**, NoArvore**);

int pesquisarArvore(Arvore**, Aluno**);
int pesquisarNo(NoArvore**, Aluno**);

int atualizarArvore(Arvore**, Aluno**);
int atualizarNo(NoArvore**, Aluno**);

void imprimirArvore(Arvore*);
void imprimirNo(NoArvore*);

#endif
