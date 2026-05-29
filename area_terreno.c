#include <stdio.h>

int main()
{
    float largura = 0;
    float altura = 0;

    printf("Digite a Largura do Terreno:\n");
    scanf("%f", &largura);

    printf("Digite a Altura do Terreno:\n");
    scanf("%f", &altura);

    float area = largura * altura;

    printf("A area do terreno eh:%.2f", area);
    
  
   return 0;
}
