#include <stdio.h>

int main(void) {
    float a = 0;
    float b = 0;
    char o = 0;

    printf("Enter first number:");
    scanf("%f", &a);

    printf("Enter 2nd number:");
    scanf("%f", &b);

    printf("Enter operand:");
    scanf("\n%c", &o);

    switch (o) {
        case 'a':
        case 'A':
        case '+':
            printf("%f + %f = %f\n", a, b, a + b);
            break;
        case 's':
        case 'S':
        case '-':
            printf("%f - %f = %f\n", a, b, a - b);
            break;
        case 'm':
        case 'M':
        case '*':
            printf("%f * %f = %f\n", a, b, a * b);
            break;
        case 'd':
        case 'D':
        case '/':
            if (b == 0)
                printf("Error: Division by zero.\n");
            else
                printf("%f / %f = %f\n", a, b, a / b);

            break;
        case 'r':
        case 'R':
        case '%':
            if (b == 0)
                printf("Error: Division by zero.\n");
            else
                printf("%f %% %f = %d\n", a, b, (int)a % (int)b);

            break;
        default:
            printf("Error: wrong operator.");
    }

    return 0;
}
