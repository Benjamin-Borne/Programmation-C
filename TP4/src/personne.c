#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef struct {
    char Nom[20];
    char Prenom[20];
    struct DATE {
        int jour;
        int mois;
        int annee;
    }date;
} Personne;

Personne p[20];

/*
 * Vérifie si deux personnes sont égales (si chaque propriété est identique).
 */
int PersonneEqual(Personne a, Personne b) {
    int cmpr = strcmp(a.Nom, b.Nom) == 0 && strcmp(a.Prenom, b.Prenom) == 0 && a.date.jour == b.date.jour && a.date.mois == b.date.mois && a.date.annee == b.date.annee;
    return cmpr;
}

/*
 * Ajoute une personne à la liste des personnes.
 * Les caractéristiques sont rentrées au clavier par l'utilisateur.'
 */
void EnrollInput(void) {
    char Name[22];
    char Firstname[22];
    int jour, mois, annee;
    int c;

    puts("Quel est votre nom ?");
    fflush(stdout);
    fgets(Name, 22, stdin);
    Name[strcspn(Name, "\n")] = '\0';

    puts("Quel est votre prénom ?");
    fflush(stdout);
    fgets(Firstname, 22, stdin);
    Firstname[strcspn(Firstname, "\n")] = '\0';

    puts("Quel est votre date de naissance ? (format: JJ/MM/AAAA)");
    scanf("%d/%d/%d", &jour, &mois, &annee);
    while ((c = getchar()) != '\n' && c != EOF); 

    if (mois < 1 || mois > 12) return;
    if (jour < 1 || jour > 31) return;
    if (annee < 1900 || annee > 2100) return;
    if ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30) return;
    if (mois == 2 && jour > 29) return;

    
    for (int i = 0; i < 20; i++) {
        if (p[i].Nom[0] == '\0') {
            strcpy(p[i].Nom, Name);
            strcpy(p[i].Prenom, Firstname);
            p[i].date.jour = jour;
            p[i].date.mois = mois;
            p[i].date.annee = annee;
            break;
        }
    }
}

/*
 * Affiche les informations des personnes une par une.
 */
void PrintInfo(void) {
    for (int i = 0; i < 20; i++) {
        if (p[i].Nom[0] == '\0') {
            break;
        }
        printf("%d. ", i+1);
        printf("Prénom: %s, Nom: %s, Date de naissance; %d/%d/%d\n", p[i].Prenom, p[i].Nom, p[i].date.jour, p[i].date.mois, p[i].date.annee);
    }
    puts("");
}


/*
 * Permet a l'utilisateur de sélectionner une personne.
 */
Personne SelectPerson(void) {
    char choice[8];
    char *end;

    if (p[0].Nom[0] == '\0') {
        puts("La liste est vide.");
        return (Personne) {0};
    }

    PrintInfo();

    puts("Sélectionner une personne a supprimer: ");
    fgets(choice, sizeof(choice), stdin);
    errno = 0;
    long idx = strtol(choice, &end, 10);
    if (errno == ERANGE || end == choice || (*end != '\0' && *end != '\n')) {
        fputs("Erreur : saisie invalide.\n", stderr);
        return (Personne) {0};
    }
    if (idx < 1 || idx > 20 || p[idx-1].Nom[0] == '\0') {
        fputs("Numéro hors de la liste.\n", stderr);
        return (Personne) {0};
    }

    return p[idx-1];
}

/*
 * Tri les personnes en ordre croissant de leur date de naissance. Le tri effectué selon l'algorithme de tri par recherche de minimas successifs vu au TP2-2
 */
