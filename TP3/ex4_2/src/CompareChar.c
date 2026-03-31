#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char compare(long int num1, long int num2) {
    /*
    Fonction pour comparer deux nombres entiers

    Args :
        num1 (long int) : premier nombre entier
        num2 (long int) : deuxième nombre entier

    Return :
        'V' si les nombres sont égaux, 'F' sinon
    */
    if (num1 == num2) {
        return 'V';
    } else {
        return 'F';
    }
}
