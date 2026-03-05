#include <stdio.h>


int PGCD(int num1, int num2){

    if ((num1 == 0) || (num2 == 0)) {
        return num2|num1;
    }else{
        while (num1 != num2){

        if (num1 < num2){
            int result = num2 - num1;
            num2 = result;
        }else {
            int result = num1 - num2;
            num1 = result;
        }

        }
        printf("PGCD : %d\n", num1);
        return num1;
    }
}

/*
int main(){
    int num1, num2;

    printf("Choisir deux nombres : ");
    scanf("%d%d",&num1,&num2);

    PGCD(num1, num2);

    

}
*/
