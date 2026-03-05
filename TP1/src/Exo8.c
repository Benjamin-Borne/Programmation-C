#include <math.h>
#include <stdio.h>

float calculatrice_if(float num1, float num2, char op) {
    float result;


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
            result = NAN;
        }else {
            result = num1 / num2;
        }
    }
    else {
        printf("Operation non valide !\n");
        result = 0;
    }

    return result;
}


float calculatrice_case(float num1, float num2, char op){
    if (op == 's') {
        return 0;
    }

    switch(op) {

        case '+':
            return num1 + num2;
            break;

        case '-':
            return num1 - num2;
            break;

        case '*':
            return num1 * num2;
            break;

        case '/':
            if (num2 == 0) {
                    puts("Division par zéro !");
                    return NAN;
                }
            return num1 / num2;
            break;
        default:
            puts("Other Value \n");
            return 0;

    }
}


/*
int main(){
    
    float num1,num2;
    char op;

    
    while (1) {
        puts("Entrez une operation (+, -, *, /) ou 's' : ");
        scanf(" %c", &op);   

        if (op == 's') {
            return 0;
        }

        puts("Entrez deux nombres : ");
        scanf("%f %f", &num1, &num2);


        puts(" ----- Calculatrice IF ----\n");

        printf("Resultat = %.2f\n\n", calculatrice_if(num1,num2,op));

        puts(" ----- Calculatrice CASE ----\n");

        printf("Résultat : %.2f\n", calculatrice_case(num1, num2, op));
        
        return 0;
    }
}
*/