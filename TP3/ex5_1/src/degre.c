#include <stdio.h>      
#include "degre.h"

double CelsiusAKelvin(double c){
    return c + 273.15;
}

double CelsiusAFahrenheit(double c){
    return (c * 9 / 5) + 32;
}

double KelvinACelsius(double k){
    return k - 273.15;
}

double KelvinAFahrenheit(double k){
    return (k - 273.15) * 9 / 5 + 32;
}

double FahrenheitACelsius(double f){
    return (f - 32) * 5 / 9;
}

double FahrenheitAKelvin(double f){
    return (f - 32) * 5 / 9 + 273.15;
}

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