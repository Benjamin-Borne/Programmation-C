#include "stdio.h"
#include <math.h>

#define PI 3.14159f

float circumference(float radius) {
    float circum = 2.0f*PI*radius;

    return circum;
}

float surface(float radius) {
    float surf = PI * radius * radius;

    return surf;
}

<<<<<<< HEAD
/*
=======

>>>>>>> ben
int main(void) {
    float radius = 4.0f;

    printf("Radius: %.2f\n", radius);
    printf("Périmètre: %.2f\n", circumference(radius));
    printf("Aire: %.2f\n", surface(radius));

    return 0;
<<<<<<< HEAD
}*/
=======
}
>>>>>>> ben
