#include <stdio.h>
int main(void) {

    int a;
    char b;
    float c;
    short d;

    printf("\n\tint = %d\n", sizeof(int));
    printf("\n\ttchar = %d\n", sizeof(char));
    printf("\n\tfloat = %d\n", sizeof(float));
    printf("\n\tdouble = %d\n", sizeof(double));
    printf("\n\tshort = %d\n", sizeof(short));



    printf("\n\tint = %d\n", sizeof a);
    printf("\n\tchar = %d\n", sizeof b);
    printf("\n\tfloat = %d\n", sizeof c);
    printf("\n\tshort = %d\n", sizeof d);
    
    return 0;
}
