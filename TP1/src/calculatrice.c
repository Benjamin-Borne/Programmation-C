#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_FLT_SIZE 64

float calculatrice_if(float num1, float num2, char op) {
    float result;


    if (op == '+') {
        result = num1 + num2;
    }
    else if (op == '-') {
        result = num1 - num2;
    }
    else if (op == '*') {
        result = num1 * num2;
    }
    else if (op == '/') {
        if (num2 == 0) {
            printf("Erreur : division par zero !\n");
            result = NAN;
        }else {
            result = num1 / num2;
        }
    }
    else {
        printf("Operation non valide !\n");
        result = 0;
    }

    return result;
}


float calculatrice_case(float num1, float num2, char op){
    if (op == 's') {
        return 0;
    }

    switch(op) {

        case '+':
            return num1 + num2;
            break;

        case '-':
            return num1 - num2;
            break;

        case '*':
            return num1 * num2;
            break;

        case '/':
            if (num2 == 0) {
                    puts("Division par zéro !");
                    return NAN;
                }
            return num1 / num2;
            break;
        default:
            puts("Other Value \n");
            return 0;

    }
}


int main(){

    char op;
    char buf1[MAX_FLT_SIZE], buf2[MAX_FLT_SIZE];
    float f1, f2;
    char *endptr1, *endptr2;


    while (1) {
        puts("Entrez une operation (+, -, *, /) ou 's' : ");

        if (scanf(" %c", &op) != 1) {
            printf("\nErreur, entrez un un opérateur valide (+, -, *, /) ou 's'\n");
        }

        if (op == 's') {
            return 0;
        }

        puts("Entrez deux nombres : ");

        if(scanf("%63s %63s", buf1, buf2) != 2) {
            puts("Réels invalides. Veuillez saisir des nombres réels valides.");
        }

        int tmp;
        while ((tmp = getchar()) != '\n' && tmp != EOF);

        errno = 0;
        f1 = strtof(buf1, &endptr1);
        f2 = strtof(buf2, &endptr2);

        if (endptr1 == buf1 || endptr2 == buf2) {
            fprintf(stderr, "Entrée invalide : aucun chiffre trouvé\n");
            continue;
        }
        if (*endptr1 != '\0' || *endptr2 != '\0') {
            fprintf(stderr, "Caractères inattendus après le nombre : '%s' '%s'\n", endptr1, endptr2);
            continue;
        }
        if (errno == ERANGE) {
            fprintf(stderr, "Valeur hors plage\n");
            continue;
        }

        puts(" ----- Calculatrice IF ----\n");

        printf("Resultat = %.2f\n\n", calculatrice_if(f1,f2,op));

        puts(" ----- Calculatrice CASE ----\n");

        printf("Résultat : %.2f\n", calculatrice_case(f1, f2, op));
    }
    return 0;
}
