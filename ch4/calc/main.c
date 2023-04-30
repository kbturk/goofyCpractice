#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "calc.h"
#include <math.h>

int main() {
    int type;
    double op2;
    char s[MAXOP];
    double varlist[VARLENGTH];
    int address;

    printf("--reverse Polish calculator!--\n");
    printf("now with variables 'a' - 'z'!\n");
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
                else if (strcmp2(s, "sin"))
                    push(sin(pop()));
                else if (strcmp2(s, "exp"))
                    push(exp(pop()));
                else if (strcmp2(s, "pow")) {
                    op2 = pop();
                    push(pow(pop(),op2));
                }

                else printf("warning!! word didn't match\n");
                break;
            case VARIABLE:
                //really primative variables
                address = s[0] - 'a';
                if (varlist[address])
                    push(varlist[address]);
                else
                    printf("%c not defined\n", address + 'a');
                break;
            case SETVAR:
                address = s[0] - 'a';
                if ((type = getop(s)) == NUMBER) {
                    push((varlist[address] = atof(s)));
                    printf("assigned %s to %c\n",s,address + 'a');
                    break;
                } else 
                    printf("tried to assign %s to var %d, but something went wrong\n", s, address + 'a');
            default:
                printf("error: unknown command %s\n", s);
                break;
        }

    }
    return 0;
}
