#include <assert.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "../src/FloatCompareChar.c"

int main(void) {
    // Cas égaux
    assert(compare(0.0f, 0.0f) == 'V');
    assert(compare(5.0f, 5.0f) == 'V');
    assert(compare(-5.0f, -5.0f) == 'V');

    // Cas dans l'epsilon 
    assert(compare(1.0f, 1.0000001f) == 'V');
    assert(compare(0.0f, 0.0000001f) == 'V');

    // Cas différents
    assert(compare(5.0f, 3.0f) == 'F');
    assert(compare(3.0f, 5.0f) == 'F');
    assert(compare(-5.0f, 5.0f) == 'F');
    assert(compare(0.0f, 1.0f) == 'F');
    assert(compare(1.0f, 1.001f) == 'F');

    // Cas limites
    assert(compare(FLT_MAX, FLT_MAX) == 'V');
    assert(compare(FLT_MAX, -FLT_MAX) == 'F');

    printf("Tous les tests sont passés avec succès !\n");
    return 0;
}