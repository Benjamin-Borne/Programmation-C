#include <stdio.h>
int puissance(int x, int n) {
    int power = 1;
    if ( (x>0) && (n>0)) {
        for (int i=0; i<n; i++) {
            power *= x;
        }

        return power;
    }

    return 0;
}


int main(void) {
    printf("Puissance de 2 au cube: %d\n", puissance(2, 3));

    return 0;
}
