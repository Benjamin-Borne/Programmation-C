#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include "../src/calculatrice.c"

#define EPSILON 1e-4f

void assert_float(float a, float b) {
    assert(fabsf((a) - (b)) < EPSILON);
} 

// ─── Tests calculatrice_if ────────────────────────────────────────────────────

void test_if_addition() {
    puts("Test Addition");
    assert_float(calculatrice_if(3.0f, 2.0f, '+'), 5.0f);
    assert_float(calculatrice_if(0.0f, 0.0f, '+'), 0.0f);
    assert_float(calculatrice_if(-1.0f, 1.0f, '+'), 0.0f);
    assert_float(calculatrice_if(1.5f, 2.5f, '+'), 4.0f);
    // Test valeur extrême
    assert(isinf(calculatrice_if(FLT_MAX, FLT_MAX, '+')));
    //Test NaN
    assert(isnan(calculatrice_if(NAN, 2.0f, '+')));
    assert(isnan(calculatrice_if(2.0f, NAN, '+')));
    assert(isnan(calculatrice_if(NAN, NAN, '+')));
    
    puts("  [OK] if -> addition");
}

void test_if_soustraction() {
    assert_float(calculatrice_if(5.0f, 3.0f, '-'), 2.0f);
    assert_float(calculatrice_if(0.0f, 0.0f, '-'), 0.0f);
    assert_float(calculatrice_if(1.0f, 5.0f, '-'), -4.0f);
    assert_float(calculatrice_if(-3.0f, -2.0f, '-'), -1.0f);
    //Test NaN
    assert(isnan(calculatrice_if(NAN, 2.0f, '-')));
    assert(isnan(calculatrice_if(2.0f, NAN, '-')));
    assert(isnan(calculatrice_if(NAN, NAN, '-')));
    puts("  [OK] if -> soustraction");
}

void test_if_multiplication() {
    assert_float(calculatrice_if(3.0f, 4.0f, '*'), 12.0f);
    assert_float(calculatrice_if(0.0f, 99.0f, '*'), 0.0f);
    assert_float(calculatrice_if(-2.0f, 3.0f, '*'), -6.0f);
    assert_float(calculatrice_if(-2.0f, -3.0f, '*'), 6.0f);
    //Test NaN
    assert(isnan(calculatrice_if(NAN, 2.0f, '*')));
    assert(isnan(calculatrice_if(2.0f, NAN, '*')));
    assert(isnan(calculatrice_if(NAN, NAN, '*')));

    puts("  [OK] if -> multiplication");
}

void test_if_division() {
    assert_float(calculatrice_if(10.0f, 2.0f, '/'), 5.0f);
    assert_float(calculatrice_if(7.0f, 3.0f, '/'), 2.3333f);
    assert_float(calculatrice_if(-9.0f, 3.0f, '/'), -3.0f);
    assert(isnan(calculatrice_if(2.0f, 0.0f, '/')));
    //Test NaN
    assert(isnan(calculatrice_if(NAN, 2.0f, '-')));
    assert(isnan(calculatrice_if(2.0f, NAN, '-')));
    assert(isnan(calculatrice_if(NAN, NAN, '-')));
    puts("  [OK] if -> division");
}

void test_if_operateur_invalide() {
    assert_float(calculatrice_if(5.0f, 3.0f, '?'), 0.0f);
    assert_float(calculatrice_if(5.0f, 3.0f, 'z'), 0.0f);
    puts("  [OK] if -> opérateur invalide");
}

// ─── Tests calculatrice_case ──────────────────────────────────────────────────

void test_case_addition() {
    assert_float(calculatrice_case(3.0f, 2.0f, '+'), 5.0f);
    assert_float(calculatrice_case(0.0f, 0.0f, '+'), 0.0f);
    assert_float(calculatrice_case(-1.0f, 1.0f, '+'), 0.0f);
    assert_float(calculatrice_case(1.5f, 2.5f, '+'), 4.0f);
    //Test NanN
    assert(isnan(calculatrice_case(NAN, 2.0f, '+')));
    assert(isnan(calculatrice_case(2.0f, NAN, '+')));
    assert(isnan(calculatrice_case(NAN, NAN, '+')));
    puts("  [OK] case -> addition");
}

void test_case_soustraction() {
    assert_float(calculatrice_case(5.0f, 3.0f, '-'), 2.0f);
    assert_float(calculatrice_case(0.0f, 0.0f, '-'), 0.0f);
    assert_float(calculatrice_case(1.0f, 5.0f, '-'), -4.0f);
    assert_float(calculatrice_case(-3.0f, -2.0f, '-'), -1.0f);
    //Test NaN
    assert(isnan(calculatrice_case(NAN, 2.0f, '-')));
    assert(isnan(calculatrice_case(2.0f, NAN, '-')));
    assert(isnan(calculatrice_case(NAN, NAN, '-')));
    
    puts("  [OK] case -> soustraction");
}

void test_case_multiplication() {
    assert_float(calculatrice_case(3.0f, 4.0f, '*'), 12.0f);
    assert_float(calculatrice_case(0.0f, 99.0f, '*'), 0.0f);
    assert_float(calculatrice_case(-2.0f, 3.0f, '*'), -6.0f);
    assert_float(calculatrice_case(-2.0f, -3.0f, '*'), 6.0f);
    puts("  [OK] case -> multiplication");
}

void test_case_division() {
    assert_float(calculatrice_case(10.0f, 2.0f, '/'), 5.0f);
    assert_float(calculatrice_case(7.0f, 2.0f, '/'), 3.5f);
    assert_float(calculatrice_case(-9.0f, 3.0f, '/'), -3.0f);
    assert(isnan(calculatrice_case(2.0f, 0.0f, '/')));
    //Test NaN
    assert(isnan(calculatrice_if(NAN, 2.0f, '/')));
    assert(isnan(calculatrice_if(2.0f, NAN, '/')));
    assert(isnan(calculatrice_if(NAN, NAN, '/')));

    puts("  [OK] case -> division");
}

void test_case_operateur_stop() {
    assert_float(calculatrice_case(99.0f, 99.0f, 's'), 0.0f);
    puts("  [OK] case -> opérateur 's'");
}

void test_case_operateur_invalide() {
    assert_float(calculatrice_case(5.0f, 3.0f, '?'), 0.0f);
    assert_float(calculatrice_case(5.0f, 3.0f, 'z'), 0.0f);
    puts("  [OK] case -> opérateur invalide (default)");
}

int MainTest(void) {

    puts("=== Tests calculatrice_if ===");
    test_if_addition();
    test_if_soustraction();
    test_if_multiplication();
    test_if_division();
    test_if_operateur_invalide();

    puts("=== Tests calculatrice_case ===");
    test_case_addition();
    test_case_soustraction();
    test_case_multiplication();
    test_case_division();
    test_case_operateur_stop();
    test_case_operateur_invalide();

    puts(">>> Tous les tests sont passes !");
    return 0;
}
