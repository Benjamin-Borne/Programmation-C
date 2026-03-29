#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int ligne(long nbCol){

    for(int i=0; i<nbCol; i++){
        printf("*");
    }

    return 0;
}

int blank(long nbCol){
    for(int i=0; i<nbCol; i++){
        printf(" ");
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
    char *endptr1, *endptr2;
    long l1, l2;

    puts("Nombres de colonnes : ");
    if (fgets(nbCol, sizeof(nbCol), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }
    nbCol[strcspn(nbCol, "\n")] = '\0';
    puts("Nombres de lignes : ");
    if (fgets(nbLigne, sizeof(nbLigne), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }
    nbLigne[strcspn(nbLigne, "\n")] = '\0';

    errno = 0;
    l1 = strtol(nbLigne, &endptr1, 10);
    l2 = strtol(nbCol, &endptr2, 10);

    if (endptr1 == nbCol || endptr2 == nbLigne) {
        fprintf(stderr, "Entrée invalide : aucun chiffre trouvé\n");
        return 0;
    }

    if (*endptr1 != '\0' || *endptr2 != '\0') {
        fprintf(stderr, "Caractères inattendus après le nombre : '%s' '%s'\n", endptr1, endptr2);
        return 0;
    }
    if (errno == ERANGE) {
        fprintf(stderr, "Valeur hors plage\n");
        return 0;
    }

    if(l1 < (long)1 || l1 > (long)20 || l2 < (long)1 || l2 > (long)20){
        puts("Mauvaise plage ! ");
        return 0;
    }

    for(int i=0; i<l1; i++){
        ligne(l2);
        printf("\n");
    }

    return 0;
}


int secondFig(void){
    char nbMax[4];
    char *endptr1;
    long i = 1;
    long max;

    puts("Nombres max : ");
    if (fgets(nbMax, sizeof(nbMax), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }
    nbMax[strcspn(nbMax, "\n")] = '\0';

    errno = 0;
    max = strtol(nbMax, &endptr1, 10);

    if (endptr1 == nbMax) {
        fprintf(stderr, "Entrée invalide : aucun chiffre trouvé\n");
        return 0;
    }
    if (*endptr1 != '\0') {
        fprintf(stderr, "Caractères inattendus après le nombre : '%s'\n", endptr1);
        return 0;
    }
    if (errno == ERANGE) {
        fprintf(stderr, "Valeur hors plage\n");
        return 0;
    }

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

int thirdFig(void){
    char nbMax[4];
    long i = 1;
    long max;
    char *endptr1;


    puts("Nombres max : ");
    if (fgets(nbMax, sizeof(nbMax), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }
    nbMax[strcspn(nbMax, "\n")] = '\0';

    errno = 0;
    max = strtol(nbMax, &endptr1, 10);

    if (endptr1 == nbMax) {
        fprintf(stderr, "Entrée invalide : aucun chiffre trouvé\n");
        return 0;
    }
    if (*endptr1 != '\0') {
        fprintf(stderr, "Caractères inattendus après le nombre : '%s'\n", endptr1);
        return 0;
    }
    if (errno == ERANGE) {
        fprintf(stderr, "Valeur hors plage\n");
        return 0;
    }

    while(i <= max){
        blank(max - i);
        printStar(i);
        printf("\n");
        i++;
    }

    i = max - 1;

    while(i >= 1){
        blank(max - i);
        printStar(i);
        printf("\n");
        i--;
    }

    return 0;
}


int fourthFig(void){

    char nbMax[4];
    long i = 1;
    long max;
    char *endptr1;


    puts("Nombres max : ");
    if (fgets(nbMax, sizeof(nbMax), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }
    nbMax[strcspn(nbMax, "\n")] = '\0';

    errno = 0;
    max = strtol(nbMax, &endptr1, 10);

    if (endptr1 == nbMax) {
        fprintf(stderr, "Entrée invalide : aucun chiffre trouvé\n");
        return 0;
    }
    if (*endptr1 != '\0') {
        fprintf(stderr, "Caractères inattendus après le nombre : '%s'\n", endptr1);
        return 0;
    }
    if (errno == ERANGE) {
        fprintf(stderr, "Valeur hors plage\n");
        return 0;
    }

    while(i <= max){
        blank(max - i);
        printStar(2 * i - 1);
        printf("\n");
        i++;
    }

    return 0;

}


int fiveFig(void){
    char nbMax[4];
    long i = 1;
    long max;
    char *endptr1;


    puts("Nombres max : ");
    if (fgets(nbMax, sizeof(nbMax), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }
    nbMax[strcspn(nbMax, "\n")] = '\0';

    errno = 0;
    max = strtol(nbMax, &endptr1, 10);

    if (endptr1 == nbMax) {
        fprintf(stderr, "Entrée invalide : aucun chiffre trouvé\n");
        return 0;
    }
    if (*endptr1 != '\0') {
        fprintf(stderr, "Caractères inattendus après le nombre : '%s'\n", endptr1);
        return 0;
    }
    if (errno == ERANGE) {
        fprintf(stderr, "Valeur hors plage\n");
        return 0;
    }

    while(i <= max){
        blank(max - i);
        printStar(2 * i - 1);
        printf("\n");
        i++;
    }

    i = max - 1;

    while(i >= 1){
        blank(max - i);
        printStar(2 * i - 1);
        printf("\n");
        i--;
    }

    return 0;
}



int main(void){
    int c;

    while (1){
        puts("Choix de la figure : ");
        c = fgetc(stdin);

        if (c == EOF) {
            fprintf(stderr, feof(stdin) ? "EOF\n" : "Erreur de lecture\n");
            return -1;
        }

        if (c != '\n') {
            int tmp;
            while ((tmp = getchar()) != '\n' && tmp != EOF);
        }

        if (c < 0x31 || c > 0x35) {
            fprintf(stderr, "Caractère non imprimable\n");
            return -1;
        }

        switch(c){

            case 0x31:
                premiereFig();
                break;

            case 0x32:
                secondFig();
                break;

            case 0x33:
                thirdFig();
                break;

            case 0x34:
                fourthFig();
                break;

            case 0x35:
                fiveFig();
                break;

            default:
                puts("Other Value \n");
                return 0;


        }
    }


}
