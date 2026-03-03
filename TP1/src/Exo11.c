#include <stdio.h>

int main() {
    char c;
    int nbVoyelles = 0;

    printf("Entrez un texte (terminez par #) :\n");

    while (1) {
        scanf("%c", &c);

        if (c == '#') {
            break;
        }

        if (c == 'a' || c == 'e' || c == 'i' || 
            c == 'o' || c == 'u' || c == 'y' ||
            c == 'A' || c == 'E' || c == 'I' ||
            c == 'O' || c == 'U' || c == 'Y') {
            
            nbVoyelles++;
        }
    }

    printf("Nombre de voyelles : %d\n", nbVoyelles);

    return 0;
}