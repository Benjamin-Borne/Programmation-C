#include <stdio.h>

char compare(float num1, float num2) {
    if (num1 == num2) {
        return 'V';
    } else {
        return 'F';
    }
}

int main(void) {

    float num1, num2;
    char res;

    scanf("%f %f", &num1, &num2);
    res = compare(num1, num2);

    printf("Résultat : %c\n", res);

    return 0;
}
