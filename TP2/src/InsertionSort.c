#include "PrintTab.h"

void InsertionSort(float TAB[], int n, enum order by) {
    /*
    Fonction de tri par insertion pour trier un tableau

    Args :
    TAB : tableau à trier
    n : nombre d'éléments dans le tableau
    by : ordre de tri (ASC pour ascendant, DESC pour descendant)
    */
    int i, j;
    float current;
    
    PrintTab(TAB, n, "entré");

    for (i = 1; i < n; ++i) {
        current = TAB[i];
        j = i - 1;

        while ( ((j >= 0 && TAB[j] > current) && (by == ASC)) || ((j >= 0 && TAB[j] < current) && (by == DESC))) {
            TAB[j + 1] = TAB[j];
            j = j - 1;
        }

        TAB[j + 1] = current;
    }

    PrintTab(TAB, n, "sortant");
}

int main(void) {
    /*
    FOnction main pour tester le tri par insertion
    */
    float TAB[] = {25, 12.3f, 41, 7, 98, 999, 4, 10, 23};
    InsertionSort(TAB, sizeof(TAB)/sizeof(float), ASC);
    return 0;
}