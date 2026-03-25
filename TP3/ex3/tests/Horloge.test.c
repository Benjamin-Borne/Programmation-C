#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "../src/Horloge.c"




int main(){
    assert(horloge(0, 0, 0) == 0);
    assert(horloge(1, 0, 0) == 3600);
    assert(horloge(0, 1, 0) == 60);
    assert(horloge(0, 0, 1) == 1);
    assert(horloge(2, 30, 15) == 9015);
    assert(horloge(23, 59, 59) == 86399);
    
    // Test avec des valeurs négatives
    assert(horloge(-1, 0, 0) == -3600);
    assert(horloge(0, -1, 0) == -60);
    assert(horloge(0, 0, -1) == -1);

    // Test avec des valeurs dépassant les limites habituelles
    assert(horloge(25, 0, 0) == 90000);
    assert(horloge(0, 60, 0) == 3600);
    assert(horloge(0, 0, 60) == 60);

    // Test avec des valeurs très grandes
    assert(horloge(LONG_MAX, 0, 0) == LONG_MAX * 3600);
    assert(horloge(0, LONG_MAX, 0) == LONG_MAX * 60);
    assert(horloge(0, 0, LONG_MAX) == LONG_MAX);

    long min_heures_safe = LONG_MIN / 3600;
    assert(horloge(min_heures_safe, 0, 0) == min_heures_safe * 3600);

    long max_minutes_safe = LONG_MAX / 60;
    assert(horloge(0, max_minutes_safe, 0) == max_minutes_safe * 60);

    printf("Tous les tests sont passés avec succès !\n");

    return 0;


}