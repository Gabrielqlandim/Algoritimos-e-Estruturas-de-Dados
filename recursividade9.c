#include <stdio.h>

int soma(int *vet, int n){
    if(n==0){
        return 0;
    }
    else{
        return vet[n-1] + soma(vet, n-1);
    }
}

int main(void){
    int n;

    printf("DIgite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];
    for(int i=0;i<n;i++){
        printf("Digite o numero do vetor: ");
        scanf("%d", &vet[i]);
    }

    int r = soma(vet, n);
    printf("%d", r);
    return 0;
}