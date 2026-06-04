#include <stdio.h>
int main(void) {

    double r, area;
    printf("\n\tDigite o valor do raio do circulo: \n");
    scanf("%lf", &r);

    area = 3.14159 * r * r;

    printf("AREA = %.3f", area);

    return 0;
}

