#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int compare(long int num1, long int num2) {
    if (num1 == num2) {
        return 1;
    } else {
        return 0;
    }
}
