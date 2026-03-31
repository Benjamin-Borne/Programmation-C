#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "../src/CompareChar.c"


int main(void) {
    /*
    Fonction main pour comparer deux nombres entiers
    */
    char res;
    char num1[12], num2[12];
    char *end1, *end2;

    puts("Choisir deux nombres : ");
    fgets(num1, sizeof(num1), stdin);
    fgets(num2, sizeof(num2), stdin);

    errno = 0;
    long val1 = strtol(num1, &end1, 10);
    if (errno == ERANGE || end1 == num1 || (*end1 != '\0' && *end1 != '\n')) {
        fprintf(stderr, "Erreur : saisie invalide pour le premier nombre\n");
        return 1;
    }

    errno = 0;
    long val2 = strtol(num2, &end2, 10);
    if (errno == ERANGE || end2 == num2 || (*end2 != '\0' && *end2 != '\n')) {
        fprintf(stderr, "Erreur : saisie invalide pour le deuxième nombre\n");
        return 1;
    }

    res = compare(val1, val2);
    printf("Résultat : %c\n", res);
    return 0;
}