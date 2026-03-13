#include <stdio.h>

void echangerPointeurs(int **ppa, int **ppb){
    int *tmp;

    tmp  = *ppa;
    *ppa = *ppb;
    *ppb = tmp;
}


int main(void){
    int x, y;
    int *px, *py;

    x = 12; 
    y = 34;

    px = &x; 
    py = &y;

    printf("Avant échange : x = %d ; y = %d\n", x, y);
    echangerPointeurs(&px, &py);
    printf("Après échange : *px = %d ; *py = %d\n", *px, *py);

    return 0;
}