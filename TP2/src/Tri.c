#include <stdio.h>
#include <stdbool.h>

void BubbleSort(float TAB[30]) {
    int i, j;
    float temp;
    bool swap;
    
    printf("Tableau entré : ");
    for (i=0; i<30; i++) {
        printf("%.2f ", *(TAB + i));
    }
    puts("");

    for (i=0; i< 30; i++) {
        swap = false;
        for (j=0; j < 30 - i - 1; j++) {
            if (TAB[j] > TAB[j+1]) {
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

int main(void) {
    float TAB[] = {25, 1, 17, 34, 23, 16, 13, 27, 4, 44, 50, 14, 10, 7, 41, 15, 21, 35, 0, 49, 24, 9, 37, 20, 36, 8, 39, 31, 3, 18};
    BubbleSort(TAB);
    return 0;
}