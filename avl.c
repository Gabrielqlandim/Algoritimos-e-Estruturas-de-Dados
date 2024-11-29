#include <stdio.h>
#include<stdlib.h>

typedef struct Arv{
    int valor;
    struct Arv *dir;
    struct Arv *esq;
}Arv;

int filhos(Arv *raiz){
    if(raiz == NULL){
        return 0;
    }
    else{
        int ae = filhos(raiz->esq);
        int ad = filhos(raiz->dir);
        return 1+(ae>ad?ae:ad);
    }
}

void roda_esq(Arv **raiz){
    Arv *aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = *raiz;
    *raiz = aux;
}

void roda_dir(Arv **raiz){
    Arv *aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = *raiz;
    *raiz = aux;
}

void balanco(Arv **raiz){
    if(raiz == NULL){
        return;
    }
    else{
        Arv *aux;
        int fb = filhos((*raiz)->dir) - filhos((*raiz)->esq);

        if(fb<=-2){
            aux = (*raiz)->esq;
            fb = filhos(aux->dir) - filhos(aux->esq);
            if(fb>0){
                roda_esq(&((*raiz)->esq));
                roda_dir(raiz);
                printf("Rotacao: dupla a direita");
            }
            else{
                roda_dir(raiz);
                printf("Rotacao: simples a direita");
            }
        }
        else if(fb >= 2){
            aux = (*raiz)->dir;
            fb = filhos(aux->dir) - filhos(aux->esq);
            if(fb<0){
                roda_dir(&((*raiz)->dir));
                roda_esq(raiz);
                printf("Rotacao dupla a esquerda");
            }
            else{
                roda_esq(raiz);
                printf("Rotacao: simples a esquerda");
            }
        }
    }
}

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
    balanco(raiz);
}

Arv *menorDireita(Arv **raiz){
    Arv *aux = *raiz;
    if((*raiz)->dir != NULL)
        return menorDireita(&(*raiz)->dir);
    else{
        if((*raiz)->esq != NULL)
            (*raiz) = (*raiz)->esq;
        else
            (*raiz)=NULL;
        return aux;
    }
}

void remover(Arv **raiz, int n){
    if (*raiz == NULL)
        return;
    else if(n<(*raiz)->valor)
        remover(&(*raiz)->esq, n);
    else if(n>(*raiz)->valor)
        remover(&(*raiz)->dir, n);
    else{
        Arv *aux = *raiz;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            free(*raiz);
            *raiz = NULL;
        }
        else{
            if((*raiz)->esq == NULL){
                (*raiz) = (*raiz)->dir;
                aux->dir = NULL;
                free(aux);
                aux = NULL;
            }
            else{
                if((*raiz)->dir == NULL){
                    (*raiz) = (*raiz)->esq;
                    aux->esq = NULL;
                    free(aux);
                    aux = NULL;
                }
                else{
                    aux = menorDireita(&(*raiz)->esq);
                    aux->dir = (*raiz)->dir;
                    aux->esq = (*raiz)->esq;
                    (*raiz)->dir = (*raiz)->esq = NULL;
                    free((*raiz));
                    *raiz = aux;
                    aux = NULL;
                }
            }
        }
    }
    balanco(raiz);
}

void preOrdem(Arv *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void inOrdem(Arv *raiz){
    if(raiz != NULL){
        inOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        inOrdem(raiz->dir);
    }
}

void posOrdem(Arv *raiz){
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}
int main(void){
    system("cls");
    Arv *raiz = NULL;

    // Inserindo valores na árvore
    inserir(&raiz, 30);
    inserir(&raiz, 20);
    inserir(&raiz, 40);
    inserir(&raiz, 10);
    inserir(&raiz, 25);
    inserir(&raiz, 35);
    inserir(&raiz, 50);

    printf("Pre-Ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Em-Ordem: ");
    inOrdem(raiz);
    printf("\n");

    printf("Pos-Ordem: ");
    posOrdem(raiz);
    printf("\n");

    // Removendo um valor da árvore
    printf("Removendo o valor 20.\n");
    remover(&raiz, 20);

    printf("Pre-Ordem apos remocao: ");
    preOrdem(raiz);
    printf("\n");

    printf("Em-Ordem apos remocao: ");
    inOrdem(raiz);
    printf("\n");

    printf("Pos-Ordem apos remocao: ");
    posOrdem(raiz);
    printf("\n");

    return 0;
}