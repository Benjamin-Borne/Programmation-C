#include <stdio.h>

int main(){
    /*
    Programme pour tester les opérateurs arithmétiques et la priorité des opérateurs
    */
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