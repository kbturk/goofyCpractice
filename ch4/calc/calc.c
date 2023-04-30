#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "calc.h"

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
        printf("pushed %g to stack\n", f);
    }
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        printf("popped %g, sp is now %d from stack\n", val[sp-1], sp-1);
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c;

    /* skip white space */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] ='\0';
    if (!isdigit(c) && c != '.' && c!= '-' && !isletter(c))
        return c; /*not a pos or neg number*/
    i = 0;
    if (isdigit(c)) /*collect integer part*/
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /*collect fractional part*/
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '-')
        while (isdigit(s[++i] = c = getch()))
            ;
    if (isletter(c)) {
        while (isletter(s[++i] = c = getch()) && c !='=')
            ;
        s[i] = '\0';
        if (strlen(s) == 1 &&
                s[0] >= 'a' &&
                s[0] <= 'z') {
            //peek
            //advance if there is white space
            if (c == ' ' || c == '\t')
                while((c = getch()) == ' ' || c == '\t')
                    ;
            //check variables
            printf("check calc s: %s\n", s);
            printf("check calc c: %c\n", c);
            if (c == '=') {
                return SETVAR;
            }
            else
                ungetch(c);
            return VARIABLE;
        }
        return WORD;
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /*push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: exceeded BUFSIZE\n");
    else
        buf[bufp++] = c;
}

//look at the next character on the stack
int peek(void) {
    int temp;
    temp = getch();
    while (temp == ' ' || temp == '\t')
        temp = getch();
    ungetch(temp);
    return temp;
}

int isletter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/*small calc functions*/

//returns 0 or 1 if strings match
int strcmp2(char s[], char t[]) {
    int i, j;
    for (i = 0; t[i] == s[i] && t[i] != '\0'; i++)
        ;
    for (j = 0; t[j] != '\0'; ++j)
        ;
    return (j == i);
}

//print the top item on the stack
void ptop() {
    printf("%g\n", val[sp - 1]);
    return;
}

//print the whole stack
void pall() {
    int i;
    for (i = sp - 1; i >= 0; --i)
        printf("%g,", val[i]);
    printf("\n");
}

//duplicate the top item on the stack
void duplicate() {
    double temp;
    temp = val[sp - 1];
    push(temp);
    printf("duplicated: %g, %g\n", val[sp - 1], val[sp - 2]);
    return;
}

//swap the top two elements on the stack
void swap() {
    int t1, t2;
    t1 = pop();
    t2 = pop();
    push(t1);
    push(t2);
    printf("swapped: %g, %g\n", val[sp - 1], val[sp - 2]);
}
