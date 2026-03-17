#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../../ex5_1/src/degre.h"

long lireChoix() {
    char choix[4];
    puts("Choisissez une conversion :");
    puts("1. Celsius à Kelvin");
    puts("2. Celsius à Fahrenheit");
    puts("3. Kelvin à Celsius");
    puts("4. Kelvin à Fahrenheit");
    puts("5. Fahrenheit à Celsius");
    puts("6. Fahrenheit à Kelvin");
    puts("Votre choix : ");
    fgets(choix, sizeof(choix), stdin);
    return strtol(choix, NULL, 10);
}

void executerChoix(long choix) {
    char temp[4];
    puts("Température à convertir : ");
    fgets(temp, sizeof(temp), stdin);
    long t = strtol(temp, NULL, 10);  // converti une seule fois
    switch (choix) {                  // choix est déjà un long
        case 1:
            printf("%ld °C = %ld K\n",  t, CelsiusAKelvin(t));
            break;
        case 2:
            printf("%ld °C = %ld °F\n", t, CelsiusAFahrenheit(t));
            break;
        case 3:
            printf("%ld K = %ld °C\n",  t, KelvinACelsius(t));
            break;
        case 4:
            printf("%ld K = %ld °F\n",  t, KelvinAFahrenheit(t));
            break;
        case 5:
            printf("%ld °F = %ld °C\n", t, FahrenheitACelsius(t));
            break;
        case 6:
            printf("%ld °F = %ld K\n",  t, FahrenheitAKelvin(t));
            break;
        default:
            puts("Choix invalide.");
    }
}

int main(void) {
    while (1) {
        long choix = lireChoix();
        executerChoix(choix);
    }
}