#include <stdio.h>
#include <assert.h>
#include "../src/Exo10.c"


void test_cas_normaux() {

    puts("===Cas classique===");
    assert(PGCD(12,8) == 4);
    assert(PGCD(48,18) == 6);
    assert(PGCD(100,75) == 25);
    assert(PGCD(7, 3) == 1);
    
    puts("  [OK] PGCD(a, b) = c");
}

void test_egaux() {
    puts("===Nombre égaux===");

    assert(PGCD(5, 5) == 5);
    assert(PGCD(1, 1) == 1);
    assert(PGCD(0, 0) == 0);
    assert(PGCD(42, 42) == 42);
    
    puts("  [OK] PGCD(n, n) = n");
}

void test_diviseur() {
    puts("L'un divise l'autre");

    assert(PGCD(10, 5) == 5);
    assert(PGCD(5, 10) == 5);
    assert(PGCD(10, 5) == 5);
    assert(PGCD(36, 6) == 6);
    assert(PGCD(6, 36) == 6);
    
    puts("  [OK] PGCD(n*k, n) = n\n");
}


void test_premiers_entre_eux() {
    puts("Nombres premiers entre eux");

    assert(PGCD(13, 7) == 1);
    assert(PGCD(17, 5) == 1);
    assert(PGCD(8, 9) == 1);
    assert(PGCD(35, 64) == 1);
    
    puts("  [OK] PGCD = 1 (premiers entre eux)\n");
}

void test_commutativite() {
    puts("Commutativite PGCD(a,b) == PGCD(b,a)");

    assert(PGCD(12, 8)  == PGCD(8,  12));
    assert(PGCD(100, 3) == PGCD(3,  100));
    assert(PGCD(77, 14) == PGCD(14, 77));
    
    puts("  [OK] PGCD(a,b) == PGCD(b,a)\n");
}

void test_cas_limites_notes() {
    puts("Cas limites");

    assert(PGCD(6, 0) == 6);
    assert(PGCD(0, 6) == 6);

    
    puts("  [OK] PGCD(n, 0) => n)\n");

    assert(PGCD(-12, 8) == 4);

    printf("  [!!] PGCD(negatif, n) => boucle infinie (bug : pas de valeur absolue)\n");

    assert(PGCD(1, 100) == 1);
    printf("  [OK] PGCD(1, n) = 1 (fonctionne mais lent pour grands n)\n");
}

int main(void) {
    printf("==========================================\n");
    printf("        TESTS PGCD\n");
    printf("==========================================\n");

    test_cas_normaux();
    test_egaux();
    test_diviseur();
    test_premiers_entre_eux();
    test_commutativite();
    test_cas_limites_notes();

    printf("\n==========================================\n");
    printf("   TOUS LES TESTS SONT PASSES !\n");
    printf("==========================================\n");
    return 0;
}