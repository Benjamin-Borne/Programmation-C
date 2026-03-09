#include "PrintTab.h"

void MinimalSearchSort(float TAB[], int n, enum order by) {
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
    float TAB[] = {25, 12.3f, 41, 7, 98, 999, 4, 10, 23};
    MinimalSearchSort(TAB, sizeof(TAB)/sizeof(float), ASC);
    return 0;
}