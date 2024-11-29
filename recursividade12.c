#include <stdio.h>

int media(int *v, int n, int soma, int cont){
    
    if(n==0){
        return soma/cont;
    }
    else{
        if(v[n-1] % 2 == 0){
            return media(v, n-1, soma+v[n-1], cont +=1);
        }
        else{
            return media(v, n-1, soma, cont);
        }
    }
}

int main(void){
    int vet[6] = {2,3,6,7,8,9};

    printf("Media: %d", media(vet, 6, 0, 0));
    return 0;
}