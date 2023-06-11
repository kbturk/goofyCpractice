#include <stdio.h>

#define MAXVAL 1000
#define TABSTOP 8

void entab(int *l, char *t);

void main(int argc, char *argv[]) {
    int tab[MAXVAL]; //list of tabs
    int *tp = &tab[0]; //pointer to tab array
    char t[MAXVAL]; //output array
    int ia; //tab conversion
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
    entab(&tab[0], &t[0]);
    printf("entab:\n%s\n", t);

}

void entab(int *tab, char *t) {
    int nspace = 0, c, ntab = 0;
    char *tempt = t;
    int tab_stop;
    tab_stop = (*tab == -999) ? TABSTOP: *tab++;

    while((c = getchar()) != EOF && (t-tempt) < MAXVAL) {
        while (c == ' ' && c != EOF)
        {
            nspace += 1;
            if (!(((t+nspace) - tempt) % tab_stop)) {
                nspace = 0;
                ntab += 1;
                tempt = (t+nspace);
                tab_stop = (*tab == -999) ? TABSTOP: *tab++;
            }
            c = getchar();
        }
        while (nspace-- > 0)
            *t++ = ' ';
        nspace = 0;
        while (ntab-- > 0)
            *t++ = '\t';
        ntab = 0;
        *t++ = c;

        if (c == '\n')
            tempt = t;
    }
    *t = '\0';
        if ((t - tempt) >= MAXVAL) {
            printf("warning: file was longer than array\n");
            return;
        }
    
}
