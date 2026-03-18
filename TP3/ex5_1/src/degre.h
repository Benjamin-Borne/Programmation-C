#ifndef DEGRE_H
#define DEGRE_H

double CelsiusAKelvin(double c) {
    return c + 273;
}
double CelsiusAFahrenheit(double c) {
    return (c * 9 / 5) + 32;
}
double KelvinACelsius(double k) {
    return k - 273;
}
double KelvinAFahrenheit(double k) {
    return (k - 273) * 9 / 5 + 32;
}
double FahrenheitACelsius(double f) {
    return (f - 32) * 5 / 9;
}
double FahrenheitAKelvin(double f) {
    return (f - 32) * 5 / 9 + 273;
}

#endif