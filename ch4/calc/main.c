#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "calc.h"
#include <math.h>

int main() {
    int type;
    double op2;
    char s[MAXOP];
    double varlist[VARLENGTH];
    int address, i;
    double last;

    //This is hacky
    for (i = 0; i < VARLENGTH; i++)
        varlist[i] = -.00000000009;
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
                printf("\t%.8g\n", (last = pop()));
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
                else if (strcmp2(s, "last")) {
                    //printf("last printed val: %g\n", last);
                    push(last);
                }
                else printf("warning!! word didn't match\n");
                break;
            case VARIABLE:
                //really primative variables
                address = s[0] - 'a';
                if (address > VARLENGTH) {
                    printf("DANGER! s[0] exceeds VARLENGTH: %c",
                            s[0]);
                    break;
                }
                if (varlist[address] != -.00000000009) {
                    //printf("%c = ",s[0]);
                    push(varlist[address]);
                }
                else
                    printf("%c not defined\n", address + 'a');
                break;
            case SETVAR:
                address = s[0] - 'a';
                if ((type = getop(s)) == NUMBER) {
                    push((varlist[address] = atof(s)));
                    printf("%c is now: ",address + 'a');
                } else if (type = VARIABLE) {
                    push((varlist[address] = varlist[s[0] - 'a']));
                    //TODO: fix these next two lines
                //} else if (type = WORD && strcmp2(s, "last")) {
                  //  push((varlist[address] = last));
                } else
                    //TODO: add pushing whole s back onto stack.
                    printf("tried to assign %s to var %c, but something went wrong\n", s, address + 'a');
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }

    }
    return 0;
}
