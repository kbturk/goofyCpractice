#include <stdio.h>
#include <ctype.h>
#include "getch.h"
#include "arrayallo.h"
#include "point.h"

#define dprint(x) printf(#x " = %g\n",x);
#define iprint(x) printf(#x " = %d\n",x);
#define SIZE 100

void swapi(int, int);
void swapp(int *, int *);
int getint(int *);

//book examples from ch5 in K&R
int main() {
    //var 5-1
    int x = 1, y = 2, z[10];
    int *ip;

    //var 5-2
    int a = 5, b = 9;

    //var 5-3
    int n, array[SIZE], c;

    //var ex-5-3
    char s[SIZE] = "hi ";
    char t[SIZE] = "MOM!";

    //var ex 5-4
    char s1[SIZE] = "the toad";
    char t1[SIZE] = "toad";
    char s2[SIZE] = "baked potato";
    char t2[SIZE] = "potato";


    //5-1
    ip = &x;
    iprint(ip);
    iprint(*ip);
    iprint(x);

    y = *ip;
    iprint(y);
    *ip = 0;
    iprint(*ip);
    iprint(x);
    iprint(y);
    ip = &z[0];
    iprint(ip);

    //5-2
    iprint(a);
    iprint(b);

    swapi(a,b);
    iprint(a);
    iprint(b);

    swapp(&a,&b);
    iprint(a);
    iprint(b);

    //exercise 5-3
    strcat2(s,t);
    printf("%s\n",s);

    //5-4
    strendWrap(s1,t1);
    strendWrap(s2,t1);
    strendWrap(s2,t2);

    //5-3
    //exercise 5-1: in getint, if + or - is not followed by a digit,
    //put it back on the stack.
    /*
    for (n = 0; n < SIZE && (c = getint(&array[n])) !=EOF; n++)
        ;

    //see what n ended up as
    iprint(n);

    int i;
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", i, array[i]);
    }

    //check that getint put a neg back on the stack
    printf("next char: %c\n", getch());
    */
}

//doesn't work bc you're swapping copies.
void swapi(int x, int y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}

void swapp(int *px, int *py) {
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

/*get int: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;
    int temp;

    while (isspace(c = getch())) /*skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /*it's not a number*/
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        temp = c;
        if (!isdigit(c = getch())) {
            if (c != EOF)
                ungetch(c);
            ungetch(temp);
            return EOF;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
