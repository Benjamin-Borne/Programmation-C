#include <stdio.h>

int main(){
    int X;
    X = -3 + 4 * 5 - 6;
    printf("Valeur : %d\n", X);

    X = 0;
    X = (-3 + 4) * 5 - 6;
    printf("Valeur : %d\n", X);

    X = 0;
    X = -3 + (4*5) - 6;
    printf("Valeur : %d\n", X);

    X = 0;
    X = -3 + 4 * (5-6);
    printf("Valeur : %d\n", X);

    return 0;

}