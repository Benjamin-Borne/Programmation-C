#include <stdio.h>

int main(){

    int num1, num2;

    printf("Choisir deux nombres : ");
    scanf("%d%d",&num1,&num2);

    while (num1 != num2){

        if (num1 < num2){
            int result = num2 - num1;
            num2 = result;
        }else {
            int result = num1 - num2;
            num1 = result;
        }

    }
    printf("PGCD : %d", num1);
    return num1;

}

