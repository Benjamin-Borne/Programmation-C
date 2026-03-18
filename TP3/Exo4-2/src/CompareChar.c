#include <stdio.h>

char compare(int num1, int num2) {
    if (num1 == num2) {
        return 'V';
    } else {
        return 'F';
    }
}

int main(void) {

    int num1, num2;
    char res;

    scanf("%d %d", &num1, &num2);
    res = compare(num1, num2);

    printf("Résultat : %c\n", res);

    return 0;
}
