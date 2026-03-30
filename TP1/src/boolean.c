#include <stdio.h>

int main(){
    /*
    Programme pour tester les opérateurs logiques et binaires
    */

    // ET binaire
    printf(" 5 & 6 = %d\n", 5&6);

    // ET logique
    printf(" 5 && 6 = %d\n", 5 && 6);

    // OU binaire
    printf(" 5 | 6 = %d\n", 5|6);

    // OU logique
    printf(" 5 || 6 = %d\n", 5||6);

    // XOR binaire
    printf(" 5^6 = %d\n", 5^6);


    printf(" !5 != !6 = %d\n", !5 != !6);

    // complément binaire
    printf(" ~5 = %d\n", ~5);

    // NON logique
    printf(" !5 = %d\n", !5);

    return 0;

}