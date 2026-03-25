#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

#define EPSILON 1e-6f

int compare(float num1, float num2) {
    if (fabsf(num1 - num2) < EPSILON) {
        return 1;
    } else {
        return 0;
    }
}

