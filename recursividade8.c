#include <stdio.h>

int som(int n){
    if(n==0){
        return 0;
    }
    else{
        return n +som(n-1);
    }
}

int main(void){
    int n;

    printf("Escreva um numero: ");
    scanf("%d", &n);

    int r = som(n);

    printf("%d", r);
    return 0;
}