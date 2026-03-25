#include <stdio.h>
#include <string.h>

int nbVoy(char *p) {

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

    char param[1025];

    if (fgets(param, sizeof(param), stdin) == NULL) {
        fprintf(stderr, "Erreur de lecture\n");
        return 1;
    }

    param[strcspn(param, "\n")] = '\0';

    printf("%d", nbVoy(param));
    return 0;
}
