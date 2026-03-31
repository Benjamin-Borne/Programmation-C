#include <stdio.h>

void echangerPointeurs(int **ppa, int **ppb){
    /*
    Permet d'échanger les pointeurs de deux entiers.

    Args :
        ppa : adresse du pointeur vers le premier entier
        ppb : adresse du pointeur vers le second entier
    */
    int *tmp;

    tmp  = *ppa;
    *ppa = *ppb;
    *ppb = tmp;
}


int main(void){
    /*
    Fonction main du programme d'échange de pointeurs.
    */
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