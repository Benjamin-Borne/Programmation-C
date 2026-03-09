#include <stdio.h>
#include <stdbool.h>

enum order {
    ASC,
    DESC,
};


void BubbleSort(float TAB[], int n, enum order by) {
    int i, j;
    float temp;
    bool swap;
    
    printf("Tableau entré : ");
    for (i=0; i<n; i++) {
        printf("%.2f ", *(TAB + i));
    }
    puts("");

    for (i=0; i< n; i++) {
        swap = false;
        for (j=0; j < n - i - 1; j++) {
            if ( (by = ASC) && (TAB[j] > TAB[j+1]) ) {
                temp = TAB[j];
                TAB[j] = TAB[j+1];
                TAB[j+1] = temp;
                swap = true;
            } else if ( (by = DESC) && (TAB[j] < TAB[j+1]) ) {
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

    printf("Tableau sortant : ");
    for (i=0; i<30; i++) {
        printf("%.2f ", *(TAB + i));
    }    

}

void MinimalSearchSort(float TAB[], int n, enum order by) {
    int i, j;
    float temp;

    printf("Tableau entré : ");
    for (i=0; i<n; i++) {
        printf("%.2f ", *(TAB + i));
    }

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
    float TAB[] = {25, 1, 17, 34, 23, 16, 13, 27, 4, 44, 50, 14, 10, 7, 41, 15, 21, 35, 0, 49, 24, 9, 37, 20, 36, 8, 39, 31, 3, 18};
    MinimalSearchSort(TAB, 30, DESC);
    return 0;
}