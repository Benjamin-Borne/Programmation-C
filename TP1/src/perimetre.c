#include "stdio.h"
#include <math.h>

#define PI 3.14159f

float circumference(float radius) {
    /*
    Fonction pour calculer le périmètre d'un cercle à partir de son rayon

    Args :
    radius : rayon du cercle

    Return :
    périmètre du cercle
    */
    float circum = 2.0f*PI*radius;

    return circum;
}

float surface(float radius) {
    /*
    Fonction pour calculer l'aire d'un cercle à partir de son rayon

    Args :
    radius : rayon du cercle

    Return :
    aire du cercle
    */
    float surf = PI * radius * radius;

    return surf;
}


int main(void) {
    /*
    Fonction main pour tester les fonctions précédentes
    */
    float radius = 4.0f;

    printf("Radius: %.2f\n", radius);
    printf("Périmètre: %.2f\n", circumference(radius));
    printf("Aire: %.2f\n", surface(radius));

    return 0;
}
