#include <stdio.h>

int compare(int num1, int num2) {
    if (num1 == num2) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {

    int res, num1, num2;

    scanf("%d %d", &num1, &num2);
    res = compare(num1, num2);

    printf("Résultat : %d\n", res);

    return 0;
}
