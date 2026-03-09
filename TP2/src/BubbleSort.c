#include <stdbool.h>
#include "PrintTab.h"

void BubbleSort(float TAB[], int n, enum order by) {
    int i, j;
    float temp;
    bool swap;

    PrintTab(TAB, n, "entré");
    for (i=0; i< n; i++) {
        swap = false;
        for (j=0; j < n - i - 1; j++) {
            if ( (by = ASC) && (TAB[j] < TAB[j+1]) ) {
                temp = TAB[j];
                TAB[j] = TAB[j+1];
                TAB[j+1] = temp;
                swap = true;
            } else if ( (by = DESC) && (TAB[j] > TAB[j+1]) ) {
                temp = TAB[j];
                TAB[j] = TAB[j+1];
                TAB[j+1] = temp;
                swap = true;
            }
        }

        if (swap == false) {
            break;
        }
    }

    PrintTab(TAB, n, "sortant");
}

int main(void) {
    float TAB[] = {25, 12.3f, 41, 7, 98, 999, 4, 10, 23};
    BubbleSort(TAB, sizeof(TAB)/sizeof(float), ASC);
    return 0;
}