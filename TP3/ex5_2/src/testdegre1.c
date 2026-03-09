#include <stdio.h>
#include <assert.h>
#include "../../ex5_1/src/degre.h"

void testCelsiusAKelvin() {
    assert(CelsiusAKelvin(0.0) == 273.15);
    assert(CelsiusAKelvin(100.0) == 373.15);
    assert(CelsiusAKelvin(-273.15) == 0.0);
    puts("  [OK] CelsiusAKelvin");
}

void testCelsiusAFahrenheit() {
    assert(CelsiusAFahrenheit(0.0) == 32.0);
    assert(CelsiusAFahrenheit(100.0) == 212.0);
    assert(CelsiusAFahrenheit(-273.15) == -459.67);
    puts("  [OK] CelsiusAFahrenheit");
}

void testKelvinACelsius() {
    assert(KelvinACelsius(273.15) == 0.0);
    assert(KelvinACelsius(373.15) == 100.0);
    assert(KelvinACelsius(0.0) == -273.15);
    puts("  [OK] KelvinACelsius");
}

void testKelvinAFahrenheit() {
    assert(KelvinAFahrenheit(273.15) == 32.0);
    assert(KelvinAFahrenheit(373.15) == 212.0);
    assert(KelvinAFahrenheit(0.0) == -459.67);
    puts("  [OK] KelvinAFahrenheit");
}

void testFahrenheitACelsius() {
    assert(FahrenheitACelsius(32.0) == 0.0);
    assert(FahrenheitACelsius(212.0) == 100.0);
    assert(FahrenheitACelsius(-459.67) == -273.15);
    puts("  [OK] FahrenheitACelsius");
}

void testFahrenheitAKelvin() {
    assert(FahrenheitAKelvin(32.0) == 273.15);
    assert(FahrenheitAKelvin(212.0) == 373.15);
    assert(FahrenheitAKelvin(-459.67) == 0.0);
    puts("  [OK] FahrenheitAKelvin");
}

int main(void) {
    testCelsiusAKelvin();
    testCelsiusAFahrenheit();
    testKelvinACelsius();
    testKelvinAFahrenheit();
    testFahrenheitACelsius();
    testFahrenheitAKelvin();

    return 0;
}