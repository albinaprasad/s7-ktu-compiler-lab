#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n, m = 0;
char a[10][10], f[10];
int visited[256] = {0}; // For marking visited variables to avoid duplicates

void follow(char c);
void first(char c);

int main() {
    int i, z;
    char c, ch;
    printf("Enter the number of productions:\n");
    scanf("%d", &n);
    getchar(); // Clear newline left in buffer after scanf

    printf("Enter the productions:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", a[i]);
        getchar(); // Clear newline left in buffer
    }

    do {
        m = 0;
        memset(visited, 0, sizeof(visited)); // Reset visited array for each variable
        printf("Enter a variable whose first & follow is to be found: ");
        scanf(" %c", &c); // Notice the space before %c to ignore leftover newlines

        // Calculate first set
        first(c);
        printf("First(%c) = { ", c);
        for (i = 0; i < m; i++) {
            printf("%c ", f[i]);
        }
        printf("}\n");

        // Reset for follow set
        memset(f, 0, sizeof(f));
        m = 0;
        memset(visited, 0, sizeof(visited)); // Reset visited array for follow calculation
        
        // Calculate follow set
        follow(c);
        printf("Follow(%c) = { ", c);
        for (i = 0; i < m; i++) {
            printf("%c ", f[i]);
        }
        printf("}\n");

        printf("Want to continue (1 = yes / 0 = no)? ");
        scanf("%d", &z);
        getchar(); // Clear newline left in buffer
    } while (z == 1);

    return 0;
}

void first(char c) {
    int k;
    // If the character is not uppercase, it is a terminal
    if (!isupper(c)) {
        if (!visited[(int)c]) { // Check if already added to avoid duplicates
            f[m++] = c;
            visited[(int)c] = 1;
        }
        return;
    }

    for (k = 0; k < n; k++) {
        if (a[k][0] == c) { // Production rule starting with `c`
            if (a[k][2] == '$') {
                follow(a[k][0]); // epsilon production, call follow
            } else if (islower(a[k][2])) {
                if (!visited[(int)a[k][2]]) { // Add only if not visited
                    f[m++] = a[k][2];
                    visited[(int)a[k][2]] = 1;
                }
            } else {
                first(a[k][2]); // Recursive call for non-terminals
            }
        }
    }
}

void follow(char c) {
    // Rule 1: Add `$` to the follow of the start symbol
    if (a[0][0] == c) {
        f[m++] = '$';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 2; j < strlen(a[i]); j++) {
            if (a[i][j] == c) {
                if (a[i][j + 1] != '\0') {
                    first(a[i][j + 1]); // Call first for the next symbol
                }
                if (a[i][j + 1] == '\0' && c != a[i][0]) {
                    follow(a[i][0]); // If at the end, call follow for LHS
                }
            }
        }
    }
}
