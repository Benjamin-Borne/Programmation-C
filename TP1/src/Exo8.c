#include <stdio.h>

int calculatrice_if(float num1, float num2, char op) {
    float result;

    while (1) { 

        if (op == 's') {
            break;
        }


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


int calculatrice_case(float num1, float num2, char op){
    

    while (1) {

    if (op == 's') {
        return 0;
    }

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

    float num1,num2;
    char op;

    printf("Entrez une operation (+, -, *, /) ou 's' : ");
    scanf(" %c", &op);   

    printf("Entrez deux nombres : ");
    scanf("%f %f", &num1, &num2);

    calculatrice_if(num1,num2,op);



    printf(" ----- Calculatrice CASE ----\n");

    float num1, num2;
    char op;

    printf("Entrez une operation (+, -, *, /) ou 's' : ");
    scanf(" %c", &op);

    printf("Entrez deux nombres : ");
    scanf("%f %f", &num1, &num2);

    calculatrice_case(num1, num2, op);
    
    return 0;
}