void SortName(void) {
    Personne temp;


    int count = 0;
    while (count < 20 && p[count].Nom[0] != '\0') count++;

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            int swap = 0;

            if (p[j].date.annee < p[i].date.annee) {
                swap = 1;
            } else if (p[j].date.annee == p[i].date.annee) {
                if (p[j].date.mois < p[i].date.mois) {
                    swap = 1;
                } else if (p[j].date.mois == p[i].date.mois) {
                    if (p[j].date.jour < p[i].date.jour) {
                        swap = 1;
                    }
                }
            }

            if (swap) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

/*
 * Permet de modifier les caractéristiques d'une personnes. Les modifications sont rentrées au clavier par l'utilisateur.
 */
void EditRecord(Personne *personne) {
    char Name[22];
    char Firstname[22];
    int jour, mois, annee;
    int c;

    puts("Quel est votre nom ?");
    fflush(stdout);
    fgets(Name, 22, stdin);
    Name[strcspn(Name, "\n")] = '\0';

    puts("Quel est votre prénom ?");
    fflush(stdout);
    fgets(Firstname, 22, stdin);
    Firstname[strcspn(Firstname, "\n")] = '\0';

    puts("Quel est votre date de naissance ? (format: JJ/MM/AAAA)");
    scanf("%d/%d/%d", &jour, &mois, &annee);
    while ((c = getchar()) != '\n' && c != EOF); 

    if (mois < 1 || mois > 12) return;
    if (jour < 1 || jour > 31) return;
    if (annee < 1900 || annee > 2100) return;
    if ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30) return;
    if (mois == 2 && jour > 29) return;

    strcpy(personne->Nom, Name);
    strcpy(personne->Prenom, Firstname);
    personne->date.jour = jour;
    personne->date.mois = mois;
    personne->date.annee = annee;
}

/*
 *Permet d'afficher les infos des personnes présente de la liste et demande à l'utilisateur s'il veut modifier une personne.'
 */
void FindModifyPeople(char nom[]) {
    Personne personnes[20];
    memset(personnes, 0, sizeof(personnes));
    int indices[20];
    int count = 0;
    int choice;
    int c;

    for (int i = 0; i < 20; i++) {
        if (p[i].Nom[0] == '\0') break;
        if (strcmp(p[i].Nom, nom) == 0) {
            personnes[count] = p[i];
            indices[count] = i;
            count++;
        }
    }

    if (count == 0) {
        printf("Aucune personne trouvée avec le nom %s\n", nom);
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d. Prénom: %s, Nom: %s, Date de naissance: %d/%d/%d\n",
               i + 1,
               personnes[i].Prenom,
               personnes[i].Nom,
               personnes[i].date.jour,
               personnes[i].date.mois,
               personnes[i].date.annee);
    }

    printf("Voulez modifier : (numéro de la personne à modifier, 0 si non) : ");
    scanf("%d", &choice);
    while ((c = getchar()) != '\n' && c != EOF); 

    if (choice > 0 && choice <= count) {
        EditRecord(&p[indices[choice - 1]]);
    }
}

/*
 * Permet de supprimer la personne passée en paramètre.
 */
void DeleteRecord(Personne personne) {
    for (int i = 0; i < 20; i++) {
        if (PersonneEqual(p[i], personne) == 1) {
            for (int j = i; j < 19; j++) {
                p[j] = p[j + 1];
            }
            memset(&p[19], 0, sizeof(Personne));
            return;
        }
    }
}

int main(void) {
    int choice;
    char Name[20];
    Personne temp;
    while (1) {

        puts("1. Enregistrer une personne");
        puts("2. Afficher les informations d'une personne");
        puts("3. Trouver une personne");
        puts("4. Supprimer une personne");
        puts("5. Trier par date de naissance");
        puts("6. Quitter");       

        puts("Choisissez une option : ");
        choice = fgetc(stdin); 
        

        int c;
        if (choice != '\n') {
            while ((c = getchar()) != '\n' && c != EOF);
        }

        puts("");
        
        switch (choice) {
            case 0x31:
                EnrollInput();
                break;
            case 0x32:
                PrintInfo();
                break;
            case 0x33:
                printf("Rentrez le nom de la personne: ");
                scanf("%s", Name);
                while ((c = getchar()) != '\n' && c != EOF);
                FindModifyPeople(Name);
                break;
            case 0x34:
                temp = SelectPerson();
                printf("%d",temp.Nom[0]);
                if (temp.Nom[0] != '\0') {
                    DeleteRecord(temp);
                }
                break;
            case 0x35:
                SortName();
                break;
            case 0x36:
                return 0;
                break;
            default:
                return 0;
                break;
        }
    }
    return 0;
}
