#include <stdio.h>
#define TAM 6

int busca(int* a, int quant, int valor){
    if(quant == 0){
        printf("O vetor está vazio! \n");
        return -2;
    }
    for(int i = 0; i < TAM; i++){
        if(a[i] == valor){
            printf("Valor já existe! Está na posição %d \n", i);
            return i;
        }
    }
    printf("Valor não encontrado! \n");
    return -1;
}

void armazenar(int* a, int* quant, int valor){
    int repetido, i;
    if (*quant == TAM){
        printf("Vetor cheio! \n");
    }
    else {
        repetido = busca(*a, *quant, valor);
        if(repetido != i){
            a[*quant] = valor;
            (*quant)++;
            printf("Valor inserido! \n");
        }
        else{
            printf("Inserção não realizada! \n");
        }
    }
}

void menu(){
    printf("Escolha uma opção abaixo: \n");
    printf("1 - inserir \n");
    printf("2 - exibir \n");
    printf("3 - buscar \n");
    printf("4 - nenhuma das opções \n");
}

void exibir(int* a, int quant){
    int i;
    printf("%d ", a[i]);
    printf("Esse vetor possui %d quantidades preenchidas \n", quant);
}

int main(){
    int a[TAM], b[TAM], quanta = 0 , quantb = 0, valor, op;

    menu();
    scanf("%d ", &op);
    switch (op){

        case '1':
        printf("Digite um número: ");
        scanf("%d", &valor);
        if(valor % 2 == 0){
            armazenar(a, quanta, valor);
            quanta += 1;
            printf("O valor foi armazenado no vetor de números pares! \n");
        }
        else{
            armazenar(b, quantb, valor);
            quantb += 1;
            printf("O valor foi armazenado no vetor de números ímpares! \n");
        }

        case '2':
        printf("Vetor de pares: \n");
        exibir(a, quanta);
        printf("Vetor de ímpares: \n");
        exibir(b, quantb);

        case '4':
        printf("Acabou! \n");
        break;
    }

    return 0;
}