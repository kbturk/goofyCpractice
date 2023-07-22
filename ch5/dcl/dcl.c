#include "dcl.h"
#include "getch.h"

//convert declaration to words
int main(void) {
    while (gettoken() != EOF) { //1st token on line
        strcpy(datatype, token); //is the datatype
        out[0] = '\0';
        dcl(); //parse the rest of the line
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

int gettoken(void) { //return the next token
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    //skip white space
    while ((c = getch()) == ' ' || c == '\t')
        ;
    switch (c) {
        case '(':
            if ((c = getch()) == ')') {
                strcpy(token, "()");
                return tokentype = PARENS;
            } else {
                ungetch(c);
                return tokentype = '(';
            }
        case '[':
            for (*p++ = c; (*p++ = getch()) != ']';)
                ;
            *p = '\0';
            return tokentype = BRACKETS;
        default:
            if (isalpha(c)) {
                for (*p++ = c; isalnum(c = getch()); )
                    *p++ = c;
                *p = '\0';
                ungetch(c);
                return tokentype = NAME;
            }
            return tokentype = c;
    }
}

//dcl: parse a declarator
void dcl(void) {
    int ns = 0;

    while (gettoken() == '*')
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

//dirdcl: parse a direct declarator
void dirdcl(void) {
    int type;

    if (tokentype == '(') { // (dcl)
        dcl();
        if (tokentype != ')')
            printf("error: missing ')'\n");
    } else if (tokentype == NAME)
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}
