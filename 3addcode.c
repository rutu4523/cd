#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int temp_count = 0;

char* new_temp() {
    char* temp = (char*)malloc(sizeof(char) * 3);
    sprintf(temp, "t%d", temp_count++);
    return temp;
}

void generate_three_address_code(char op, char* arg1, char* arg2, char* result) {
    printf("%s = %s %c %s\n", result, arg1, op, arg2);
}

int main() {
    char expr[100];
    printf("Enter an arithmetic expression (e.g., a + b * c - d): ");
    fgets(expr, sizeof(expr), stdin);

    char* token = strtok(expr, " \n");
    char* temp1 = strdup(token);
    char* temp2 = NULL;
    char op;

    while ((token = strtok(NULL, " \n")) != NULL) {
        if (strchr("+-*/", token[0])) {
            op = token[0];
        } else {
            temp2 = strdup(token);
            char* result = new_temp();
            generate_three_address_code(op, temp1, temp2, result);
            temp1 = result;
        }
    }

    free(temp1);
    if (temp2) free(temp2);
    return 0;
}
/*a + b * c - d*/