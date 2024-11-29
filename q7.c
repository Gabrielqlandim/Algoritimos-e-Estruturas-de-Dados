#include <stdio.h>
#include <string.h>

void intercala(char *livros[], int inicio, int meio, int fim){
    int inicio_V1 = inicio;
    int inicio_V2 = meio+1;
    int poslivre = 0;
    char *aux[fim-inicio+1];

    while(inicio_V1<=meio && inicio_V2<= fim){
        if(strcmp(livros[inicio_V1], livros[inicio_V2])<=0)
            aux[poslivre++] = livros[inicio_V1++];
        else
            aux[poslivre++] = livros[inicio_V2++];
    }

    while(inicio_V1<=meio)
        aux[poslivre++] = livros[inicio_V1++];
    while(inicio_V2<=fim)
        aux[poslivre++] = livros[inicio_V2++];
    
    for(int i=0; i<poslivre;i++)
        livros[inicio+i] = aux[i];
}

void mergesort(char *livros[], int inicio, int fim){
    if(inicio<fim){
        int meio = (inicio+fim)/2;
        mergesort(livros, inicio, meio);
        mergesort(livros, meio+1, fim);
        intercala(livros, inicio,meio,fim);
    }
}

int main(void){
    char *romance[] = {"O Morro dos Ventos Uivantes","Orgulho e Preconceito", "A Culpa é das Estrelas", "Anna Kariênina", "Jane Eyre"};
    char *terror[] = { "It - A Coisa", "Drácula", "O Iluminado", "O Exorcista", "A Coisa"};

    printf("livros antes da ordenacao:\n ");
    int tam = sizeof(romance)/sizeof(romance[0]);
    int tam2 = sizeof(terror)/sizeof(terror[0]);
    for(int i=0; i<tam; i++){
        printf("%s\n ", romance[i]);
    }
    printf("\n");
    for(int i=0; i<tam2; i++){
        printf("%s\n ", terror[i]);
    }

    mergesort(romance, 0, tam-1);
    mergesort(terror, 0, tam2-1);

    printf("Livros depois da ordenacao: \n");

    printf("\n");

    printf("Fileira 1: Romance \n");
    for(int i = 0; i<tam; i++){
        printf("%s \n", romance[i]);
    }
    printf("\n");
    printf("Fileira 2: Terror \n");
    for(int i = 0; i<tam2; i++){
        printf("%s \n", terror[i]);
    }
    return 0;
}