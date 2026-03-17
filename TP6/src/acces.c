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


typedef struct {
    maillon* suivant;
    maillon* precedent;
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
    timer_t t = time(NULL);
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
            strncpy(courant->personne->codeSecret, nouveauCode, 5);
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

void main(){
    int choix;


}
