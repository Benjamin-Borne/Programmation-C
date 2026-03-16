#include <stdio.h>
#include <string.h>

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


int PersonneEqual(Personne a, Personne b) {
    int cmpr = strcmp(a.Nom, b.Nom) == 0 && strcmp(a.Prenom, b.Prenom) == 0 && a.date.jour == b.date.jour && a.date.mois == b.date.mois && a.date.annee == b.date.annee;
    return cmpr;
}


void EnrollInput(void) {
    char Name[22];
    char Firstname[22];
    int jour, mois, annee;

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

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

Personne SelectPerson(void) {
    int choice;
    PrintInfo();

    printf("Sélectionner une personne a supprimer: ");
    scanf("%d", &choice);

    return p[choice-1];
}


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

void EditRecord(Personne *personne) {
    char Name[22];
    char Firstname[22];
    int jour, mois, annee;
    int c;

    while ((c = getchar()) != '\n' && c != EOF);

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

    strcpy(personne->Nom, Name);
    strcpy(personne->Prenom, Firstname);
    personne->date.jour = jour;
    personne->date.mois = mois;
    personne->date.annee = annee;
}


void FindModifyPeople(char nom[]) {
    Personne personnes[20];
    memset(personnes, 0, sizeof(personnes));
    int indices[20]; // Stocker les indices dans p[] global
    int count = 0;
    int choice;

    for (int i = 0; i < 20; i++) {
        if (p[i].Nom[0] == '\0') break;
        if (strcmp(p[i].Nom, nom) == 0) {
            personnes[count] = p[i];
            indices[count] = i; // Sauvegarder l'indice
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

    if (choice > 0 && choice <= count) {
        EditRecord(&p[indices[choice - 1]]);
    }
}


void DeleteRecord(Personne personne) {
    for (int i = 0; i < 20; i++) {
        if (PersonneEqual(p[i], personne) == 1) {
            for (int j = i; j < 19; j++) {
                p[j] = p[j + 1];
            }
            memset(&p[19], 0, sizeof(Personne));
            break;
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

        printf("Choisissez une option : ");
        scanf("%d", &choice);
        puts("");
        switch (choice) {
            case 1:
                EnrollInput();
                break;
            case 2:
                PrintInfo();
                break;
            case 3:
                printf("Rentrez le nom de la personne: ");
                scanf("%s", Name);
                FindModifyPeople(Name);
                break;
            case 4:
                temp = SelectPerson();
                DeleteRecord(temp);
                break;
            case 5:
                SortName();
                break;
            case 6:
                return 0;
                break;
            default:
                return 0;
                break;
        }
    }
    return 0;
}
