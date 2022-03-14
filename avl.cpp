#include<iostream>
#include<cstdio>
#include"avl.hpp"
#include"alunoAVL.hpp"
using namespace std;

struct NoArvore{
    Aluno *aluno;
    NoArvore *esq;
    NoArvore *dir;
};

struct Arvore{
    NoArvore *raiz;
};

Arvore *criarArvore(void){
    Arvore *arvore = new Arvore;
    arvore->raiz = NULL;
    return arvore;
}

int calcularFBA(Arvore *arvore){
    return calcularFBN(arvore->raiz);
}

int calcularFBN(NoArvore *arvore){
    if(arvore == NULL)
        return 0;
    return calcularAltura(arvore->esq) - calcularAltura(arvore->dir);
}

int calcularAltura(NoArvore *arvore){
    int auxEsq, auxDir;
    if(arvore == NULL)
        return 0;

    auxEsq = calcularAltura(arvore->esq);
    auxDir = calcularAltura(arvore->dir);

    if(auxEsq > auxDir)
        return auxEsq+1;
    else
        return auxDir+1;
}

void rotacionarSENo(NoArvore **arvore){
    NoArvore *aux;
    aux = (*arvore)->dir;
    (*arvore)->dir = aux->esq;
    aux->esq = (*arvore);
    (*arvore) = aux;
}

void rotacionarSDNo(NoArvore **arvore){
    NoArvore *aux;
    aux = (*arvore)->esq;
    (*arvore)->esq = aux->dir;
    aux->dir = (*arvore);
    (*arvore) = aux;
}

int balancearENo(NoArvore **arvore){
    int fbe = calcularFBN((*arvore)->esq);
    if(fbe > 0){
        rotacionarSDNo(arvore);
        return 1;
    }
    else if(fbe < 0){
        rotacionarSENo(&((*arvore)->esq));
        rotacionarSDNo(arvore);
        return 1;
    }
    return 0;
}

int balancearDNo(NoArvore **arvore){
    int fbd = calcularFBN((*arvore)->dir);
    if(fbd < 0){
        rotacionarSENo(arvore);
        return 1;
    }
    else if(fbd > 0){
        rotacionarSDNo(&((*arvore)->dir));
        rotacionarSENo(arvore);
        return 1;
    }
    return 0;
}

int balancerNo(NoArvore **arvore){
    int fb = calcularFBN(*arvore);
    if(fb > 1)
        return balancearENo(arvore);
    else if(fb < -1)
        return balancearDNo(arvore);
    else
        return 0;
}

int inserirArvore(Arvore **arvore, Aluno **aluno){
    return inserirNo(&((*arvore)->raiz), aluno);
}

int inserirNo(NoArvore **arvore, Aluno **aluno){
    if(*arvore == NULL){
        NoArvore *folha = new NoArvore;
        folha->dir = NULL;
        folha->esq = NULL;
        folha->aluno = criarAluno();
        inserirAlunoArvore(&(folha->aluno), aluno);
        (*arvore) = folha;
        return 1;
    }
    else if(retornarChave((*arvore)->aluno, *aluno) > 0){
        if(inserirNo(&(*arvore)->esq, aluno)){
            if(balancerNo(arvore))
                return 0;
            else
                return 1;
        }
    }
    else if(retornarChave((*arvore)->aluno, *aluno) < 0){
        if(inserirNo(&(*arvore)->dir, aluno)){
            if(balancerNo(arvore))
                return 0;
            else
                return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

int removerArvore(Arvore **arvore, Aluno **aluno){
    return removerNo(&(*arvore)->raiz, aluno);
}

int removerNo(NoArvore **arvore, Aluno **aluno){
    NoArvore *aux;
    if(*arvore == NULL)
        return 0;

    else if(retornarChave((*arvore)->aluno, *aluno) == 0){
        inserirArvoreAluno(&(*arvore)->aluno, aluno);

        if((*arvore)->esq == NULL && (*arvore)->dir == NULL){
            delete (*arvore);
            *arvore = NULL;
            balancerNo(arvore);
            return 1;
        }

        if((*arvore)->esq != NULL && (*arvore)->dir == NULL){ // Possui subAv a esq
            aux = (*arvore);
            *arvore = (*arvore)->esq;
            delete (aux);
            balancerNo(arvore);
            return 1;
        }

        if((*arvore)->esq == NULL && (*arvore)->dir != NULL){ // Possui subAv a dir
            aux = (*arvore);
            *arvore = (*arvore)->dir;
            delete (aux);
            balancerNo(arvore);
            return 1;
        }
        retirarSucessor(arvore, &(*arvore)->dir);
        return 1;
    }
    else if(retornarChave((*arvore)->aluno, *aluno) > 0){
        removerNo(&(*arvore)->esq, aluno);
    }
    else{
        removerNo(&(*arvore)->dir, aluno);
    }
}

void retirarSucessor(NoArvore **raiz, NoArvore **subAv){
    NoArvore *aux;
    if((*subAv)->esq != NULL){
        retirarSucessor(raiz, &(*subAv)->esq);
        return;
    }

    inserirAlunoArvore(&(*raiz)->aluno, &(*subAv)->aluno);
    aux = *subAv;
    *subAv = (*subAv)->dir;
    delete aux;
}

int atualizarArvore(Arvore **arvore, Aluno **aluno){
    return atualizarNo(&(*arvore)->raiz, aluno);
}

int atualizarNo(NoArvore **arvore, Aluno **aluno){
    if(*arvore == NULL)
        return 0;
    else if(retornarChave((*arvore)->aluno, *aluno) == 0){
        inserirAlunoArvore(&(*arvore)->aluno, aluno);
        return 1;
    }
    else if(retornarChave((*arvore)->aluno, *aluno) > 0){
        if(atualizarNo(&(*arvore)->esq, aluno)){
            return 1;
        }
        else
            return 0;
    }
    else{
        if(atualizarNo(&(*arvore)->dir, aluno)){
            return 1;
        }
        else
            return 0;
    }
}

int pesquisarArvore(Arvore **arvore, Aluno **aluno){
    pesquisarNo(&(*arvore)->raiz, aluno);
}

int pesquisarNo(NoArvore **arvore, Aluno **aluno){
    if(*arvore == NULL)
        return 0;
    else if(retornarChave((*arvore)->aluno, *aluno) == 0){
        inserirArvoreAluno(&(*arvore)->aluno, aluno);
        return 1;
    }
    else if(retornarChave((*arvore)->aluno, *aluno) > 0){
        if(pesquisarNo(&(*arvore)->esq, aluno)){
            return 1;
        }
        else
            return 0;
    }
    else{
        if(pesquisarNo(&(*arvore)->dir, aluno)){
            return 1;
        }
        else
            return 0;
    }
}

void imprimirArvore(Arvore *arvore){
    imprimirNo(arvore->raiz);
}

void imprimirNo(NoArvore *arvore){
    if(arvore == NULL)
        return;
    else{
        imprimirNo(arvore->esq);
        imprimirAluno(arvore->aluno);
        imprimirNo(arvore->dir);
    }
}

void apagarArvore(Arvore **arvore){
    apagarNo(&(*arvore)->raiz);
}

void apagarNo(NoArvore **arvore){
    if(*arvore == NULL)
        return;
    else{
        apagarNo(&(*arvore)->esq);
        apagarNo(&(*arvore)->dir);
        apagarAluno(&(*arvore)->aluno);
        delete *arvore;
    }
}







