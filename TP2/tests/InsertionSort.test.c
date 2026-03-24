#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "../src/InsertionSort.c"

bool arrays_equal(float a[], float b[], int n) {
    for (int i = 0; i < n; i++) {
        if (fabs(a[i] - b[i]) > 1e-4f) return false;
    }
    return true;
}

void run_test(const char* name, float input[], float expected[], int n, enum order by) {
    InsertionSort(input, n, by);
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

    // T1 - Croissant basique
    { float in[] = {25, 12.3f, 41, 7, 98};
      float ex[] = {7, 12.3f, 25, 41, 98};
      run_test("T1 - Croissant", in, ex, 5, ASC); }

    // T2 - Décroissant basique
    { float in[] = {25, 12.3f, 41, 7, 98};
      float ex[] = {98, 41, 25, 12.3f, 7};
      run_test("T2 - Decroissant", in, ex, 5, DESC); }

    // T3 - Déjà trié ASC
    { float in[] = {1, 2, 3, 4, 5};
      float ex[] = {1, 2, 3, 4, 5};
      run_test("T3 - Deja trie ASC", in, ex, 5, ASC); }

    // T4 - Tableau inversé → ASC
    { float in[] = {5, 4, 3, 2, 1};
      float ex[] = {1, 2, 3, 4, 5};
      run_test("T4 - Inverse vers ASC", in, ex, 5, ASC); }

    // T5 - Un seul élément
    { float in[] = {42};
      float ex[] = {42};
      run_test("T5 - Un element", in, ex, 1, ASC); }

    // T6 - Deux éléments ASC
    { float in[] = {9, 3};
      float ex[] = {3, 9};
      run_test("T6 - Deux elements ASC", in, ex, 2, ASC); }

    // T7 - Deux éléments DESC
    { float in[] = {3, 9};
      float ex[] = {9, 3};
      run_test("T7 - Deux elements DESC", in, ex, 2, DESC); }

    // T8 - Doublons ASC
    { float in[] = {3, 1, 3, 2};
      float ex[] = {1, 2, 3, 3};
      run_test("T8 - Doublons ASC", in, ex, 4, ASC); }

    // T9 - Nombres négatifs ASC
    { float in[] = {-1, -5, 0, 3};
      float ex[] = {-5, -1, 0, 3};
      run_test("T9 - Negatifs ASC", in, ex, 4, ASC); }

    // T10 - Flottants DESC
    { float in[] = {1.001f, 1.1f, 1.01f};
      float ex[] = {1.1f, 1.01f, 1.001f};
      run_test("T10 - Flottants DESC", in, ex, 3, DESC); }

    // T11 - Tableau du main() original ASC
    { float in[] = {25, 12.3f, 41, 7, 98, 999, 4, 10, 23};
      float ex[] = {4, 7, 10, 12.3f, 23, 25, 41, 98, 999};
      run_test("T11 - Tableau original ASC", in, ex, 9, ASC); }

    // T12 - Tableau du main() original DESC
    { float in[] = {25, 12.3f, 41, 7, 98, 999, 4, 10, 23};
      float ex[] = {999, 98, 41, 25, 23, 12.3f, 10, 7, 4};
      run_test("T12 - Tableau original DESC", in, ex, 9, DESC); }

    // T13 - Tous identiques
    { float in[] = {5, 5, 5, 5};
      float ex[] = {5, 5, 5, 5};
      run_test("T13 - Tous identiques", in, ex, 4, ASC); }

    // T14 - Valeurs négatives et positives DESC
    { float in[] = {-3, 7, -1, 0, 4};
      float ex[] = {7, 4, 0, -1, -3};
      run_test("T14 - Mix negatifs DESC", in, ex, 5, DESC); }

    return 0;
}