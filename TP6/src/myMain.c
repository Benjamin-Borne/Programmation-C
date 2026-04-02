#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "../src/acces.c"

int main(){
    /*
    Fonction main du programme pour gérer les personnes et le contrôle d'accès
    */
    int choix;

    file f;
    initialiserFile(&f);

    while (1) {
        printf("\n ------------- \n");
        printf("1. Ajouter une personne\n");
        printf("2. Supprimer une personne\n");
        printf("3. Modifier le code secret d'une personne\n");
        printf("4. Contrôle d'accès\n");
        printf("5. Afficher la liste des personnes\n");
        printf("6. Sauvegarder la liste dans un fichier\n");
        printf("7 . Charger la liste depuis un fichier\n");
        printf("8. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouterPersonne(&f);
            break;
        
        case 2: {
            char badge[5];
            printf("Entrez le badge de la personne à supprimer : ");
            scanf("%s", badge);
            supprimerPersonne(&f, badge);
            break;
        }

        case 3: {
            char badge[5];
            char nouveauCode[5];
            printf("Entrez le badge de la personne à modifier : ");
            scanf("%s", badge);
            printf("Entrez le nouveau code secret : ");
            scanf("%s", nouveauCode);
            modifierCodeSecret(&f, badge, nouveauCode);
            break;
        }   

        case 4: {
            char badge[5];
            char codeSecret[5];
            printf("Entrez le badge pour le contrôle d'accès : ");
            scanf("%s", badge);
            printf("Entrez le code secret pour le contrôle d'accès : ");
            scanf("%s", codeSecret);
            controleAcces(&f, badge, codeSecret);
            break;
        }

        case 5:
            afficherListe(&f);
            break;

        case 6:
            sauvegarderListe(&f, "personnes.txt");
            printf("Liste sauvegardée dans personnes.txt\n");
            break;

        case 7:
            lireFichier(&f, "personnes.txt");
            printf("Liste chargée depuis personnes.txt\n");
            break;
        
        case 8:
            exit(0);
            break;
        
        
        default:
            break;
        }
    }

    return 0;    

}
