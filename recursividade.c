#include <stdio.h>

int fat(int n){
    if(n==1 || n==0){
        return 1;
    }
    else{
        return n*fat(n-1);
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    int r = fat(n);
    printf("%d",r);
    return 0;
}