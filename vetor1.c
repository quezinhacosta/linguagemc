#include <stdio.h>
#define TAM 3

void adicionar(double* vetor, int* qtd, double valor) {
    if (*qtd >= TAM) {
        printf("Não tem espaço no vetor.\n");
        return;
    }

    for (int i = 0; i < *qtd; i++) {
        if (vetor[i] == valor) {
            printf("O valor %.2f já tá no vetor!\n", valor);
            return;
        }
    }

    int i = *qtd;
    while (i > 0 && vetor[i - 1] < valor) {
        vetor[i] = vetor[i - 1];
        i--;
    }
    vetor[i] = valor;
    (*qtd)++;
}

int procurar(double vetor[], int qtd, double valor) {
    if (qtd == 0) {
        return -2;
    }
    for (int i = 0; i < qtd; i++) {
        if (vetor[i] == valor) {
            return i;
        }
        if (vetor[i] < valor) {
            return -1;
        }
    }
    return qtd;
}

void remover(double vetor[], int *qtd, double valor) {
    int i = procurar(vetor, *qtd, valor);
    if (i == -2) {
        printf("O vetor tá vazio.\n");
        return;
    } else if (i == -1) {
        printf("Não achei o valor %.2f no vetor.\n", valor);
        return;
    }

    for (; i < *qtd - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    (*qtd)--;
    printf("O valor %.2f foi removido do vetor.\n", valor);
}

void mostrarVetor(double vetor[], int qtd) {
    if (qtd == 0) {
        printf("O vetor tá vazio.\n");
        return;
    }

    printf("Valores no vetor:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%.2f ", vetor[i]);
    }
    printf("\n");
}

int main() {
    double vetor[TAM], valor;
    int quantidade = 0, opcao;

    do {
        printf("Escolha uma opção:\n");
        printf("1. Adicionar valor\n");
        printf("2. Remover valor\n");
        printf("3. Mostrar vetor\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Insira um valor: ");
                scanf("%lf", &valor);
                adicionar(vetor, &quantidade, valor);
                break;
            case 2:
                printf("Insira o valor a ser removido: ");
                scanf("%lf", &valor);
                remover(vetor, &quantidade, valor);
                break;
            case 3:
                mostrarVetor(vetor, quantidade);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
