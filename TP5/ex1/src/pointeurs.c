/*
* TP 5 : Pointeurs
*
* lecture de l'adresse des éléments d'un tableau
*/
#include <stdio.h>
#define N 5

int main(){
    int i;
    double t[N] = {10.0, 20.0, 30.0, 40.0, 50.0};
    for(i = 0; i < N; i++){
        printf("t[%d] = %.1f ; &t[%d] = %p\n", i, t[i], i, (void*)&t[i]);
    }
    return 0;
}