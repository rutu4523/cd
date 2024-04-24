#include <stdio.h>
#include <string.h>

int main() {
    char t[5], nt[10], p[5][5], first[10][5], temp;
    int i, j, not, nont, k = 0, f = 0;

    printf("Enter the number of Non-terminals in the grammar: ");
    scanf("%d", &nont);
    
    printf("Enter the Non-terminals in the grammar: ");
    for (i = 0; i < nont; i++) {
        scanf(" %c", &nt[i]);
    }
    
    printf("Enter the number of Terminals in the grammar (Enter 'e' for epsilon): ");
    scanf("%d", &not);
    
    printf("Enter the Terminals in the grammar: ");
    for (i = 0; i < not; i++) {
        scanf(" %c", &t[i]);
    }

    for (i = 0; i < nont; i++) {
        p[i][0] = nt[i];
        first[i][0] = nt[i];
    }

    printf("Enter the productions:\n");
    for (i = 0; i < nont; i++) {
        printf("Enter the production for %c (End the production with '$' sign): ", p[i][0]);
        for (j = 1; p[i][j - 1] != '$';) {
            scanf(" %c", &p[i][j]);
            j++;
        }
    }

    for (i = 0; i < nont; i++) {
        printf("\nThe production for %c -> ", p[i][0]);
        for (j = 1; p[i][j] != '$'; j++) {
            printf("%c", p[i][j]);
        }
    }

    for (i = 0; i < nont; i++) {
        f = 0;
        for (j = 1; p[i][j] != '$'; j++) {
            for (k = 0; k < not; k++) {
                if (f == 1)
                    break;
                if (p[i][j] == t[k]) {
                    first[i][j] = t[k];
                    first[i][j + 1] = '$';
                    f = 1;
                    break;
                } else if (p[i][j] == nt[k]) {
                    first[i][j] = first[k][j];
                    if (first[i][j] == 'e')
                        continue;
                    first[i][j + 1] = '$';
                    f = 1;
                    break;
                }
            }
        }
    }

    for (i = 0; i < nont; i++) {
        printf("\n\nThe first of %c -> ", first[i][0]);
        for (j = 1; first[i][j] != '$'; j++) {
            printf("%c\t", first[i][j]);
        }
    }

    return 0;
}
/*Enter the number of Non-terminals in the grammar: 3
Enter the Non-terminals in the grammar: ERT 
Enter the number of Terminals in the grammar (Enter 'e' for epsilon): 5
Enter the Terminals in the grammar: ase*+
Enter the productions:
Enter the production for E (End the production with '$' sign): a+s$
Enter the production for R (End the production with '$' sign): e$
Enter the production for T (End the production with '$' sign): Rs$

The production for E -> a+s
The production for R -> e
The production for T -> Rs

The first of E -> a

The first of R -> e

The first of T -> e     s*/