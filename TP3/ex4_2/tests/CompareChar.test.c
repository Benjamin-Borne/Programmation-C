#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include "../src/CompareInt.c"

int main(void) {
    // Cas égaux
    assert(compare(0, 0) == 'V');
    assert(compare(5, 5) == 'V');
    assert(compare(-5, -5) == 'V');
    assert(compare(LONG_MAX, LONG_MAX) == 'V');
    assert(compare(LONG_MIN, LONG_MIN) == 'V');

    // Cas différents
    assert(compare(5, 3) == 'F');
    assert(compare(3, 5) == 'F');
    assert(compare(-5, 5) == 'F');
    assert(compare(0, 1) == 'F');
    assert(compare(LONG_MAX, LONG_MIN) == 'F');

    printf("Tous les tests sont passés avec succès !\n");
    return 0;
}