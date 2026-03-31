#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

#define EPSILON 1e-6f

int compare(float num1, float num2) {
    /*
    Fonction pour comparer deux nombres float

    Args :
        num1 (float) : premier nombre float
        num2 (float) : deuxième nombre float

    Return :   
        1 si les nombres sont égaux, 0 sinon
    */
    if (fabsf(num1 - num2) < EPSILON) {
        return 1;
    } else {
        return 0;
    }
}
