#define N 3
typedef struct maillon {
    int x;
    struct maillon * suiv;
} maillon;
void{
    main(void)
    maillon lc;
    lc.x = 1;
    printf("Valeur du champs x = %d\n\n", lc.x);
    lc.suiv = (maillon *) malloc(sizeof(maillon));
    lc.suiv->x = 2;
    printf("Valeur du champs x du deuxieme maillon = %d\n\n", lc.suiv->x);
}
