#ifndef DEGRE_H
#define DEGRE_H

long CelsiusAKelvin(long c) {
    return c + 273;
}
long CelsiusAFahrenheit(long c) {
    return (c * 9 / 5) + 32;
}
long KelvinACelsius(long k) {
    return k - 273;
}
long KelvinAFahrenheit(long k) {
    return (k - 273) * 9 / 5 + 32;
}
long FahrenheitACelsius(long f) {
    return (f - 32) * 5 / 9;
}
long FahrenheitAKelvin(long f) {
    return (f - 32) * 5 / 9 + 273;
}

#endif