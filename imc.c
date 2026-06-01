#include <stdio.h>

float calcular_imc(float p, float a) {
    return p / (a * a);
}

void imprimir_resultado(float imc) {

    printf("\nIMC = %.2f\n", imc);

    if(imc < 18.5)
        printf("Abaixo do peso\n");

    else if(imc < 25)
        printf("Peso normal\n");

    else if(imc < 30)
        printf("Sobrepeso\n");

    else
        printf("Obesidade\n");
}

int main() {

    float peso, altura;
    float imc;

    printf("Peso: ");
    scanf("%f", &peso);

    printf("Altura: ");
    scanf("%f", &altura);

    imc = calcular_imc(peso, altura);

    imprimir_resultado(imc);

    return 0;
}
