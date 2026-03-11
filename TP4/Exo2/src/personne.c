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

Personne EnrollInput(void) {
    char Name[22];
    char Firstname[22];
    int jour, mois, annee;
    Personne personne;

    puts("Quel est votre nom ?");
    fflush(stdout);
    fgets(Name, 22, stdin);

    puts("Quel est votre prénom ?");
    fflush(stdout);
    fgets(Firstname, 22, stdin);

    puts("Quel est votre date de naissance ? (format: JJ/MM/AAAA)");
    scanf("%d/%d/%d", &jour, &mois, &annee);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    strcpy(personne.Nom, Name);
    strcpy(personne.Prenom, Firstname);
    personne.date.jour = jour;
    personne.date.mois = mois;
    personne.date.annee = annee;
    return personne;
}

void PrintInfo(Personne p) {
    printf("Prénom: %s", p.Prenom);
    printf("Nom: %s", p.Nom);
    printf("Date de naissance: %d/%d/%d", p.date.jour, p.date.mois, p.date.annee);
}

void SortName(Personne p[], int n) {
    Personne temp;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (p[j].date.annee < p[i].date.annee) {
                temp = *(p + i);
                p[i] = *(p + j);
                p[j] = temp;
            }else if (p[j].date.annee == p[i].date.annee){
                if (p[j].date.mois < p[i].date.mois) {
                    temp = *(p + i);
                    p[i] = *(p + j);
                    p[j] = temp;
                }else if (p[j].date.mois == p[i].date.mois){
                    if (p[j].date.jour < p[i].date.jour) {
                        temp = *(p + i);
                        p[i] = *(p + j);
                        p[j] = temp;
                    }
                }
            }
        }
    }
}

void FindPeople(Personne p[], int n, char nom[]) {
    for (int i = 0; i < n; i++) {
        if (p[i].Nom == nom) {
            PrintInfo(p[i]);
        }
    }
}

int main(void) {
    Personne p[3];

    for (int i=0; i<3; i++) {
        p[i] = EnrollInput();
    }

    SortName(p, 3);
    for (int i=0; i<3; i++) {
        printf("%s", p[i].Nom);
    }

    return 0;
}
