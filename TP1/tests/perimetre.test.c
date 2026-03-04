#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../src/perimetre.c"

#define PI 3.14159f
#define EPSILON 0.001f

float circumference(float radius);
float surface(float radius);

int float_eq(float a, float b) {
    return fabsf(a - b) < EPSILON;
}


void test_circumference_normal() {
    assert(float_eq(circumference(1.0f), 2.0f * PI));
    puts("PASS test_circumference_normal");
}

void test_circumference_zero() {
    assert(float_eq(circumference(0.0f), 0.0f));
    puts("PASS test_circumference_zero");
}

void test_circumference_large() {
    assert(float_eq(circumference(100.0f), 2.0f * PI * 100.0f));
    puts("PASS test_circumference_large");
}

void test_circumference_decimal() {
    assert(float_eq(circumference(2.5f), 2.0f * PI * 2.5f));
    puts("PASS test_circumference_decimal");
}


void test_surface_normal() {
    assert(float_eq(surface(1.0f), PI));
    puts("PASS test_surface_normal");
}

void test_surface_zero() {
    assert(float_eq(surface(0.0f), 0.0f));
    puts("PASS test_surface_zero");
}

void test_surface_large() {
    assert(float_eq(surface(100.0f), PI * 100.0f * 100.0f));
    puts("PASS test_surface_large");
}

void test_surface_decimal() {
    assert(float_eq(surface(3.5f), PI * 3.5f * 3.5f));
    puts("PASS test_surface_decimal");
}


int main(void) {
    puts("\n--- Tests circumference ---");
    test_circumference_normal();
    test_circumference_zero();
    test_circumference_large();
    test_circumference_decimal();

    puts("\n--- Tests surface ---");
    test_surface_normal();
    test_surface_zero();
    test_surface_large();
    test_surface_decimal();

    puts("Tous les tests sont passes.");
    return 0;
}