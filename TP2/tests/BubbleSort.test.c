#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "../src/BubbleSort.c"



bool arrays_equal(float a[], float b[], int n) {
    for (int i = 0; i < n; i++) {
        if (fabs(a[i] - b[i]) > 1e-4f) return false;
    }
    return true;
}

void run_test(const char* name, float input[], float expected[], int n, enum order by) {
    BubbleSort(input, n, by);
    if (arrays_equal(input, expected, n)) {
        printf("[PASS] %s\n", name);
    } else {
        printf("[FAIL] %s\n", name);
        printf("  Obtenu  : ");
        PrintTab(input, n, "");
        printf("  Attendu : ");
        PrintTab(expected, n, "");
    }
}

int mainTest(void) {
    // T1 - Croissant
    { float in[] = {25, 12.3f, 41, 7, 98};
      float ex[] = {7, 12.3f, 25, 41, 98};
      run_test("T1 - Croissant", in, ex, 5, ASC); }

    
    // T2 - Décroissant
    { float in[] = {25, 12.3f, 41, 7, 98};
      float ex[] = {98, 41, 25, 12.3f, 7};
      run_test("T2 - Décroissant", in, ex, 5, DESC); }

    // T3 - Déjà trié 
    { float in[] = {1, 2, 3, 4, 5};
      float ex[] = {1, 2, 3, 4, 5};
      run_test("T3 - Deja tri", in, ex, 5, ASC); }

    // T4 - Inversé
    { float in[] = {5, 4, 3, 2, 1};
      float ex[] = {1, 2, 3, 4, 5};
      run_test("T4 - Inversé", in, ex, 5, ASC); }

    // T5 - Un élément
    { float in[] = {42};
      float ex[] = {42};
      run_test("T5 - Un element", in, ex, 1, ASC); }

    // T6 - Deux éléments
    { float in[] = {9, 3};
      float ex[] = {3, 9};
      run_test("T6 - Deux elements ASC", in, ex, 2, ASC); }

    // T7 - Doublons
    { float in[] = {3, 1, 3, 2};
      float ex[] = {1, 2, 3, 3};
      run_test("T7 - Doublons", in, ex, 4, ASC); }

    // T8 - Négatifs
    { float in[] = {-1, -5, 0, 3};
      float ex[] = {-5, -1, 0, 3};
      run_test("T8 - Negatifs ", in, ex, 4, ASC); }

    // T9 - Flottants
    { float in[] = {1.001f, 1.1f, 1.01f};
      float ex[] = {1.1f, 1.01f, 1.001f};
      run_test("T9 - Flottants ", in, ex, 3, DESC); }

    return 0;
}

