#include <stdio.h>

void calcular_media(int *a, int *b){
    if(*a>*b){
        int media = 0, resto = 0;
        media = (*a+*b)/2;
        resto = (*a+*b)%2;
        *b=media;     
        *a=resto;
    }
    else{
        int media = 0, resto = 0;
        media = (*a+*b)/2;
        resto = (*a+*b)%2;
        *a=media;
        
        *b=resto;
    }
}

int main(void){
    int a,b;
    a=20;
    b=3;
    calcular_media(&a,&b);
    return 0;
}