#include "stdio.h"
#include <stdint.h>

int IncrementLoop(int n) {
    
    int sum = 0;
    for(int i=1; i<=n; i++) {
        sum += i;
    }

    return sum;
}

int DecrementLoop(int n) {
    int sum = 0;

    for (int i = n; i>=1; i--) {
        sum += i;
    }

    return sum;
}

int WhileSumIncrement(int n) {
    int sum = 0;
    int i = 1;

    while (i<=n) {
        sum += i;
        i++;
    }

    return sum;
}

int WhileSumDecrement(int n) {
    int sum = 0;
    int i = n;

    while (i>0) {
        sum += i;
        i--;
    }

    return sum;
}


int main (void) {
    printf("Somme for incrémentation: %d\n", IncrementLoop(10));
    printf("Somme for décrémentation: %d\n", DecrementLoop(10));
    printf("Somme While Incrementation: %d\n", WhileSumIncrement(10));
    printf("Somme While Decrementation: %d\n", WhileSumDecrement(10));

    return 0;
}

