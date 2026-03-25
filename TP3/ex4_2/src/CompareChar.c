#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char compare(long int num1, long int num2) {
    if (num1 == num2) {
        return 'V';
    } else {
        return 'F';
    }
}

