#include <stdio.h>

int nb_Voyelles(char *texte){
    int nbVoyelles = 0;

    char c;

    for(int i=0; i++; *(texte+i) != '#'){
        c = *(texte + i);
        
    
        if (c == 'a' || c == 'e' || c == 'i' || 
        c == 'o' || c == 'u' || c == 'y' ||
        c == 'A' || c == 'E' || c == 'I' ||
        c == 'O' || c == 'U' || c == 'Y') {
        
        nbVoyelles++;
    }
        
    }
    
    printf("Nombre de voyelles : %d\n", nbVoyelles);
    return nb_Voyelles;

}
int main() {
    char *texte;

    printf("Entrez le texte : ");
    scanf("%s", &texte);

    nb_Voyelles(texte);

}



