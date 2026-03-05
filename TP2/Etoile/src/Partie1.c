#include <stdio.h>
#include <stdlib.h>

int ligne(long nbCol){

    for(int i=0; i<nbCol; i++){
        printf("*");
    }

    return 0;
}

int printStar(long nbStar){
    for(int i=0; i<nbStar; i++){
        printf("*");
    }

    return 0;
}


int premiereFig(void){
    char nbCol[4], nbLigne[4];

    puts("Nombres de colonnes : ");
    fgets(nbCol, sizeof(nbCol), stdin);

    puts("Nombres de lignes : ");
    fgets(nbLigne, sizeof(nbLigne), stdin);

    if(strtol(nbLigne, NULL, 10) < (long)1 || strtol(nbLigne, NULL, 10) > (long)20 || strtol(nbCol, NULL, 10) < (long)1 || strtol(nbCol, NULL, 10) > (long)20){
        puts("Mauvaise plage ! ");
        return 0;
    }

    for(int i=0; i<strtol(nbLigne, NULL, 10); i++){
        ligne(strtol(nbCol, NULL, 10));
        printf("\n");
    } 

    return 0;
}


int secondFig(void){
    char nbMax[4];
    long i = 1;

    puts("Nombres max : ");
    fgets(nbMax, sizeof(nbMax), stdin);

    long max = strtol(nbMax, NULL, 10);

    while(i <= max){
        printStar(i);
        printf("\n");   
        i++;
    }

    i = max - 1;

    while(i >= 1){
        printStar(i);
        printf("\n");
        i--;
    }

    return 0;
}




int main(void){
    char choix[4];

    while (1){
        puts("Choix de la figure : ");
        fgets(choix, sizeof(choix), stdin);

        switch(strtol(choix, NULL, 10)){

            case 1:
                premiereFig();
                break;

            case 2: 
                secondFig();
                break;


            default:
                puts("Other Value \n");
                return 0;


        }
    }


}