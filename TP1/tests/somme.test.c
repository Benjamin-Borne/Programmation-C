#include <stdio.h>
#include <assert.h>
#include "../src/somme.c"

int IncrementLoop(int n);
int DecrementLoop(int n);
int WhileSumIncrement(int n);
int WhileSumDecrement(int n);


void test_increment_normal() {
    assert(IncrementLoop(10) == 55);
    assert(IncrementLoop(5)  == 15);
    assert(IncrementLoop(1)  == 1);
    puts("PASS test_increment_normal");
}

void test_increment_zero() {
    assert(IncrementLoop(0) == 0);
    puts("PASS test_increment_zero");
}


void test_decrement_normal() {
    assert(DecrementLoop(10) == 55);
    assert(DecrementLoop(5)  == 15);
    assert(DecrementLoop(1)  == 1);
    puts("PASS test_decrement_normal");
}

void test_decrement_zero() {
    assert(DecrementLoop(0) == 0);
    puts("PASS test_decrement_zero");
}

void test_while_increment_normal() {
    assert(WhileSumIncrement(10) == 55);
    assert(WhileSumIncrement(5)  == 15);
    assert(WhileSumIncrement(1)  == 1);
    puts("PASS test_while_increment_normal");
}

void test_while_increment_zero() {
    assert(WhileSumIncrement(0) == 0);
    puts("PASS test_while_increment_zero");
}


void test_while_decrement_normal() {
    assert(WhileSumDecrement(10) == 55);
    assert(WhileSumDecrement(5)  == 15);
    assert(WhileSumDecrement(1)  == 1);
    puts("PASS test_while_decrement_normal");
}

void test_while_decrement_zero() {
    assert(WhileSumDecrement(0) == 0);
    puts("PASS test_while_decrement_zero");
}

void test_coherence() {
    for (int n = 0; n <= 50; n++) {
        int ref = IncrementLoop(n);
        assert(DecrementLoop(n)     == ref);
        assert(WhileSumIncrement(n) == ref);
        assert(WhileSumDecrement(n) == ref);
    }
    puts("PASS test_coherence");
}


int main(void) {
    puts("--- Tests IncrementLoop ---");
    test_increment_normal();
    test_increment_zero();

    puts("\n--- Tests DecrementLoop ---");
    test_decrement_normal();
    test_decrement_zero();

    puts("\n--- Tests WhileSumIncrement ---");
    test_while_increment_normal();
    test_while_increment_zero();

    puts("\n--- Tests WhileSumDecrement ---");
    test_while_decrement_normal();
    test_while_decrement_zero();

    puts("\n--- Test coherence globale ---");
    test_coherence();

    puts("\nTous les tests sont passes.");
    return 0;
}