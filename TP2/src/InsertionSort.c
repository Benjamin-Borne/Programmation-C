#include "PrintTab.h"

void InsertionSort(float TAB[], int n, enum order by) {
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
    float TAB[] = {25, 12.3f, 41, 7, 98, 999, 4, 10, 23};
    InsertionSort(TAB, sizeof(TAB)/sizeof(float), ASC);
    return 0;
}