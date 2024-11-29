#include <stdio.h>

int soma(int n){
    if(n==0){
        return 0;
    }
    else{
        return (n%10)+ soma(n/10); 
    }
}