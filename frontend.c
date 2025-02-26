#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototypes
void display_menu();
void add();
void subtract();
void multiply();
void divide();
void clear_input_buffer();

int main() {
    char choice;
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        clear_input_buffer();  // Clear any extra characters in input buffer

        switch(toupper(choice)) {
            case 'A':
                add();
                break;
            case 'S':
                subtract();
                break;
            case 'M':
                multiply();
                break;
            case 'D':
                divide();
                break;
            case 'Q':
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
        
        if(toupper(choice) != 'Q') {
            printf("\nPress Enter to continue...");
            clear_input_buffer();
        }
    } while(toupper(choice) != 'Q');

    return 0;
}

void display_menu() {
    system("clear || cls");  // Clear screen (works for both Unix and Windows)
    printf("================================\n");
    printf("      CALCULATOR FRONT-END      \n");
    printf("================================\n");
    printf("[A] Add two numbers\n");
    printf("[S] Subtract two numbers\n");
    printf("[M] Multiply two numbers\n");
    printf("[D] Divide two numbers\n");
    printf("[Q] Quit program\n");
    printf("================================\n");
}

void add() {
    double num1, num2;
    printf("\nEnter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
    clear_input_buffer();
    printf("\nResult: %.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
}

void subtract() {
    double num1, num2;
    printf("\nEnter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
    clear_input_buffer();
    printf("\nResult: %.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
}

void multiply() {
    double num1, num2;
    printf("\nEnter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
    clear_input_buffer();
    printf("\nResult: %.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
}

void divide() {
    double num1, num2;
    printf("\nEnter numerator: ");
    scanf("%lf", &num1);
    printf("Enter denominator: ");
    scanf("%lf", &num2);
    clear_input_buffer();
    
    if(num2 == 0) {
        printf("\nError: Division by zero is not allowed!\n");
    } else {
        printf("\nResult: %.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Clear remaining characters in buffer
}