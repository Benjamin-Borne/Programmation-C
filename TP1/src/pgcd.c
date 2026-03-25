#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>


int PGCD(int num1, int num2){

    if ((num1 == 0) || (num2 == 0)) {
        printf("PGCD : %d\n", num1);
        return num2|num1;
    }else{
        while (abs(num1) != abs(num2)){

        if ( abs(num1) < abs(num2) ){
            int result = abs(num2) - abs(num1);
            num2 = result;
        }else {
            int result = abs(num1) - abs(num2);
            num1 = result;
        }

        }
        printf("PGCD : %d\n", num1);
        return num1;
    }
}


int main(){
    int num1, num2;
    long val1, val2;
    char buf1[64], buf2[64];
    char *endptr1, *endptr2;

    printf("Choisir deux nombres : ");
    if(scanf("%63s %63s", buf1, buf2) != 2) {
        puts("Réels invalides. Veuillez saisir des nombres réels valides.");
    }

    int tmp;
    while ((tmp = getchar()) != '\n' && tmp != EOF);

    errno = 0;
    val1 = strtol(buf1, &endptr1, 10);
    val2 = strtol(buf2, &endptr2, 10);

    if (endptr1 == buf1 || endptr2 == buf2) {
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

    if (num1 < INT_MIN || num1 > INT_MAX || num2 < INT_MIN || num2 > INT_MAX) {
        fprintf(stderr, "Entrée invalide ce ne sont pas des entiers");
        return 0;
    }

    num1 = (int)val1;
    num2 = (int)val2;
    PGCD(num1, num2);



}

