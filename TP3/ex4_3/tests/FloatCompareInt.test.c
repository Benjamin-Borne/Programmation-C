#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include "../src/FloatCompareInt.c"

int main(void) {
    // Cas égaux
    assert(compare(0.0f, 0.0f) == 1);
    assert(compare(5.0f, 5.0f) == 1);
    assert(compare(-5.0f, -5.0f) == 1);
    assert(compare(1.0000001f, 1.0000001f) == 1);

    // Cas dans l'epsilon 
    assert(compare(1.0f, 1.0000001f) == 1);
    assert(compare(0.0f, 0.0000001f) == 1);

    // Cas différents
    assert(compare(5.0f, 3.0f) == 0);
    assert(compare(3.0f, 5.0f) == 0);
    assert(compare(-5.0f, 5.0f) == 0);
    assert(compare(0.0f, 1.0f) == 0);
    assert(compare(1.0f, 1.001f) == 0);

    // Cas limites
    assert(compare(FLT_MAX, FLT_MAX) == 1);
    assert(compare(FLT_MAX, -FLT_MAX) == 0);

    printf("Tous les tests sont passés avec succès !\n");
    return 0;
}