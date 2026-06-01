#include <stdio.h>

long potencia_recursiva(int base, int exp) {

    // Caso Base
    if(exp == 0)
        return 1;

    // Chamada Recursiva
    return base * potencia_recursiva(base, exp - 1);
}

int main() {

    int base, exp;

    printf("Base: ");
    scanf("%d", &base);

    printf("Expoente: ");
    scanf("%d", &exp);

    printf("Resultado = %ld\n",
           potencia_recursiva(base, exp));

    return 0;
}
