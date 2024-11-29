#include <stdio.h>
#include <stdlib.h>

typedef struct Arv{
    int valor;
    struct Arv *dir;
    struct Arv *esq;
}Arv;

void inserir(Arv **raiz, int n){
    if(*raiz == NULL){
        *raiz = (Arv*)malloc(sizeof(Arv));
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;
        (*raiz)->valor = n;
    }
    else if(n<(*raiz)->valor)
        inserir(&(*raiz)->esq, n);
    else if(n>(*raiz)->valor)
        inserir(&(*raiz)->dir, n);
}

void fihsEsquerdos(Arv* raiz){
    if(raiz == NULL)
        return;
    else{
        if(raiz->esq != NULL)
            printf("%d ", raiz->esq->valor);
    }
    fihsEsquerdos(raiz->esq);
    fihsEsquerdos(raiz->dir);
}

int main(void){
    Arv *raiz = NULL;
    inserir(&raiz, 4);
    inserir(&raiz, 2);
    inserir(&raiz, 7);
    inserir(&raiz, 1);
    inserir(&raiz, 3);
    inserir(&raiz, 5);
    inserir(&raiz, 8);

    fihsEsquerdos(raiz);
    return 0;
}