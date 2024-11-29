#include <stdio.h>

int main(void){
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];

    for(int i=0;i<n;i++){
        printf("Digite o numero para compor o vetor: ");
        scanf("%d", &vet[i]);
    }

    int t=1, troca = 1;

    while(troca == 1 && t<=n){
        troca = 0;
        for(int i=0;i<n-1;i++){
            if(vet[i]>vet[i+1]){
                int aux=vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                troca =1;
            }
            
        }
        ++t;
    }


    for(int i=0;i<n;i++){
        printf("%d ", vet[i]);
    }

    int TD=1, trocaD = 1;
    while(trocaD == 1 && TD<=n){
        trocaD = 0;
        for(int i=0;i<n-1;i++){
            if(vet[i]<vet[i+1]){
                int aux=vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                trocaD =1;
            }
        }
        ++TD;
    }
    
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ", vet[i]);
    }
    return 0;
}