#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

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
            //printf("check calc s: %s\n", s);
            //printf("check calc c: %c\n", c);
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

int isletter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

//returns 0 or 1 if strings match
int strcmp2(char s[], char t[]) {
    int i, j;
    for (i = 0; t[i] == s[i] && t[i] != '\0'; i++)
        ;
    for (j = 0; t[j] != '\0'; ++j)
        ;
    return (j == i);
}
