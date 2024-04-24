#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

char stack[30];
int top = -1;

void push(char c) {
    top++;
    stack[top] = c;
}

char pop() {
    char c;
    if (top != -1) {
        c = stack[top];
        top--;
        return c;
    }
    return 'x';
}

void printstat() {
    int i;
    cout << "\n\t\t\t $";
    for (i = 0; i <= top; i++)
        cout << stack[i];
}

int main() {
    int i, l;
    char s1[20], s2[20], ch1, ch2, ch3;

    cout << "\nLR PARSING";
    cout << "\nENTER THE EXPRESSION:" << endl;
    cin >> s1;

    l = strlen(s1);

    cout << "\n\t\t $";

    for (i = 0; i < l; i++) {
        if (isalpha(s1[i])) { // Check if the character is an alphabet (id)
            s1[i] = ' ';
            push('E');
            printstat();
            cout << s1[i]; // Print the character itself
        } else if (s1[i] == '+' || s1[i] == '-' || s1[i] == '*' || s1[i] == '/') {
            push(s1[i]);
            printstat();
        }
    }

    printstat();

    while (true) {
        ch1 = pop();

        if (ch1 == 'x') {
            cout << "\n\t\t\t $";
            break;
        }

        if (ch1 == '+' || ch1 == '/' || ch1 == '*' || ch1 == '-') {
            ch3 = pop();
            if (ch3 != 'E') {
                cout << "error";
                // exit();
            } else {
                push('E');
                printstat();
            }
        }
        ch2 = ch1;
    }

    return 0;
}

/*a+b*c
a+b*c

                 $
                         $E 
                         $E+
                         $E+E 
                         $E+E*
                         $E+E*E 
                         $E+E*E
                         $E+E
                         $E
                         $
*/
