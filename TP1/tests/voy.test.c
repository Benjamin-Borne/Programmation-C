#include <stdio.h>
#include <assert.h>
#include "../src/voy.c"

int nbVoy(char *p);

// ---- Tests nbVoy ----

void test_voyelles_minuscules() {
    assert(nbVoy("aeiou#") == 5);
    assert(nbVoy("aeiouy#") == 6);
    printf("PASS test_voyelles_minuscules\n");
}

void test_voyelles_majuscules() {
    assert(nbVoy("AEIOU#") == 5);
    assert(nbVoy("AEIOUY#") == 6);
    printf("PASS test_voyelles_majuscules\n");
}

void test_mixte_majmin() {
    assert(nbVoy("AeIoUy#") == 6);
    assert(nbVoy("BoNjOuR#") == 3);
    printf("PASS test_mixte_majmin\n");
}

void test_aucune_voyelle() {
    assert(nbVoy("bcdfg#") == 0);
    assert(nbVoy("xz#") == 0);
    printf("PASS test_aucune_voyelle\n");
}

void test_que_consonnes() {
    assert(nbVoy("nnnn#") == 0);
    printf("PASS test_que_consonnes\n");
}

void test_chaine_vide() {
    assert(nbVoy("#") == 0);
    printf("PASS test_chaine_vide\n");
}

void test_phrase_normale() {
    // "Bonjour" → o, o, u = 3
    assert(nbVoy("Bonjour#") == 3);
    // "Hello World" → e, o, o = 3
    assert(nbVoy("Hello World#") == 3);
    printf("PASS test_phrase_normale\n");
}

void test_chiffres_et_speciaux() {
    // Chiffres et caractères spéciaux ne sont pas des voyelles
    assert(nbVoy("123!?#") == 0);
    assert(nbVoy("a1b2c3#") == 1);
    printf("PASS test_chiffres_et_speciaux\n");
}

void test_repetition_voyelles() {
    assert(nbVoy("aaaa#") == 4);
    assert(nbVoy("EEEE#") == 4);
    printf("PASS test_repetition_voyelles\n");
}

void test_y_compte_comme_voyelle() {
    assert(nbVoy("y#") == 1);
    assert(nbVoy("Y#") == 1);
    assert(nbVoy("yYyY#") == 4);
    printf("PASS test_y_compte_comme_voyelle\n");
}

// ---- Runner ----

int main(void) {
    printf("=== Tests nbVoy ===\n");
    test_voyelles_minuscules();
    test_voyelles_majuscules();
    test_mixte_majmin();
    test_aucune_voyelle();
    test_que_consonnes();
    test_chaine_vide();
    test_phrase_normale();
    test_chiffres_et_speciaux();
    test_repetition_voyelles();
    test_y_compte_comme_voyelle();

    printf("\nTous les tests sont passes.\n");
    return 0;
}