#include <stdio.h>

#define MAXVAL 1000
#define TABSTOP 8


void detab(int *l, char *t);

//Exercise 5-11 take a list of tab stops as arguments
//There's very little error handling here.
//can't take a tab stop larger than 10 currently.
void main(int argc, char *argv[]) {
    int tab[MAXVAL]; //list of tabs
    int *tp = &tab[0];
    char t[MAXVAL]; //output array
    int ia;
    char s[MAXVAL];
    while (--argc) {
        
        ia = (int)**++argv - '0';
        if (ia < 0) {
            printf("Error: tab stop %d less than 0\n", ia);
            return;
        }
        *tp++ = ia;
    }

    *tp = -999;
    detab(&tab[0], &t[0]);
    printf("output:\n%s\n", t);
}

void detab(int *tab, char *t) {
    //t is a global 1d array
    char *temp = t;
    char *temp2 = t;
    int c;
    int tab_stop;
    while ((c = getchar()) != EOF && (t-temp) < MAXVAL) {
        if (c == '\t') {
            tab_stop = (*tab == -999) ? TABSTOP: *tab++;
            *t++ = ' ';
            while((t - temp2) % tab_stop)
                *t++ = ' ';
            temp2 = t;
        }
        else
            *t++ = c;
        if (c == '\n')
            temp2 = t;
    }
    *t = '\0';
    if ((t - temp) >= MAXVAL) {
        printf("warning: file was longer than array\n");
        return;
    }
}
