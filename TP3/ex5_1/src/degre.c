#include <stdio.h>      
#include "degre.h"


int main(void){
    double celsius, kelvin, fahrenheit;

    puts("Entrez une température en Celsius : ");
    scanf("%lf", &celsius);

    kelvin = CelsiusAKelvin(celsius);
    fahrenheit = CelsiusAFahrenheit(celsius);

    printf("%.2lf °C = %.2lf K\n", celsius, kelvin);
    printf("%.2lf °C = %.2lf °F\n", celsius, fahrenheit);

    return 0;
}