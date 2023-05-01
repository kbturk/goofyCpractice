#include <stdio.h>
#include <string.h>
#include "calc.h"
#define BUFSIZE 100

static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp = 0; /* next free position in buf */

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

//idk, make getch and ungetch only push back one char?
//there are a lot of ways to do this like have a temp char
//variable that stores something and is nan when it's popped
//but... in this case, I like lazy solutions that take
//advantage of existing variables
int onegetch(void) {
    return (bufp == 1) ? buf[--bufp] : getchar();
}

void oneungetch(int c) {
    if (bufp > 0)
        printf("oneungetch: exceeded one char BUFSIZE\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[]) {
    int i;
    for (i = strlen(s) - 1; i >= 0; i--) {
        ungetch(s[i]);
        printf("pushed %c onto buffer\n", s[i]);
    }
    //check work:
    printf("whole buffer: ");
    for (i=bufp; i >= 0; i--)
        printf("%c",buf[i]);
    printf("\n");
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


