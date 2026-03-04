#include <stdio.h>

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

    fgets(param, 1024, stdin);

    printf("%d", nbVoy(param));
    return 0;
}