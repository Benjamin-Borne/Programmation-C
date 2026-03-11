#include <stdio.h>
#include <assert.h>
#include "../../ex5_1/src/degre.h"


int lireChoix() {
    int choix;
    puts("Choisissez une conversion :\n");
    puts("1. Celsius à Kelvin\n");
    puts("2. Celsius à Fahrenheit\n");
    puts("3. Kelvin à Celsius\n");
    puts("4. Kelvin à Fahrenheit\n");
    puts("5. Fahrenheit à Celsius\n");
    puts("6. Fahrenheit à Kelvin\n");
    puts("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}

void executerChoix(int choix) {
    char temp[4];

    puts("Température à convertir : ");
    fgets(temp, sizeof(temp), stdin);
    switch (choix) {
        case 1:
            printf("%.2f °C = %.2f K\n", temp, CelsiusAKelvin(strtol(temp, NULL, 10)));
            break;
        case 2:
            printf("%.2f °C = %.2f °F\n", temp, CelsiusAFahrenheit(strtol(temp, NULL, 10)));
            break;
        case 3:
            printf("%.2f K = %.2f °C\n", temp, KelvinACelsius(strtol(temp, NULL, 10)));
            break;
        case 4:
            printf("%.2f K = %.2f °F\n", temp, KelvinAFahrenheit(strtol(temp, NULL, 10)));
            break;
        case 5:
            printf("%.2f °F = %.2f °C\n", temp, FahrenheitACelsius(strtol(temp, NULL, 10)));
            break;
        case 6:
            printf("%.2f °F = %.2f K\n", temp, FahrenheitAKelvin(strtol(temp, NULL, 10)));
            break;
        default:
            puts("Choix invalide.");
    }
}


void main(void){
    while (1){
        int choix = lireChoix();
        executerChoix(choix);
    }
}