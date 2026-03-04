#include <stdio.h>
#include <assert.h>
#include "../src/puissance.c"

int puissance(int x, int n);

// ---- Tests puissance ----

void test_puissance_normal() {
    assert(puissance(2, 3) == 8);
    assert(puissance(3, 2) == 9);
    assert(puissance(5, 4) == 625);
    printf("PASS test_puissance_normal\n");
}

void test_puissance_exposant_un() {
    assert(puissance(7, 1) == 7);
    assert(puissance(1, 1) == 1);
    printf("PASS test_puissance_exposant_un\n");
}

void test_puissance_base_un() {
    assert(puissance(1, 5) == 1);
    assert(puissance(1, 100) == 1);
    printf("PASS test_puissance_base_un\n");
}

void test_puissance_zero_base() {
    // x=0 → retourne 0 (condition x>0 non remplie)
    assert(puissance(0, 3) == 0);
    printf("PASS test_puissance_zero_base\n");
}

void test_puissance_zero_exposant() {
    // n=0 → retourne 0 (condition n>0 non remplie)
    // Note: mathématiquement x^0 = 1, mais la fonction retourne 0
    assert(puissance(2, 0) == 0);
    printf("PASS test_puissance_zero_exposant\n");
}

void test_puissance_negatif_base() {
    // x<0 → retourne 0 (condition x>0 non remplie)
    assert(puissance(-2, 3) == 0);
    printf("PASS test_puissance_negatif_base\n");
}

void test_puissance_negatif_exposant() {
    // n<0 → retourne 0 (condition n>0 non remplie)
    assert(puissance(2, -1) == 0);
    printf("PASS test_puissance_negatif_exposant\n");
}

// ---- Runner ----

int main(void) {
    printf("=== Tests puissance ===\n");
    test_puissance_normal();
    test_puissance_exposant_un();
    test_puissance_base_un();
    test_puissance_zero_base();
    test_puissance_zero_exposant();
    test_puissance_negatif_base();
    test_puissance_negatif_exposant();

    printf("\nTous les tests sont passes.\n");
    return 0;
}