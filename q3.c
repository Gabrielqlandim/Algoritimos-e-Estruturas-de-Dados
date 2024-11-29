#include <stdio.h>
#include<stdlib.h>
//q3 prova
typedef struct Arv{
    int valor;
    struct Arv *dir;
    struct Arv *esq;
}Arv;

void inserir(Arv **raiz, int n){
    if(*raiz == NULL){
        *raiz = (Arv*)malloc(sizeof(Arv));
        (*raiz)->dir=NULL;
        (*raiz)->esq=NULL;
        (*raiz)->valor = n;
    }
    else if(n<(*raiz)->valor)
        inserir(&(*raiz)->esq, n);
    else if(n>(*raiz)->valor)
        inserir(&(*raiz)->dir, n);
}
int contaFolhas(Arv *raiz){
    if(raiz == NULL)
        return 0;
    else{
        if(raiz->esq == NULL && raiz->dir == NULL)
            return 1;
        return contaFolhas(raiz->dir) + contaFolhas(raiz->esq);
    }
}

int qtdFolhas(Arv *raiz, int chave){
    if(raiz == NULL)
        return 0;
    if(chave < raiz->valor)
        qtdFolhas(raiz->esq, chave);
    else
        qtdFolhas(raiz->dir, chave);
    return contaFolhas(raiz);
}

int main(void){
    Arv *raiz = NULL;

    inserir(&raiz, 48);
    inserir(&raiz, 30);
    inserir(&raiz, 82);
    inserir(&raiz, 15);
    inserir(&raiz, 37);
    inserir(&raiz, 61);
    inserir(&raiz, 98);

    printf("%d ", qtdFolhas(raiz, 48));
    return 0;
}

