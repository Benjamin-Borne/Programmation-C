#include <stdio.h>


enum order {
    ASC,
    DESC,
};


inline int PrintTab(float TAB[], int n, char *entry) {
    printf("Tableau %s : ", entry);
    for (int i=0; i<n; i++) {
        printf("%.2f ", *(TAB + i));
    }
    puts("");

    return 0;
}