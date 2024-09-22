#include <stdio.h>
#define TAM 10

void preencherA(int* a){
    for (int i = 0; i < TAM; i++){
        printf("Valor na posicao %d = ", i);
        scanf("%d", &a[i]);
    }
    printf("\n");
}

void preencherB(int* a, int* b){
    for(int i = 0; i < TAM; i++){
        if (a[i] % 2 == 0){
            b[i] = a[i] / 2;
        }
        else {
            b[i] = a[i]*3;
        }
    }
}

void exibir(int* x){
    for(int i = 0; i < TAM; i++){
        printf("%d  ", x[i]);
    }
    printf("\n");
}

int main(){
    int a[TAM], b[TAM], c[TAM];
    printf("Digite valores para 'a': \n");
    preencherA(a);
    preencherB(a, b);
    printf("Valores de 'a': \n");
    exibir(a);
    printf("Valores de 'b': \n");
    exibir(b);

    return 0;

}