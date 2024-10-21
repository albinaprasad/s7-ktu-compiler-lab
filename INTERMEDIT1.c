#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct code {
    char op[2], a1[5], a2[5], result[5];
    int flag;
} in[10];

int n;
int j = 0;

void check(int p, char *res1);

int main() {
    int i, res;
    char op, res1[10];

    printf("\n\nEnter the maximum number of expressions: ");
    scanf("%d", &n);

    // Input the expressions
    for (i = 0; i < n; i++) {
        scanf("%s", in[i].op);
        scanf("%s", in[i].a1);
        scanf("%s", in[i].a2);
        scanf("%s", in[i].result);
        in[i].flag = 0;
    }

    // Process constant folding
    for (i = 0; i < n; i++) {
        if ((isdigit(in[i].a1[0]) && isdigit(in[i].a2[0])) || strcmp(in[i].op, "=") == 0) {
            if (strcmp(in[i].op, "=") == 0) {
                // Assignment operation
                strcpy(res1, in[i].a1);
            } else {
                // Arithmetic operation
                int a1 = atoi(in[i].a1);
                int a2 = atoi(in[i].a2);
                op = in[i].op[0];

                switch (op) {
                    case '+':
                        res = a1 + a2;
                        break;
                    case '-':
                        res = a1 - a2;
                        break;
                    case '*':
                        res = a1 * a2;
                        break;
                }
                sprintf(res1, "%d", res);
            }
            in[i].flag = 1;  // Mark this expression as processed
            check(i, res1);
        }
    }

    // Output the expressions after constant folding
    printf("\nFinal expressions after constant folding:\n");
    for (i = 0; i < n; i++) {
        printf("%s %s %s %s\n", in[i].op, in[i].a1, in[i].a2, in[i].result);
    }

    return 0;
}

void check(int p, char *res1) {
    for (int i = p + 1; i < n; i++) {
        if (strcmp(in[p].result, in[i].a1) == 0) {
            strcpy(in[i].a1, res1);
        }
        if (strcmp(in[p].result, in[i].a2) == 0) {
            strcpy(in[i].a2, res1);
        }
    }
}
