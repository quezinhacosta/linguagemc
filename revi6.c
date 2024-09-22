#include <stdio.h>
#define TAM 6
void ordenar(int* a){
    int aux;
    for(int i = 0; i < TAM - 1; i++){
        for(int q = 0; q < TAM - i - 1; q++){
            if (a[q] > a[q+1]){
            aux = a[q];
            a[q] = a[q+1];
            a[q+1] = aux;
        }
    }
    }
}
void preencher(int* a){
    for(int i = 0; i < TAM; i++){
        printf("Insira um valor: ");
        scanf("%d", &a[i]);
    }
}
void exibir(int* a){
    for(int i = 0; i < TAM; i++){
        printf("%d ", a[i]);
    }
}
int main(){
    int a[TAM];
    preencher(a);
    exibir(a);
    printf("\n");
    printf("Vetor ordenado: \n");
    ordenar(a);
    exibir(a);
    return 0;
}