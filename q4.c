#include <stdio.h>
#include <stdlib.h>

typedef struct Arv{
    int valor;
    struct Arv *esq;
    struct Arv *dir;
}Arv;

int filhos(Arv *raiz){
    if(raiz == NULL)
        return 0;
    else{
        int ae = filhos(raiz->esq);
        int ad = filhos(raiz->dir);
        return 1+(ae>ad?ae:ad);
    }
}

void roda_dir(Arv **raiz){
    Arv *aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);
    (*raiz) = aux;
}

void roda_esq(Arv **raiz){
    Arv *aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = (*raiz);
    (*raiz) = aux;
}

void balanco(Arv **raiz){
    if(*raiz == NULL)
        return;
    else{
        Arv *aux = *raiz;

        int ae = filhos((*raiz)->esq);
        int ad = filhos((*raiz)->dir);

        int fb = ad - ae;

        if(fb<= -2){
            aux = (*raiz)->esq;
            fb = filhos(aux->dir) - filhos(aux->esq);

            if(fb>0){
                roda_dir(&(*raiz)->dir);
                roda_esq(raiz);
                printf("Rotacao: dupla direita");
            }
            else{
                roda_esq(raiz);
                printf("Rotacao: simples direita");
            }
        }
        else if(fb>=2){
            aux = (*raiz)->dir;

            fb = filhos(aux->dir) - filhos(aux->esq);

            if(fb<0){
                roda_esq(&(*raiz)->esq);
                roda_dir(raiz);
                printf("Rotacao: dupla a esquerda");
            }
            else{
                roda_esq(raiz);
                printf("Rotacao: simples esquerda");
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
    else if(n< (*raiz)->valor)
        inserir(&(*raiz)->esq, n);
    else if(n>(*raiz)->valor)
        inserir(&(*raiz)->dir, n);
    
    balanco(raiz);
}

Arv *maiorDireita(Arv **raiz){
    if((*raiz)->dir != NULL)
        return maiorDireita(&(*raiz)->dir);
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
                    aux = maiorDireita(&(*raiz)->esq);
                    aux->dir = (*raiz)->dir;
                    aux->esq = (*raiz)->esq;
                    (*raiz)->esq = (*raiz)->dir = NULL;
                    free(*raiz);
                    *raiz = aux;
                    aux = NULL;
                }
            }
        }
    }
    balanco(raiz);
}

void posOrdem(Arv *raiz){
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

int main(void){
    Arv *raiz = NULL;

    inserir(&raiz, 50);
    inserir(&raiz, 25);
    inserir(&raiz, 75);
    inserir(&raiz, 10);
    inserir(&raiz, 30);
    inserir(&raiz, 60);
    inserir(&raiz, 80);
    inserir(&raiz, 65);
    inserir(&raiz, 70);
    inserir(&raiz, 90);

    printf("\n ");
    posOrdem(raiz);

    remover(&raiz, 30);

    printf("\n ");
    posOrdem(raiz);
    return 0;
}