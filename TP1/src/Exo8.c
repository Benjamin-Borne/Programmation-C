#include <stdio.h>

int calculatrice_if() {
    float num1, num2, result;
    char op;

    while (1) {

        printf("Entrez une operation (+, -, *, /) ou 's' : ");
        scanf(" %c", &op);   

        if (op == 's') {
            break;
        }

        printf("Entrez deux nombres : ");
        scanf("%f %f", &num1, &num2);

        if (op == '+') {
            result = num1 + num2;
        }
        else if (op == '-') {
            result = num1 - num2;
        }
        else if (op == '*') {
            result = num1 * num2;
        }
        else if (op == '/') {
            if (num2 == 0) {
                printf("Erreur : division par zero !\n");
                continue;
            }
            result = num1 / num2;
        }
        else {
            printf("Operation non valide !\n");
            continue;
        }

        printf("Resultat = %.2f\n\n", result);
    }

    return 0;
}


int calculatrice_case(){
    float num1, num2;
    char op;

    while (1) {

    printf("Entrez une operation (+, -, *, /) ou 's' : ");
    scanf(" %c", &op);   

    if (op == 's') {
        return 0;
    }

    printf("Entrez deux nombres : ");
    scanf("%f %f", &num1, &num2);

    switch(op) {

        case '+':
            printf("Résultat : %f\n", num1 + num2);
            break;

        case '-':
            printf("Résultat : %f\n", num1 - num2);
            break;

        case '*':
            printf("Résultat : %f\n", num1 * num2);
            break;

        case '/':
            if (num2 == 0) {
                    printf("Erreur : division par zero !\n");
                }
            printf("Résultat : %f\n", num1 / num2);
            break;
        default:
            printf("Other Value \n");

    }
    }

    return 0;

}



int main(){
    printf(" ----- Calculatrice IF ----\n");
    calculatrice_if();

    printf(" ----- Calculatrice CASE ----\n");
    calculatrice_case();
    
    return 0;
}