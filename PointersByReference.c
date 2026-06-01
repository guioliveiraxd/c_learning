#include <stdio.h>

void inverter_e_menor(int *a, int *b, int *menor) {

    if(*a < *b)
        *menor = *a;
    else
        *menor = *b;

    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int x = 10;
    int y = 20;
    int m;

    inverter_e_menor(&x, &y, &m);

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("menor = %d\n", m);

    return 0;
}
