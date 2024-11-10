#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Global variables
int n;              // Number of productions
int m = 0;          // Counter for result array
char a[10][10];     // Array to store productions
char f[10];         // Array to store FIRST/FOLLOW sets

// Function declarations
void follow(char c);
void first(char c);

int main() {
    int i, z;
    char c, ch;

    // Input the number of productions
    printf("Enter the no of productions:\n");
    scanf("%d", &n);

    // Input the productions
    printf("Enter the productions:\n");
    for(i = 0; i < n; i++) {
        scanf("%s%c", a[i], &ch);
    }

    // Main processing loop
    do {
        // Reset counter for new computation
        m = 0;

        // Get the symbol to compute FIRST and FOLLOW
        printf("Enter the elements whose first & follow is to be found:");
        scanf("%c", &c);

        // Calculate and print FIRST set
        first(c);
        printf("First(%c)={", c);
        for(i = 0; i < m; i++) {
            printf("%c", f[i]);
        }
        printf("}\n");

        // Reset for FOLLOW calculation
        strcpy(f, " ");
        m = 0;

        // Calculate and print FOLLOW set
        follow(c);
        printf("Follow(%c)={", c);
        for(i = 0; i < m; i++) {
            printf("%c", f[i]);
        }
        printf("}\n");

        // Ask to continue
        printf("Continue(0/1)?");
        scanf("%d%c", &z, &ch);
    } while(z == 1);

    return 0;
}

/**
 * Computes FIRST set of a given symbol
 * @param c: The symbol to compute FIRST set for
 */
void first(char c) {
    int k;

    // If c is terminal, add it to result
    if(!isupper(c)) {
        f[m++] = c;
        return;
    }

    // Check all productions
    for(k = 0; k < n; k++) {
        if(a[k][0] == c) {  // If LHS matches
            if(a[k][2] == '$') {  // If production derives epsilon
                follow(a[k][0]);
            }
            else if(islower(a[k][2])) {  // If first symbol is terminal
                f[m++] = a[k][2];
            }
            else {  // If first symbol is non-terminal
                first(a[k][2]);
            }
        }
    }
}

/**
 * Computes FOLLOW set of a given non-terminal
 * @param c: The non-terminal to compute FOLLOW set for
 */
void follow(char c) {
    int i, j;

    // Rule 1: Add $ to FOLLOW set of start symbol
    if(a[0][0] == c) {
        f[m++] = '$';
    }

    // Check all productions
    for(i = 0; i < n; i++) {
        for(j = 2; j < strlen(a[i]); j++)
         {
            if(a[i][j] == c) 
            {
                  // If c is found in RHS
                if(a[i][j+1] != '\0') {  // If there's a symbol after c
                    first(a[i][j+1]);
                }
                if(a[i][j+1] == '\0' && c != a[i][0]) {  // If c is at end and not left recursive
                    follow(a[i][0]);
                }
            }
        }
    }
}