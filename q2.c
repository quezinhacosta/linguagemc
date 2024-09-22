#include <stdio.h>

#define LANCAMENTOS 1000000
#define FACES 6
#define PERCENTUAL_ESPERADO 16.0
#define MARGEM_ERRO 1.0

int jogarDado() {
    return (unsigned int)(123456789 * 214013 + 2531011) % FACES + 1;
}

void simulacao(int* vetor) {
    for (int i = 0; i < LANCAMENTOS; i++) {
        int face = jogarDado();
        vetor[face - 1]++;
    }
}

void resultado(int* vetor) {
    for (int i = 0; i < FACES; i++) {
        printf("Face %d apareceu %d vezes.\n", i + 1, vetor[i]);
    }
}

int dadoviciado(int* vetor) {
    for (int i = 0; i < FACES; i++) {
        float percentual = (vetor[i] / (float)LANCAMENTOS) * 100;
        if (percentual < (PERCENTUAL_ESPERADO - MARGEM_ERRO) || 
            percentual > (PERCENTUAL_ESPERADO + MARGEM_ERRO)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int vetor[FACES] = {0};

    simulacao(vetor);
    resultado(vetor);

    if (dadoviciado(vetor)) {
        printf("O dado é viciado.\n");
    } else {
        printf("O dado não é viciado.\n");
    }

    return 0;
}
