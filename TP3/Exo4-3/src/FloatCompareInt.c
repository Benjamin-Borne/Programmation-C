#include <stdio.h>

int compare(float num1, float num2) {
    if (num1 == num2) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {

    int res;
    float num1, num2;

    scanf("%f %f", &num1, &num2);
    res = compare(num1, num2);

    printf("Résultat : %d\n", res);

    return 0;
}
