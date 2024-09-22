#include <stdio.h>
#define TAM 5

void preencher(int* vet){
    for (int i = 0; i < TAM; i++){
        printf("Valor na posicao %d = ", i);
        scanf("%d", &vet[i]);
    }
    printf("\n");
}

void soma(int* a, int* b, int* c){
    for (int i = 0; i < TAM; i++){
        c[i] = a[i] + b[i];
    }
}

void exibir(int* vet){
    for (int i = 0; i < TAM; i++){
        printf("%d  ", vet[i]); // & apenas no scanf ou uso nos ponteiros
    }
    printf("\n");
}

int main(){
    int a[TAM], b[TAM], c[TAM];

    printf("Preencher vetor 'a': \n");
    preencher(a);
    printf("Preencher vetor 'b': \n");
    preencher(b);
    soma(a, b, c);
    printf("Valores do vetor 'a': \n");
    exibir(a);
    printf("Valores do vetor 'b': \n");
    exibir(b);
    printf("Valores do vetor 'c': \n");
    exibir(c);

    return 0;
}