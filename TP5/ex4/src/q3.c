#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define N 3

typedef struct maillon{
    int x;
    struct maillon *suiv;    
} maillon;

void supprimerMaillon(maillon *lc, maillon *tete, int valeur){
    lc = tete;
    maillon *prec = NULL;

    while (lc != NULL && lc->x != valeur){
        prec = lc;
        lc = lc->suiv;
    }
    
    if (lc == NULL){
        printf("La valeur n'existe pas dans la liste\n");
        return;
    }

    if (prec == NULL){
        tete = lc->suiv;
    }else{
        prec->suiv = lc->suiv;
    }
    
    free(lc);
}

int main(){
    maillon *lc;
    maillon *tete;
    int cpt;

    lc = (maillon*)malloc(sizeof(maillon));
    tete = lc;

    for(cpt=1; cpt<N; cpt++){
        lc->suiv = (maillon*)malloc(sizeof(maillon));
        lc = lc->suiv;
    }
    lc->suiv = NULL;

    cpt = 0;
    lc = tete;

    while (lc != NULL)
    {
        lc->x = cpt;
        cpt++;
        lc = lc->suiv;
    }
    lc = tete;

    while (lc != NULL){
        printf("Valeur du champs courant = %d \n",lc->x);
        printf("Adresse maillon courant= %p et du suivant %p\n", (void*)lc, (void*)lc->suiv);
        lc = lc->suiv;
    }   

    while (1){
        puts(" ----------------------\n");
        printf("Entrez une valeur a supprimer : ");
        scanf("%d", &cpt);
        if (cpt == -1){
            break;
        }
        printf("Vous avez choisi de supprimer la valeur %d\n", cpt);
        supprimerMaillon(lc, tete, cpt);
        lc = tete;

        while (lc != NULL){
            printf("Valeur du champs courant = %d \n",lc->x);
            printf("Adresse maillon courant= %p et du suivant %p\n", (void*)lc, (void*)lc->suiv);
            lc = lc->suiv;
        }  
    }


    return 0;    
    
}