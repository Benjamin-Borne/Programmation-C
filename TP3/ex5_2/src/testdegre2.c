#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../../ex5_1/src/degre.h"

long lireChoix() {
    int choix;
    puts("Choisissez une conversion :");
    puts("1. Celsius à Kelvin");
    puts("2. Celsius à Fahrenheit");
    puts("3. Kelvin à Celsius");
    puts("4. Kelvin à Fahrenheit");
    puts("5. Fahrenheit à Celsius");
    puts("6. Fahrenheit à Kelvin");
    puts("7. Quitter");
    puts("Votre choix : ");
    scanf("%d", &choix);
    return choix;
}

void executerChoix(int choix) {
    double temp;
    puts("Entrez la température à convertir : ");
    scanf("%lf", &temp);
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