#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "degre.h"


int main(void){
    char *endptr;
    double celsius, kelvin, fahrenheit;
    char input[64];
    puts("Entrez une température en Celsius : ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';

    errno = 0;
    celsius = strtod(input, &endptr);

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

    kelvin = CelsiusAKelvin(celsius);
    fahrenheit = CelsiusAFahrenheit(celsius);

    printf("%.2lf °C = %.2lf K\n", celsius, kelvin);
    printf("%.2lf °C = %.2lf °F\n", celsius, fahrenheit);

    return 0;
}
