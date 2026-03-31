#include "PrintTab.h"

void MinimalSearchSort(float TAB[], int n, enum order by) {
    /*
    Fonction de tri par sélection pour trier un tableau

    Args :
    TAB : tableau à trier
    n : nombre d'éléments dans le tableau
    by : ordre de tri (ASC pour ascendant, DESC pour descendant)
    */
    int i, j;
    float temp;

    PrintTab(TAB, n, "entré");

    for (i=0; i < 30; i++) {
        for (j=i; j < n; j++) {
            if ( (by == ASC) && (TAB[j] < TAB[i]) ) {
                temp = *(TAB + i);
                TAB[i] = *(TAB + j);
                TAB[j] = temp;
            } else if ( (by == DESC) && (TAB[j] > TAB[i]) ) {
                temp = *(TAB + i);
                TAB[i] = *(TAB + j);
                TAB[j] = temp;
            }
        }
    }

    printf("Tableau sortie : ");
    for (i=0; i<n; i++) {
        printf("%.2f ", *(TAB + i));
    }
}

int main(void) {
    /*
    Fonction main pour tester le tri par sélection
    */
    float TAB[] = {25, 12.3f, 41, 7, 98, 999, 4, 10, 23};
    MinimalSearchSort(TAB, sizeof(TAB)/sizeof(float), ASC);
    return 0;
}