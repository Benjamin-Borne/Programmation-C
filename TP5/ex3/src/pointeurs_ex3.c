/*
* TP 5 : Pointeurs
*
* insuffisance des appels de fonction
* avec passage par valeur
*/

#include <stdio.h>

void echanger(int *a, int *b){
    /*
    Fonction d'échange de deux entiers.
    */
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}


int main(void){
    /*
    Fonction main du programme d'échange de pointeurs.
    */
    int x,y;

    x = 12;
    y = 34;

    printf("Avant échange : x = %d ; y = %d\n",x,y);
    echanger(&x,&y);
    printf("Après échange : x = %d ; y = %d\n",x,y);

    return 0;
}

