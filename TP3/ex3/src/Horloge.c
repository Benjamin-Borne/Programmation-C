#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int horloge(long heures, long minutes, long secondes){

    if (heures < 0 || minutes < 0 || secondes < 0) {
        fprintf(stderr, "Heures, minutes ou secondes invalides.");
        return -1;
    }

    long secondes_finales = heures * 3600 + minutes * 60 + secondes;
    printf("L'heure en seconde est: %ld\n", secondes_finales);

    return 0;
}

long StringToLong(char input[]) {
    char *endptr;
    long number;

    errno = 0;
    number = strtol(input, &endptr, 10);

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

    return number;
}

int main(void){
    char heures[4], minutes[4], secondes[4];
    long hours, min, sec;
    puts("Heures : ");
    if (fgets(heures, sizeof(heures), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }
    heures[strcspn(heures, "\n")] = '\0';

    puts("Minutes : ");
    if (fgets(minutes, sizeof(minutes), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }
    minutes[strcspn(minutes, "\n")] = '\0';

    puts("Secondes : ");
    if (fgets(secondes, sizeof(secondes), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }
    secondes[strcspn(secondes, "\n")] = '\0';

    hours = StringToLong(heures);
    min   = StringToLong(minutes);
    sec   = StringToLong(secondes);

    horloge(hours, min, sec);

    return 0;
}
