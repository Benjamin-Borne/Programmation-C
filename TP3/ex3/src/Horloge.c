#include <stdio.h>
#include <stdlib.h>

int horloge(long heures, long minutes, long secondes){

    long secondes_finales = heures * 3600 + minutes * 60 + secondes;
    printf("L'heure en seconde est: %ld\n", secondes_finales);

    return 0;
}


int main(void){
    char heures[4], minutes[4], secondes[4];

    puts("Heures : ");
    fgets(heures, sizeof(heures), stdin);

    puts("Minutes : ");
    fgets(minutes, sizeof(minutes), stdin);

    puts("Secondes : ");
    fgets(secondes, sizeof(secondes), stdin);

    horloge(strtol(heures, NULL, 10), strtol(minutes, NULL, 10), strtol(secondes, NULL, 10));

    return 0;
}