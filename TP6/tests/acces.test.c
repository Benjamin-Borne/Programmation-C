#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../src/myMain.c"



static int tests_total  = 0;
static int tests_passed = 0;

#define ASSERT(nom, cond) do {                                \
    tests_total++;                                            \
    if (cond) { printf("  [PASS] %s\n", nom); tests_passed++; } \
    else       { printf("  [FAIL] %s\n", nom); }             \
} while (0)



/* ── 1. initialiserFile ── */
void test_initialiserFile(void) {
    puts("\n=== initialiserFile ===");
    file f;
    initialiserFile(&f);
    ASSERT("tete est NULL après init",  f.tete  == NULL);
    ASSERT("queue est NULL après init", f.queue == NULL);
}

/* ── 2. ajouterPersonneDirect ── */
void test_ajouterPersonne(void) {
    puts("\n=== ajouterPersonne ===");
    file f; initialiserFile(&f);

    ajouterPersonneDirect(&f, creerP("Dupont", "Alice", "A001", "1234"));
    ASSERT("1 élément après premier ajout",      tailleFile(&f) == 1);
    ASSERT("tete non NULL",                      f.tete  != NULL);
    ASSERT("queue non NULL",                     f.queue != NULL);
    ASSERT("tete == queue pour 1 élément",       f.tete  == f.queue);

    ajouterPersonneDirect(&f, creerP("Martin", "Bob",  "B002", "5678"));
    ASSERT("2 éléments après deuxième ajout",    tailleFile(&f) == 2);
    ASSERT("tete et queue distincts",            f.tete != f.queue);
    ASSERT("chaînage avant correct (tete->suiv == queue)",
           f.tete->suivant == f.queue);
    ASSERT("chaînage arrière correct (queue->prec == tete)",
           f.queue->precedent == f.tete);

    ajouterPersonneDirect(&f, creerP("Durand", "Carol","C003", "9999"));
    ASSERT("3 éléments après troisième ajout",   tailleFile(&f) == 3);
    ASSERT("dernier badge correct",
           strcmp(f.queue->personne->badge, "C003") == 0);

    libererFile(&f);
}

/* ── 3. supprimerPersonne ── */
void test_supprimerPersonne(void) {
    puts("\n=== supprimerPersonne ===");
    file f; initialiserFile(&f);
    ajouterPersonneDirect(&f, creerP("Dupont", "Alice", "A001", "1234"));
    ajouterPersonneDirect(&f, creerP("Martin", "Bob",   "B002", "5678"));
    ajouterPersonneDirect(&f, creerP("Durand", "Carol", "C003", "9999"));

    /* Suppression milieu */
    supprimerPersonne(&f, "B002");
    ASSERT("2 éléments après suppression milieu", tailleFile(&f) == 2);
    ASSERT("B002 introuvable après suppression",  trouverMaillon(&f, "B002") == NULL);
    ASSERT("A001 toujours présent",               trouverMaillon(&f, "A001") != NULL);
    ASSERT("C003 toujours présent",               trouverMaillon(&f, "C003") != NULL);
    ASSERT("chaînage OK après suppression milieu",
           f.tete->suivant == f.queue && f.queue->precedent == f.tete);

    /* Suppression tête */
    supprimerPersonne(&f, "A001");
    ASSERT("1 élément après suppression tête",    tailleFile(&f) == 1);
    ASSERT("tete == queue après suppression tête",f.tete == f.queue);
    ASSERT("nouvelle tête est C003",
           strcmp(f.tete->personne->badge, "C003") == 0);

    /* Suppression queue (dernier élément) */
    supprimerPersonne(&f, "C003");
    ASSERT("file vide après suppression dernière", tailleFile(&f) == 0);
    ASSERT("tete NULL sur file vide",  f.tete  == NULL);
    ASSERT("queue NULL sur file vide", f.queue == NULL);

    /* Badge inexistant : aucun crash */
    supprimerPersonne(&f, "XXXX");
    ASSERT("suppression badge inexistant ne plante pas", 1);

    libererFile(&f);
}

/* ── 4. modifierCodeSecret ── */
void test_modifierCodeSecret(void) {
    puts("\n=== modifierCodeSecret ===");
    file f; initialiserFile(&f);
    ajouterPersonneDirect(&f, creerP("Dupont", "Alice", "A001", "1234"));
    ajouterPersonneDirect(&f, creerP("Martin", "Bob",   "B002", "5678"));

    modifierCodeSecret(&f, "A001", "9999");
    maillon* m = trouverMaillon(&f, "A001");
    ASSERT("code modifié pour A001",
           m && strcmp(m->personne->codeSecret, "9999") == 0);

    /* L'autre badge n'est pas affecté */
    maillon* m2 = trouverMaillon(&f, "B002");
    ASSERT("code B002 inchangé",
           m2 && strcmp(m2->personne->codeSecret, "5678") == 0);

    /* Badge inexistant : aucun crash */
    modifierCodeSecret(&f, "XXXX", "0000");
    ASSERT("modification badge inexistant ne plante pas", 1);

    libererFile(&f);
}

