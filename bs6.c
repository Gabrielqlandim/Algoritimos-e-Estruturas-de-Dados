#include <stdio.h>


int main(void){
    int n;

    printf("Tamahno do vetor: ");
    scanf("%d", &n);
    int vet[n];
    for(int i=0;i<n;i++){
        scanf("%d", &vet[i]);
    }

    int t = 1, troca =1;

    while(t<=n && troca ==1){
        troca = 0;
        for(int i=0; i<n-1;i++){
            if(vet[i]>vet[i+1]){
                int aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                troca = 1; 
            }
        }
        ++t;
    }
    for(int i=0;i<n;i++){
        printf("%d ", vet[i]);
    }
    return 0;
}