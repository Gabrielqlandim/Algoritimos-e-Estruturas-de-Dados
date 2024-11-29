#include <stdio.h>

int menor(int *vet, int tam,int indice){
    if(tam == 0){
        return vet[indice];
    }
    else{
        if(vet[tam-1]<vet[indice]){
            return menor(vet, tam-1, tam-1);
        }
        else{
            return menor(vet, tam-1,indice);
        }
    }
}

int main(void){
    int vet[8] = {57,13,42,1,21,3,82,59};

    printf("%d", menor(vet,8, 0));
    return 0;
}