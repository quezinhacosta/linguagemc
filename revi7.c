#include <stdio.h> 
#define TAM 5 //30 ALUNOS

void menu(){
    printf("1 - inserir \n");
    printf("2 - média da turma \n");
    printf("3 - exibir notas \n");
    printf("4 - buscar nota \n");
    printf("5 - sair \n");
}

double busca(double* a, double* quant, double nota){
    if(*quant == 0){
        printf("Ainda não há notas! \n");
        return -2;
    }
    for(int i = 0; i < TAM; i++){
        if(a[i] == nota){
            printf("Valor encontrado! Nota = %.2lf na posicão %d", nota, i);
            return i;
        }
    }
    printf("Valor não encontrado... \n");
    return -1;
}
void inserir(double* a, int* quant, double nota){
    if (*quant == TAM){
        printf("Vetor está cheio!");
    }
    for(int i = 0; i < *quant; i++){
        a[*quant] = nota;
        (*quant)++;
    }
}
double media(double* a){
    double soma = 0, media;
    for (int i = 0; i < TAM; i++){
        soma += a[i];
    }
    media = soma/TAM;
    return media;
}
void exibirordenado(double* a, int* quant){
    double aux;
    if (*quant ==  0){
        printf("Vetor vazio! \n");
    }
    for (int i = 0; i < TAM; i++){
        for(int q = 0; q < TAM - i - 1; q++){
            if(a[q] > a[q + 1]){
                aux = a[q];
                a[q] = a[q+1];
                a[q+1] = aux;
            }
        }
    }
    for(int i = 0; i < TAM; i++){
        printf("%lf ", a[i]);
    }
}

int main(){
    double a[TAM], nota, mediar;
    int op, retorno, *quant;

    do { 
        menu();
        printf("Insira uma opção: ");
        scanf("%d", &op);
        switch (op){
            case 1:
                printf("Insira uma nota: ");
                scanf("%lf", &nota);
                retorno = busca(a, *quant, nota);
                if(retorno == -1){
                    inserir(a, *quant, nota);
                }
                else {
                    printf("Valor inválido!");
                }
                break;
            case 2:
                mediar = media(a);
                printf("A média da turma é %.2lf \n", mediar);
                break;
            case 3:
                printf("Notas: \n");
                exibirordenado(a, *quant);
                break;
            case 4: 
                printf("Qual nota está procurando? \n");
                scanf("%lf", &nota);
                busca(a, *quant, nota);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(op != 5);

    return 0;
}
