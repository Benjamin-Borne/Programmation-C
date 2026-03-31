#include "stdio.h"
#include <stdint.h>

int IncrementLoop(int n) {
    /*
    Fonction pour calculer la somme des entiers de 1 à n

    Args :
    n : entier positif

    Return :
    somme des entiers de 1 à n
    */

    int sum = 0;
    for(int i=1; i<=n; i++) {
        sum += i;
    }

    return sum;
}

int DecrementLoop(int n) {
    /*
    Fonction pour calculer la somme des entiers de n à 1

    Args :
    n : entier positif
    
    Return :
    somme des entiers de n à 1
    */
    int sum = 0;

    for (int i = n; i>=1; i--) {
        sum += i;
    }

    return sum;
}

int WhileSumIncrement(int n) {
    /*
    Fonction pour calculer la somme des entiers de 1 à n en utilisant une boucle while

    Args :
    n : entier positif

    Return :
    somme des entiers de 1 à n
    */
    int sum = 0;
    int i = 1;

    while (i<=n) {
        sum += i;
        i++;
    }

    return sum;
}

int WhileSumDecrement(int n) {
    /*
    Fonction pour calculer la somme des entiers de n à 1 en utilisant une boucle while

    Args :
    n : entier positif

    Return :
    somme des entiers de n à 1
    */
    int sum = 0;
    int i = n;

    while (i>0) {
        sum += i;
        i--;
    }

    return sum;
}


int main (void) {
    /*
    Fonction main pour tester les fonctions de somme
    */
    printf("Somme for incrémentation: %d\n", IncrementLoop(10));
    printf("Somme for décrémentation: %d\n", DecrementLoop(10));
    printf("Somme While Incrementation: %d\n", WhileSumIncrement(10));
    printf("Somme While Decrementation: %d\n", WhileSumDecrement(10));

    return 0;
}
