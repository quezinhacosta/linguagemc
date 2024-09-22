#include <stdio.h>

void menu(){
    printf("A -  adicão \n");
    printf("B - subtração \n");
    printf("C -  divisão \n");
    printf("D - multiplicação \n");
    printf("E - Nenhuma das opções \n");
}

float calcular(float a, float b, char resp){
    float adicao = 0 , sub= 0, div= 0, mult= 0;
    if(resp == 'A'){
        adicao = a+b;
        printf("O resultado da soma é %.2f \n", adicao);
        return adicao;
    }
    if(resp == 'B'){
        sub = a-b;
        printf("O resultado da subtração é %.2f \n", sub);
        return sub;
    }
    if(resp == 'C'){
        if (b == 0){
            printf("A divisão não pode ser efetuada! \n");
        }
        else{
            div = a/b;
            printf("O resultado da divisão é %.2f \n", div);
            return div;
        }
    }
    if(resp == 'D'){
        mult = a*b;
        printf("O resultado da multiplicação é %.2f \n", mult);
        return mult;
    }

}

int main(){
    float a, b;
    char resp, nov;
    do{
        printf("Valor de a: ");
        scanf("%f", &a);
        printf("Valor de b: ");
        scanf("%f", &b);

        menu();
        printf("Qual opção deseja? ");
        scanf(" %c", &resp);

        calcular(a, b, resp);

        printf("Deseja calcular novamente? (s/n) ");
        scanf(" %c", &nov);
    } while (nov == 's');
    
    return 0;
}
