#include <stdio.h>

int main()
{
    float largura = 0;
    float altura = 0;
    float valormetroquadrado = 0;

    printf("Digite o valor do metro quadrado:\n");
    scanf("%f", &valormetroquadrado);

    printf("Digite a Largura do Terreno:\n");
    scanf("%f", &largura);

    printf("Digite a Altura do Terreno:\n");
    scanf("%f", &altura);

    float area = largura * altura;
    float valorterreno = valormetroquadrado * area;

    printf("Area do terreno:%.2f\n", area);
    printf("Valor terreno:%.2f", valorterreno);

  
   return 0;
}
