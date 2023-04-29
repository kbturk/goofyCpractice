#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "calc.h"

int main() {
    int type;
    double op2;
    char s[MAXOP];

    printf("--reverse Polish calculator!--\n");
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                push((double)((int)pop() % (int)op2));
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case WORD:
                if (strcmp2(s, "ptop"))
                       ptop();
                else if (strcmp2(s, "duplicate"))
                    duplicate();
                else if (strcmp2(s, "swap"))
                    swap();
                else if (strcmp2(s, "pall"))
                    pall();
                else printf("warning!! word didn't match\n");
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
