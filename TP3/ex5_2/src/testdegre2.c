#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "../../ex5_1/src/degre.h"

int lireChoix() {
    int choix;
    char *endptr;
    char input[10];

    puts("Choisissez une conversion :");
    puts("1. Celsius à Kelvin");
    puts("2. Celsius à Fahrenheit");
    puts("3. Kelvin à Celsius");
    puts("4. Kelvin à Fahrenheit");
    puts("5. Fahrenheit à Celsius");
    puts("6. Fahrenheit à Kelvin");
    puts("7. Quitter");
    puts("Votre choix : ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';

    errno = 0;
    choix = (int)strtol(input, &endptr, 10);

    if (endptr == input) {
        fprintf(stderr, "Entrée invalide : aucun chiffre trouvé\n");
        return -1;
    }
    if (*endptr != '\0') {
        fprintf(stderr, "Caractères inattendus après le nombre : '%s'\n", endptr);
        return -1;
    }
    if (errno == ERANGE) {
        fprintf(stderr, "Valeur hors plage\n");
        return -1;
    }

    return choix;
}

void executerChoix(int choix) {
    double temp;
    char *endptr;
    char input[32];

    if (choix < 0) {
        fprintf(stderr, "Le choix est incorrect");
        return;
    }

    puts("Entrez la température à convertir : ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return;
    }
    input[strcspn(input, "\n")] = '\0';

    errno = 0;
    temp = strtod(input, &endptr);

    if (endptr == input) {
        fprintf(stderr, "Entrée invalide : aucun chiffre trouvé\n");
        return;
    }
    if (*endptr != '\0') {
        fprintf(stderr, "Caractères inattendus après le nombre : '%s'\n", endptr);
        return;
    }
    if (errno == ERANGE) {
        fprintf(stderr, "Valeur hors plage\n");
        return;
    }

    switch (choix) {
        case 1:
            printf("%.2lf °C = %.2lf K\n",  temp, CelsiusAKelvin(temp));
            break;
        case 2:
            printf("%.2lf °C = %.2lf °F\n", temp, CelsiusAFahrenheit(temp));
            break;
        case 3:
            printf("%.2lf K = %.2lf °C\n", temp, KelvinACelsius(temp));
            break;
        case 4:
            printf("%.2lf K = %.2lf °F\n",  temp, KelvinAFahrenheit(temp));
            break;
        case 5:
            printf("%.2lf °F = %.2lf °C\n", temp, FahrenheitACelsius(temp));
            break;
        case 6:
            printf("%.2lf °F = %.2lf K\n",  temp, FahrenheitAKelvin(temp));
            break;
        case 7:
            exit(0);
            break;
        default:
            puts("Choix invalide.");
    }
}

int main(void) {
    while (1) {
        int choix = lireChoix();
        if (choix == 7){
            exit(0);
        } 
        executerChoix(choix);
    }
}
