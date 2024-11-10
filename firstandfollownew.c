#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Global variables
int n, m = 0, p, i = 0, j = 0;
char a[10][10], f[10];

// Function prototypes
void follow(char c);
void first(char c);

int main() {
    int i, z;
    char c, ch;

    // Input number of productions
    printf("Enter the number of productions:\n");
    scanf("%d", &n);

    // Input each production
    printf("Enter the productions:\n");
    for (i = 0; i < n; i++) {
        scanf("%s%c", a[i], &ch); // Reading production and handling newline character
    }

    // Loop to find First and Follow sets
    do {
        m = 0; // Reset index for First set output

        printf("Enter the element whose First & Follow is to be found: ");
        scanf("%c", &c); // Read the non-terminal

        // Calculate First set
        first(c);
        printf("First(%c) = {", c);
        for (i = 0; i < m; i++) {
            printf("%c", f[i]);
        }
        printf("}\n");

        // Reset the `f` array for Follow set calculation
        strcpy(f, " ");
        m = 0; // Reset index for Follow set output

        // Calculate Follow set
        follow(c);
        printf("Follow(%c) = {", c);
        for (i = 0; i < m; i++) {
            printf("%c", f[i]);
        }
        printf("}\n");

        // Ask the user if they want to continue
        printf("Continue (0/1)? ");
        scanf("%d%c", &z, &ch); // Read choice and handle newline
    } while (z == 1);

    return 0;
}

// Function to compute the First set of a given non-terminal
void first(char c) {
    int k;
    
    // If `c` is a terminal, add it directly to First set
    if (!isupper(c)) {
        f[m++] = c;
        return;
    }

    // Iterate through all productions
    for (k = 0; k < n; k++) {
        // Check if the left side of the production is `c`
        if (a[k][0] == c) {
            // If the right side is epsilon (`$`)
            if (a[k][2] == '$') {
                follow(a[k][0]); // Call follow for the non-terminal
            }
            // If the right side starts with a terminal (lowercase letter)
            else if (islower(a[k][2])) {
                f[m++] = a[k][2]; // Add it directly to First set
            }
            // If the right side starts with a non-terminal (uppercase letter)
            else {
                first(a[k][2]); // Recursively call first for the non-terminal
            }
        }
    }
}

// Function to compute the Follow set of a given non-terminal
void follow(char c) {
    // Add `$` to the follow of the start symbol
    if (a[0][0] == c) {
        f[m++] = '$';
    }

    // Iterate through all productions
    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(a[i]); j++) {
            // Check if `c` is in the production
            if (a[i][j] == c) {
                // If `c` is followed by another symbol, get the First of the next symbol
                if (a[i][j + 1] != '\0') {
                    first(a[i][j + 1]);
                }
                // If `c` is at the end of the production and not the same as the left side
                if (a[i][j + 1] == '\0' && c != a[i][0]) {
                    follow(a[i][0]); // Recursively call follow for the left side
                }
            }
        }
    }
}
