#ifndef DEGRE_H
#define DEGRE_H

double CelsiusAKelvin(double c) {
    /*
    Convert Celsius to Kelvin

    Args :
    c (double) : temperature in Celsius
    */
    return c + 273;
}
double CelsiusAFahrenheit(double c) {
    /*
    Convert Celsius to Fahrenheit

    Args :
    c (double) : temperature in Celsius
    */
    return (c * 9 / 5) + 32;
}
double KelvinACelsius(double k) {
    /*
    Convert Kelvin to Celsius

    Args :
    k (double) : temperature in Kelvin
    */
    return k - 273;
}
double KelvinAFahrenheit(double k) {
    /*
    Convert Kelvin to Fahrenheit

    Args :
    k (double) : temperature in Kelvin
    */
    return (k - 273) * 9 / 5 + 32;
}
double FahrenheitACelsius(double f) {
    /*
    Convert Fahrenheit to Celsius

    Args :
    f (double) : temperature in Fahrenheit
    */
    return (f - 32) * 5 / 9;
}
double FahrenheitAKelvin(double f) {
    /*
    Convert Fahrenheit to Kelvin

    Args :
    f (double) : temperature in Fahrenheit
    */
    return (f - 32) * 5 / 9 + 273;
}

#endif