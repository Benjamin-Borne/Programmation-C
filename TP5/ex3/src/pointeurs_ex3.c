/*
* TP 5 : Pointeurs
*
* insuffisance des appels de fonction
* avec passage par valeur
*/

#include <stdio.h>

void echanger(int *a, int *b){
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}


int main(void){
    int x,y;

    x = 12;
    y = 34;

    printf("Avant échange : x = %d ; y = %d\n",x,y);
    echanger(&x,&y);
    printf("Après échange : x = %d ; y = %d\n",x,y);

    return 0;
}

