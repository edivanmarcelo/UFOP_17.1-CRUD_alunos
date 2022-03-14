#ifndef hash_hpp
#define hash_hpp

#include"alunoHash.hpp"

struct Hash;
struct Lista;
struct Celula;

void iniciarHash(Hash**, int);
Lista criarLista(void);

void ApagarHash(Hash**);
void liberarLista(Lista*);
void liberarCelula(Celula**);

int retornarIndice(Hash*, int);
int listaVazia(Lista);

int pesquisarHash(Hash**, int, Aluno**);
Celula *pesquisarCelula(Hash**, int);
int atualizarHash(Hash**, int, Aluno**);

int inserirHash(Hash**, Aluno*);
void inserirLista(Lista*, Aluno*);

int removerHash(Hash**, Aluno**);
void retirarLista(Lista*, Aluno**);

void imprimirHash(Hash*);
void imprimirLista(Lista*);


#endif
