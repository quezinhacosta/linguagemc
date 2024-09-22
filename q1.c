#include <stdio.h>
#define TAM 100

void armazenar(float* vet, int* indice, float valor) {
    if (*indice < TAM) {
        vet[*indice] = valor; 
        (*indice)++; 
    } else {
        printf("Vetor cheio! Não é possível armazenar mais valores.\n");
    }
}

void exibir(float* vet){
    for (int i = 0; i < TAM; i++) {
        printf("%.1f ", vet[i]);
    }
    printf("\n"); 
}

float calcular(float* vet, float* vetb) {
    float resultado = 0;
    for (int i = 0; i < TAM; i++) {
        resultado += vet[i] * vetb[i]; 
    }
    return printf("O produto escalar dos dois vetores é %.2f \n", resultado);
}

int main(){
    float veta[TAM] = {0}, vetb[TAM] = {0}; 
    float valor, valorb;
    int indice = 0, indiceb = 0; 

    while (indice < TAM) {
        printf("Digite um valor para armazenar na posição A[%d]: \n", indice);
        scanf("%f", &valor);
        armazenar(veta, &indice, valor);

        printf("Digite um valor para armazenar na posição B[%d]: \n", indiceb);
        scanf("%f", &valorb);
        armazenar(vetb, &indiceb, valorb);
    }
    exibir(veta);
    exibir(vetb);
    calcular(veta, vetb);

    return 0;
}


