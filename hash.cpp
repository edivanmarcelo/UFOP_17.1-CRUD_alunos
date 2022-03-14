#include<iostream>
#include<cstdio>

#include"alunoHash.hpp"
#include"hash.hpp"
using namespace std;

struct Hash{
    int qnt;
    int nListas;
    Lista *vetor;
};

struct Celula{
    Aluno *aluno;
    Celula *prox;
};

struct Lista{
    Celula *primeiro;
    Celula *ultimo;
};

void iniciarHash(Hash **tabela, int nListas){
    *tabela = new Hash;

    (*tabela)->qnt = 0;
    (*tabela)->nListas = nListas;

    (*tabela)->vetor = new Lista [nListas];
    for(int i=0; i<nListas; i++){
        (*tabela)->vetor[i] = criarLista(); //Inicializar listas
    }
}

Lista criarLista(void){
    Lista lista;
    lista.primeiro = NULL;
    lista.ultimo = NULL;

    return lista;
}

int retornarIndice(Hash *tabela, int matricula){
    int aux;
    aux = matricula % tabela->nListas;
    return aux;
}

int pesquisarHash(Hash **tabela, int matricula, Aluno **aluno){
    Celula *aux = pesquisarCelula(tabela, matricula);

    if(aux == NULL)
        return 0;

    *aluno = retornarAluno(aux->aluno);
    return 1;
}

Celula *pesquisarCelula(Hash **tabela, int matricula){
    int i = retornarIndice(*tabela, matricula);
    Celula *aux;

    if(listaVazia((*tabela)->vetor[i]))
        return NULL; //pesquisa sem sucesso

    aux = (*tabela)->vetor[i].primeiro;

    while(aux!=NULL && compararChave(matricula, aux->aluno)!=0)
        aux = aux->prox;

    if(aux != NULL)
        if(!compararChave(matricula, aux->aluno))
            return aux;
    else
        return NULL; //pesquisa sem sucesso
}

int listaVazia(Lista lista){
    if(lista.primeiro == NULL)
        return 1;
    return 0;
}

int inserirHash(Hash **tabela, Aluno *aluno){
    if(pesquisarCelula(tabela, retornarMat(aluno)) == NULL){
        inserirLista(&(*tabela)->vetor[retornarIndice(*tabela, retornarMat(aluno))], aluno);
        (*tabela)->qnt++;
        return 1;
    }
    return 0;
}

void inserirLista(Lista *lista, Aluno *aluno){
    Celula *novo = new Celula;

    novo->aluno = criarAlunoHash();
    novo->aluno = retornarAluno(aluno);
    novo->prox = lista->primeiro;
    lista->primeiro = novo;

    if(lista->ultimo == NULL){
        lista->ultimo = novo;
    }
}

int removerHash(Hash **tabela, Aluno **aluno){
    Celula *aux = pesquisarCelula(tabela, retornarMat(*aluno));

    if(aux == NULL)
        return 0;

    retirarLista(&(*tabela)->vetor[retornarIndice(*tabela, retornarMat(*aluno))], aluno);
    (*tabela)->qnt--;
    return 1;
}

void retirarLista(Lista *lista, Aluno **aluno){
    Celula *anterior = NULL;
    Celula *aux = lista->primeiro;

    while(aux!=NULL && compararChave(retornarMat(aux->aluno), *aluno)!=0){
        anterior = aux;
        aux = aux->prox;
    }

    if(aux != NULL){
        if(anterior == NULL)
            lista->primeiro = aux->prox;
        else{
            anterior->prox = aux->prox;
            if(lista->ultimo == aux)
                lista->ultimo = anterior;
        }
        *aluno = retornarAluno(aux->aluno);
        delete aux;
    }
}

int atualizarHash(Hash **tabela, int matricula, Aluno **aluno){
    Celula *aux = pesquisarCelula(tabela, matricula);

    if(aux == NULL)
        return 0;

    aux->aluno = retornarAluno(*aluno);
    return 1;
}

void imprimirHash(Hash *tabela){
     for(int i=0; i<tabela->nListas; i++){
        imprimirLista(&tabela->vetor[i]);
     }

}

void imprimirLista(Lista *lista){
    for(Celula *aux=lista->primeiro; aux!=NULL; aux=aux->prox){
       imprimirAlunoHash(aux->aluno);
    }
}

void ApagarHash(Hash **tabela){
    for(int i=0; i<(*tabela)->qnt; i++){
        liberarLista(&(*tabela)->vetor[i]);
    }
    delete tabela;
}

void liberarLista(Lista *lista){
    liberarCelula(&lista->primeiro);
}

void liberarCelula(Celula **aux){
    if(*aux != NULL){
        liberarCelula(&(*aux)->prox);
        apagarAlunoHash(&(*aux)->aluno);
        delete *aux;
    }
}












