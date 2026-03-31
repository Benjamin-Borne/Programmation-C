#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "../src/FloatCompareChar.c"


int main(void) {
    /*
    Fonction main pour comparer deux nombres float
    */
    char res;
    char num1[32], num2[32];
    char *end1, *end2;

    puts("Choisir deux nombres : ");
    fgets(num1, sizeof(num1), stdin);
    fgets(num2, sizeof(num2), stdin);

    errno = 0;
    float val1 = strtof(num1, &end1);
    if (errno == ERANGE || end1 == num1 || (*end1 != '\0' && *end1 != '\n')) {
        fprintf(stderr, "Erreur : saisie invalide pour le premier nombre\n");
        return 1;
    }

    errno = 0;
    float val2 = strtof(num2, &end2);
    if (errno == ERANGE || end2 == num2 || (*end2 != '\0' && *end2 != '\n')) {
        fprintf(stderr, "Erreur : saisie invalide pour le deuxième nombre\n");
        return 1;
    }

    res = compare(val1, val2);
    printf("Résultat : %c\n", res);
    return 0;
}