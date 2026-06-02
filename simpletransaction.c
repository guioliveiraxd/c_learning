#include <stdio.h>

int main()
{
    double unitario, recebido, troco, quantidadecomprada;
    
    printf("Quanto custa o item comprado?:\n");
    scanf("%lf", &unitario);

    printf("E quantos ele comprou?: \n");
    scanf("%lf", &quantidadecomprada);

    printf("Com quanto ele pagou?: \n");
    scanf("%lf", &recebido);

    troco = recebido - (unitario * quantidadecomprada);

    printf("Valor unitario: %.2f\n", unitario);
    printf("Qntd comprada: %.2f\n", quantidadecomprada);
    printf("Recebido: %.2f\n", recebido);
    printf("TROCO = : %.2f\n", troco);


    return 0;
}
