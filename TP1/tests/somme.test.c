#include <stdio.h>
#include <assert.h>
#include "../src/somme.c"

int IncrementLoop(int n);
int DecrementLoop(int n);
int WhileSumIncrement(int n);
int WhileSumDecrement(int n);

// Formule de Gauss : n*(n+1)/2
int gauss(int n) {
    return n * (n + 1) / 2;
}

// ---- Tests IncrementLoop ----

void test_increment_normal() {
    assert(IncrementLoop(10) == 55);
    assert(IncrementLoop(5)  == 15);
    assert(IncrementLoop(1)  == 1);
    printf("PASS test_increment_normal\n");
}

void test_increment_zero() {
    assert(IncrementLoop(0) == 0);
    printf("PASS test_increment_zero\n");
}

void test_increment_gauss() {
    for (int n = 1; n <= 100; n++)
        assert(IncrementLoop(n) == gauss(n));
    printf("PASS test_increment_gauss\n");
}

// ---- Tests DecrementLoop ----

void test_decrement_normal() {
    assert(DecrementLoop(10) == 55);
    assert(DecrementLoop(5)  == 15);
    assert(DecrementLoop(1)  == 1);
    printf("PASS test_decrement_normal\n");
}

void test_decrement_zero() {
    assert(DecrementLoop(0) == 0);
    printf("PASS test_decrement_zero\n");
}

void test_decrement_gauss() {
    for (int n = 1; n <= 100; n++)
        assert(DecrementLoop(n) == gauss(n));
    printf("PASS test_decrement_gauss\n");
}

// ---- Tests WhileSumIncrement ----

void test_while_increment_normal() {
    assert(WhileSumIncrement(10) == 55);
    assert(WhileSumIncrement(5)  == 15);
    assert(WhileSumIncrement(1)  == 1);
    printf("PASS test_while_increment_normal\n");
}

void test_while_increment_zero() {
    assert(WhileSumIncrement(0) == 0);
    printf("PASS test_while_increment_zero\n");
}

void test_while_increment_gauss() {
    for (int n = 1; n <= 100; n++)
        assert(WhileSumIncrement(n) == gauss(n));
    printf("PASS test_while_increment_gauss\n");
}

// ---- Tests WhileSumDecrement ----

void test_while_decrement_normal() {
    assert(WhileSumDecrement(10) == 55);
    assert(WhileSumDecrement(5)  == 15);
    assert(WhileSumDecrement(1)  == 1);
    printf("PASS test_while_decrement_normal\n");
}

void test_while_decrement_zero() {
    assert(WhileSumDecrement(0) == 0);
    printf("PASS test_while_decrement_zero\n");
}

void test_while_decrement_gauss() {
    for (int n = 1; n <= 100; n++)
        assert(WhileSumDecrement(n) == gauss(n));
    printf("PASS test_while_decrement_gauss\n");
}

// ---- Cohérence entre les 4 fonctions ----

void test_coherence() {
    for (int n = 0; n <= 50; n++) {
        int ref = IncrementLoop(n);
        assert(DecrementLoop(n)     == ref);
        assert(WhileSumIncrement(n) == ref);
        assert(WhileSumDecrement(n) == ref);
    }
    printf("PASS test_coherence\n");
}

// ---- Runner ----

int main(void) {
    printf("=== Tests IncrementLoop ===\n");
    test_increment_normal();
    test_increment_zero();
    test_increment_gauss();

    printf("\n=== Tests DecrementLoop ===\n");
    test_decrement_normal();
    test_decrement_zero();
    test_decrement_gauss();

    printf("\n=== Tests WhileSumIncrement ===\n");
    test_while_increment_normal();
    test_while_increment_zero();
    test_while_increment_gauss();

    printf("\n=== Tests WhileSumDecrement ===\n");
    test_while_decrement_normal();
    test_while_decrement_zero();
    test_while_decrement_gauss();

    printf("\n=== Test coherence globale ===\n");
    test_coherence();

    printf("\nTous les tests sont passes.\n");
    return 0;
}