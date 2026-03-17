#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 3
#define TAILLE_DATE 20
#define MAX_PERSONNES 100

typedef struct {
    char nom[20];
    char prenom[20];
    char badge[5];
    char codeSecret[5];
    char dernierPassage[TAILLE_DATE];

} personne;


typedef struct maillon{
    struct maillon* suivant;
    struct maillon* precedent;
    personne* personne; 
} maillon;

typedef struct {
    maillon* tete;
    maillon* queue;
} file;


void initialiserFile(file* f) {
    f->tete = NULL;
    f->queue = NULL;
}

void afficherListe(file* f) {
    maillon* courant = f->tete;
    while (courant != NULL) {
        printf("Nom: %s, Prénom: %s, Badge: %s, Code Secret: %s, Dernier Passage: %s\n",
               courant->personne->nom,
               courant->personne->prenom,
               courant->personne->badge,
               courant->personne->codeSecret,
               courant->personne->dernierPassage);
        courant = courant->suivant;
    }
}

personne* creerPersonne() {
    personne* p = (personne*)malloc(sizeof(personne));
    if (p == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    printf("Entrez le nom de la personne : ");
    scanf("%s", p->nom);        
    printf("Entrez le prénom de la personne : ");
    scanf("%s", p->prenom);
    printf("Entrez le badge de la personne (4 caractères) : ");
    scanf("%s", p->badge);
    printf("Entrez le code secret de la personne (4 caractères) : ");
    scanf("%s", p->codeSecret);
    time_t t = time(NULL);
    strftime(p->dernierPassage, TAILLE_DATE, "%Y-%m-%d %H:%M:%S", localtime(&t));

    return p;
}
void ajouterPersonne(file* f) {
    personne* p = creerPersonne();
    maillon* nouveauMaillon = (maillon*)malloc(sizeof(maillon));
    nouveauMaillon->personne = p;
    nouveauMaillon->suivant = NULL;
    nouveauMaillon->precedent = NULL;

    if (f->tete == NULL) {
        f->tete = nouveauMaillon;
        f->queue = nouveauMaillon;
    } else {
        f->queue->suivant = nouveauMaillon;
        nouveauMaillon->precedent = f->queue;
        f->queue = nouveauMaillon;
    }
}

void supprimerPersonne(file* f, char* badge) {
    maillon* courant = f->tete;
    while (courant != NULL) {
        if (strcmp(courant->personne->badge, badge) == 0) {
            if (courant->precedent != NULL) {
                courant->precedent->suivant = courant->suivant;
            } else {
                f->tete = courant->suivant;
            }
            if (courant->suivant != NULL) {
                courant->suivant->precedent = courant->precedent;
            } else {
                f->queue = courant->precedent;
            }
            free(courant->personne);
            free(courant);
            return;
        }
        courant = courant->suivant;
    }
}

void modifierCodeSecret(file* f, char* badge, char* nouveauCode) {
    maillon* courant = f->tete;
    while (courant != NULL) {
        if (strcmp(courant->personne->badge, badge) == 0) {
            snprintf(courant->personne->codeSecret,
            sizeof(courant->personne->codeSecret),
            "%s", nouveauCode);
            return;
        }
        courant = courant->suivant;
    }
}

void controleAcces(file* f, char* badge, char* codeSecret) {
    maillon* courant = f->tete;
    while (courant != NULL) {
        if (strcmp(courant->personne->badge, badge) == 0) {
            if (strcmp(courant->personne->codeSecret, codeSecret) == 0) {
                time_t now = time(NULL);
                strftime(courant->personne->dernierPassage, TAILLE_DATE, "%Y-%m-%d %H:%M:%S", localtime(&now));
                printf("Accès autorisé pour %s %s\n", courant->personne->prenom, courant->personne->nom);
                printf("Date et Heure de la visite : %s\n", courant->personne->dernierPassage);
            } else {
                printf("Code secret incorrect pour %s %s\n", courant->personne->prenom, courant->personne->nom);
            }
            return;
        }
        courant = courant->suivant;
    }
    printf("Badge non trouvé\n");
}


void sauvegarderListe(file* f, const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier\n");
        fprintf(stderr,"\n");
        return;
    }
    fprintf(fichier, "Nom,Prenom,Badge,CodeSecret,DernierPassage\n");
    maillon* courant = f->tete;
    while (courant != NULL) {
        fprintf(fichier, "%s,%s,%s,%s,%s\n",
                courant->personne->nom,
                courant->personne->prenom,
                courant->personne->badge,
                courant->personne->codeSecret,
                courant->personne->dernierPassage);
        courant = courant->suivant;
    }
    fclose(fichier);
}

void lireFichier(file* f, const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier\n");
        return;
    }
    char ligne[256];
    fgets(ligne, sizeof(ligne), fichier);
    while (fgets(ligne, sizeof(ligne), fichier)) {
        personne* p = (personne*)malloc(sizeof(personne));
        sscanf(ligne, "%[^,],%[^,],%[^,],%[^,],%[^\n]",
               p->nom, p->prenom, p->badge, p->codeSecret, p->dernierPassage);
        maillon* nouveauMaillon = (maillon*)malloc(sizeof(maillon));
        nouveauMaillon->personne = p;
        nouveauMaillon->suivant = NULL;
        nouveauMaillon->precedent = NULL;

        if (f->tete == NULL) {
            f->tete = nouveauMaillon;
            f->queue = nouveauMaillon;
        } else {
            f->queue->suivant = nouveauMaillon;
            nouveauMaillon->precedent = f->queue;
            f->queue = nouveauMaillon;
        }
    }
    fclose(fichier);
}


int main(){
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
