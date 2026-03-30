#include <stdio.h>
#include <string.h>

int nbVoy(char *p) {
    /*
    Compte le nombre de voyelles dans une chaîne de caractères

    Args :
    p : chaîne de caractères à analyser 

    Return :
    Nombre de voyelles dans la chaîne de caractères
    */

    int nbVoy = 0;

    for (int i=0; *(p+i)!='#'; i++){
        char c = *(p+i);
        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u' || c == 'y' ||
            c == 'A' || c == 'E' || c == 'I' ||
            c == 'O' || c == 'U' || c == 'Y') {

            nbVoy++;
            }
    }

    return nbVoy;
}


int main(void) {
    /*
    Programme main pour tester le nombre de voyelles
    */

    char param[1025];

    if (fgets(param, sizeof(param), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }

    param[strcspn(param, "\n")] = '\0';

    printf("%d", nbVoy(param));
    return 0;
}
