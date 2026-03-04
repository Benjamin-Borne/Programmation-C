#include "stdio.h"

#define PI 3.14159f

float circumference(float radius) {
    float circum = 2.0f*PI*radius;

    return circum;
}

float surface(float radius) {
    float surf = PI * radius * radius;

    return surf;
}

int main(void) {
    float radius = 4.0f;

    printf("Radius: %f\n", radius);
    printf("Périmètre: %f\n", circumference(radius));
    printf("Aire: %f\n", surface(radius));

    return 0;
}