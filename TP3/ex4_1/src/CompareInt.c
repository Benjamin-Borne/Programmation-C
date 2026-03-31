#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int compare(long int num1, long int num2) {
    /*
    Programme pour comparer deux nombres entiers

    Args : 
        num1 (long int) : premier nombre entier
        num2 (long int) : deuxième nombre entier
    
    Return :
    1 si les nombres sont égaux, 0 sinon
    */
    if (num1 == num2) {
        return 1;
    } else {
        return 0;
    }
}
