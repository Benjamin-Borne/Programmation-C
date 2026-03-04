#include <stdio.h>
#include <assert.h>
#include "../src/voy.c"

int nbVoy(char *p);


void test_voyelles_minuscules() {
    assert(nbVoy("aeiou#") == 5);
    assert(nbVoy("aeiouy#") == 6);
    puts("PASS test_voyelles_minuscules");
}

void test_voyelles_majuscules() {
    assert(nbVoy("AEIOU#") == 5);
    assert(nbVoy("AEIOUY#") == 6);
    puts("PASS test_voyelles_majuscules");
}

void test_mixte_majmin() {
    assert(nbVoy("AeIoUy#") == 6);
    assert(nbVoy("BoNjOuR#") == 3);
    puts("PASS test_mixte_majmin");
}

void test_aucune_voyelle() {
    assert(nbVoy("bcdfg#") == 0);
    assert(nbVoy("xz#") == 0);
    puts("PASS test_aucune_voyelle");
}

void test_que_consonnes() {
    assert(nbVoy("nnnn#") == 0);
    puts("PASS test_que_consonnes");
}

void test_chaine_vide() {
    assert(nbVoy("#") == 0);
    puts("PASS test_chaine_vide");
}

void test_phrase_normale() {
    assert(nbVoy("Bonjour#") == 3);
    assert(nbVoy("Hello World#") == 3);
    puts("PASS test_phrase_normale");
}

void test_chiffres_et_speciaux() {
    assert(nbVoy("123!?#") == 0);
    assert(nbVoy("a1b2c3#") == 1);
    puts("PASS test_chiffres_et_speciaux");
}

void test_repetition_voyelles() {
    assert(nbVoy("aaaa#") == 4);
    assert(nbVoy("EEEE#") == 4);
    puts("PASS test_repetition_voyelles");
}

void test_y_compte_comme_voyelle() {
    assert(nbVoy("y#") == 1);
    assert(nbVoy("Y#") == 1);
    assert(nbVoy("yYyY#") == 4);
    puts("PASS test_y_compte_comme_voyelle");
}



int main(void) {
    puts("=== Tests nbVoy ===");
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

    puts("\nTous les tests sont passes.");
    return 0;
}