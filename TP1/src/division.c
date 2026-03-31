#include <stdio.h>

int main () {
    /*
    Fonction principale pour tester les différentes façons de faire une division en C
    */
    printf("X = %d\n", 10/3);
    // Calcul d'abord en int puis cast le résultat en float d'où le 3.0000000...
    printf("X = %f\n", (float)(10/3));
    printf("X = %f\n", 10.0/3);
    printf("X = %f\n", 10.0/3.0);
    printf("X = %f\n", (float)10/3);
    printf("X = %f\n", ((float)10)/3);
    printf("X = %.1f\n", ((float)10)/3);
    printf("X = %.5f\n", ((float)10)/3);

    return 0;
}