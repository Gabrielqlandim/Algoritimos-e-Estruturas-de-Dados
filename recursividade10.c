#include <stdio.h>

int maior(int *vet, int n, int indice){
    if(n==0){
        return vet[indice];
    }
    else{
        if(vet[n-1]>vet[indice]){
            return maior(vet, n-1, n-1);
        }
        else{
            return maior(vet,n-1, indice);
        }
        
    }
}

int main(void){
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];
    for(int i=0;i<n;i++){
        printf("Digite o numero do vetor: ");
        scanf("%d", &vet[i]);
    }

    printf("%d", maior(vet, n, 0));
    return 0;
}