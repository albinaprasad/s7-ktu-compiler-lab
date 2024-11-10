#include<stdio.h>
#include<string.h>
#include<ctype.h>

char input[100];  // Increased size for longer expressions
int i = 0, error = 0;

void E();    // Parses an expression
void T();    // Parses a term
void F();    // Parses a factor

// E -> T E'
void E() {
    T();
    if (input[i] == '+') {  // Handle the '+' operator directly in E
        i++;
        T();
    }
}

// T -> F T'
void T() {
    F();
    if (input[i] == ' ') {  // Handle the '' operator directly in T
        i++;
        F();
    }
}

// F -> (E) | id
void F() {
    if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')')
            i++;
        else
            error = 1;  // Error if no closing ')'
    } else if (isalpha(input[i])) {
        i++;  // Accept single variable or identifier
    } else {
        error = 1;  // Error for invalid input
    }
}

int main() {
    printf("Enter the arithmetic expression: ");
    scanf("%s", input);

    E();  // Start parsing the expression

    if (input[i] == '\0' && error == 0)
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");

    return 0;
}