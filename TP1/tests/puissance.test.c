#include <stdio.h>
#include <assert.h>
#include "../src/puissance.c"

int puissance(int x, int n);


void test_puissance_normal() {
    assert(puissance(2, 3) == 8);
    assert(puissance(3, 2) == 9);
    assert(puissance(5, 4) == 625);
    puts("PASS test_puissance_normal");
}

void test_puissance_exposant_un() {
    assert(puissance(7, 1) == 7);
    assert(puissance(1, 1) == 1);
    puts("PASS test_puissance_exposant_un");
}

void test_puissance_base_un() {
    assert(puissance(1, 5) == 1);
    assert(puissance(1, 100) == 1);
    puts("PASS test_puissance_base_un");
}

void test_puissance_zero_base() {
    assert(puissance(0, 3) == 0);
    puts("PASS test_puissance_zero_base");
}

void test_puissance_zero_exposant() {
    assert(puissance(2, 0) == 0);
    puts("PASS test_puissance_zero_exposant");
}

void test_puissance_negatif_base() {
    assert(puissance(-2, 3) == 0);
    puts("PASS test_puissance_negatif_base");
}

void test_puissance_negatif_exposant() {
    assert(puissance(2, -1) == 0);
    puts("PASS test_puissance_negatif_exposant");
}



int main(void) {
    puts("--- Tests puissance ---");
    test_puissance_normal();
    test_puissance_exposant_un();
    test_puissance_base_un();
    test_puissance_zero_base();
    test_puissance_zero_exposant();
    test_puissance_negatif_base();
    test_puissance_negatif_exposant();

    puts("\nTous les tests sont passes.\n");
    return 0;
}