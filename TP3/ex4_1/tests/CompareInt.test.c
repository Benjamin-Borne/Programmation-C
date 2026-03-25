#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include "../src/CompareInt.c"

int main(void) {
    // Cas égaux
    assert(compare(0, 0) == 1);
    assert(compare(5, 5) == 1);
    assert(compare(-5, -5) == 1);
    assert(compare(LONG_MAX, LONG_MAX) == 1);
    assert(compare(LONG_MIN, LONG_MIN) == 1);

    // Cas différents
    assert(compare(5, 3) == 0);
    assert(compare(3, 5) == 0);
    assert(compare(-5, 5) == 0);
    assert(compare(0, 1) == 0);
    assert(compare(LONG_MAX, LONG_MIN) == 0);

    printf("Tous les tests sont passés avec succès !\n");
    return 0;
}