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


void inOrdem(Arv *raiz){
    if(raiz != NULL){
        inOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        inOrdem(raiz->dir);
    }
}

void preOrdem(Arv *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);     
    }
}

void posOrdem(Arv *raiz){
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

int busca(Arv *raiz, int n){
    if(raiz == NULL)
        return 0;
    else if(raiz->valor == n)
        return 1;
    else if(n<raiz->valor)
        busca(raiz->esq, n);
    else
        busca(raiz->dir, n);
}

Arv *menorDireita(Arv **raiz){
    if((*raiz)->dir != NULL)
        return menorDireita(&(*raiz)->dir);
    else{
        Arv *aux = *raiz;
        if((*raiz)->esq != NULL)
            (*raiz) = (*raiz)->esq;
        else
            *raiz = NULL;
        return aux;
    }
}

void remover(Arv **raiz, int n){
    if(*raiz == NULL)
        return;
    else if(n<(*raiz)->valor)
        remover(&(*raiz)->esq, n);
    else if(n>(*raiz)->valor)
        remover(&(*raiz)->dir, n);
    else{
        Arv *aux = *raiz;
        if((*raiz)->dir == NULL && (*raiz)->esq == NULL){
            free(aux);
            aux = NULL;
        }
        else{
            if((*raiz)->esq == NULL){
                (*raiz) = (*raiz)->dir;
                aux->dir = NULL;
                free(aux);
            }
            else{
                if((*raiz)->dir == NULL){
                    (*raiz) = (*raiz)->esq;
                    aux->esq = NULL;
                    free(aux);
                }
                else{
                    aux = menorDireita(&(*raiz)->esq);
                    aux->esq = (*raiz)->esq;
                    aux->dir = (*raiz)->dir;
                    free(*raiz);
                    *raiz = aux;
                }
            }
        }
    }
}

int main(void){
    system("CLS");
    Arv *raiz = NULL;
    inserir(&raiz, 10);
    inserir(&raiz, 15);
    inserir(&raiz, 5);

    printf("\n");
    printf("In ordem: ");
    inOrdem(raiz);

    printf("\n");
    printf("Pre ordem: ");
    preOrdem(raiz);

    printf("\n");
    printf("Pos ordem: ");
    posOrdem(raiz);


    printf("\n");
    remover(&raiz, 10);


    printf("\n");
    printf("In ordem: ");
    inOrdem(raiz);
    return 0;
}