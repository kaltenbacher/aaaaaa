#include <stdio.h>
#include <stdlib.h>

/* Exercício 01:
    Faça um programa que receba dois números e execute as
    operações listadas a seguir, de acordo com a escolha do usuário.
    - 1: média entre os números digitados;
    - 2: diferença do maior pelo menor;
    - 3: produto entre os números digitados;
    - 4: divisão do primeiro pelo segundo;
*/

int main() {
    float first_number, second_number;

    float average, difference, multiplication, division;

    printf("\n Insert the first number to be used in the operations: ");
    scanf("%f", &first_number);
    printf("\n Insert the second number to be used in the operations: ");
    scanf("%f", &second_number);

    printf("\n\n Choose one of the options below to perform a mathematical operation:");
    printf("\n - 1: Average between the inserted numbers.");
    printf("\n - 2: Difference between the bigger and smallest.");
    printf("\n - 3: Multiply both numbers.");
    printf("\n - 4: Divide the first number by the second number.");

    int operation_number;

    printf("\n\n Insert the number of the operation: ");
    scanf("%d", &operation_number);

    switch (operation_number) {
    case 1:
        average = (first_number + second_number)/2;
        printf("\n The average between the numbers %.2f and %.2f is: %.2f.\n\n", first_number, second_number, average);
        break;

    case 2:
        if (first_number > second_number) {
            difference = (first_number - second_number);
        } else {
            difference = (second_number - first_number);
        }

        printf("\n The difference between the numbers %.2f and %.2f is: %.2f.\n\n", first_number, second_number, difference);
        break;

    case 3:
        multiplication = (first_number * second_number);
        printf("\n The multiplication between the numbers %.2f and %.2f is: %.2f.\n\n", first_number, second_number, multiplication);
        break;

    case 4:
        division = (first_number/second_number);
        printf("\n The division between the numbers %.2f and %.2f is: %.2f.\n\n", first_number, second_number, division);
        break;

    default:
        printf("\n Invalid operation! \n Please select one of the options listed above.\n\n");
    }

    system("pause");
    return 0;
}
