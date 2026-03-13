/*
* TP 5 : Pointeurs
*
* lecture de l'adresse des éléments d'un tableau
*/
#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(void){ 
    int *px;

    px = (int *) malloc(sizeof(int));
    *px = 1;

    printf("Adresse de px : %p\n", (void*)&px);
    printf("Adresse pointee par le pointeur px = %p\n", (void*)px);
    printf("Valeur memorisee a l'adresse pointee par le pointeur px = %d\n\n", *px);

    free(px);
    
    return 0;
}