/* ── 5. controleAcces ── */
void test_controleAcces(void) {
    puts("\n=== controleAcces ===");
    file f; initialiserFile(&f);
    ajouterPersonneDirect(&f, creerP("Dupont", "Alice", "A001", "1234"));
    ajouterPersonneDirect(&f, creerP("Martin", "Bob",   "B002", "5678"));

    ASSERT("accès OK (badge + code corrects)",
           controleAccesTest(&f, "A001", "1234") == 1);
    ASSERT("accès refusé (mauvais code)",
           controleAccesTest(&f, "A001", "0000") == 0);
    ASSERT("badge inconnu → -1",
           controleAccesTest(&f, "ZZZZ", "1234") == -1);
    ASSERT("accès OK deuxième personne",
           controleAccesTest(&f, "B002", "5678") == 1);

    /* Vérification mise à jour du dernier passage */
    maillon* m = trouverMaillon(&f, "A001");
    ASSERT("dernierPassage mis à jour après accès OK",
           strcmp(m->personne->dernierPassage, "2025-01-01 00:00:00") != 0);

    libererFile(&f);
}

/* ── 6. sauvegarde / lecture fichier ── */
void test_fichier(void) {
    puts("\n=== sauvegarde / lecture fichier ===");
    const char* tmp = "/tmp/test_acces.csv";

    /* Peuplement */
    file src; initialiserFile(&src);
    ajouterPersonneDirect(&src, creerP("Dupont", "Alice", "A001", "1234"));
    ajouterPersonneDirect(&src, creerP("Martin", "Bob",   "B002", "5678"));
    sauvegarderListe(&src, tmp);

    /* Rechargement dans une nouvelle file */
    file dst; initialiserFile(&dst);
    lireFichier(&dst, tmp);

    ASSERT("même nombre de personnes après rechargement", tailleFile(&dst) == tailleFile(&src));

    maillon* m1 = trouverMaillon(&dst, "A001");
    ASSERT("A001 présent après chargement", m1 != NULL);
    ASSERT("nom A001 correct",    m1 && strcmp(m1->personne->nom,        "Dupont") == 0);
    ASSERT("prénom A001 correct", m1 && strcmp(m1->personne->prenom,     "Alice")  == 0);
    ASSERT("code A001 correct",   m1 && strcmp(m1->personne->codeSecret, "1234")   == 0);

    maillon* m2 = trouverMaillon(&dst, "B002");
    ASSERT("B002 présent après chargement", m2 != NULL);
    ASSERT("nom B002 correct",    m2 && strcmp(m2->personne->nom, "Martin") == 0);

    /* Chaînage correct après lireFichier */
    ASSERT("tete->suivant == queue pour 2 éléments rechargés",
           dst.tete->suivant == dst.queue);
    ASSERT("queue->precedent == tete pour 2 éléments rechargés",
           dst.queue->precedent == dst.tete);

    libererFile(&src);
    libererFile(&dst);
    remove(tmp);
}

/* ── 7. file vide (cas limites) ── */
void test_casLimites(void) {
    puts("\n=== Cas limites ===");
    file f; initialiserFile(&f);

    supprimerPersonne(&f, "A001");
    ASSERT("supprimer dans file vide ne plante pas", 1);

    modifierCodeSecret(&f, "A001", "9999");
    ASSERT("modifier dans file vide ne plante pas", 1);

    ASSERT("controle accès file vide → -1",
           controleAccesTest(&f, "A001", "1234") == -1);

    ASSERT("taille file vide == 0", tailleFile(&f) == 0);
}

/* ══════════════════════════════════════════════════════
   main
   ══════════════════════════════════════════════════════ */

int main(void) {
    puts("╔══════════════════════════════════════════╗");
    puts("║   Tests unitaires – Contrôle d'accès    ║");
    puts("╚══════════════════════════════════════════╝");

    test_initialiserFile();
    test_ajouterPersonne();
    test_supprimerPersonne();
    test_modifierCodeSecret();
    test_controleAcces();
    test_fichier();
    test_casLimites();

    printf("\n══════════════════════════════════════════\n");
    printf("Résultat : %d/%d tests réussis\n", tests_passed, tests_total);

    return (tests_passed == tests_total) ? 0 : 1;
}

