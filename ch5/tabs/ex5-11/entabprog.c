#include <stdio.h>

#define MAXVAL 1000
#define TABSTOP 8

void entab();

void main(int argc, char *argv[]) {
    int tab[MAXVAL]; //list of tabs
    int *tp = &tab[0]; //pointer to tab array
    char t[MAXVAL]; //output array
    int ia; //tab conversion
    char s[MAXVAL];
    while (--argc) {
        
        ia = (int)**++argv - '0';
        printf("ia: %d\n", ia);
        if (ia < 0) {
            printf("Error: tab stop %d less than 0\n", ia);
            return;
        }
        *tp++ = ia;
        
        printf("argc:%d argv:%s\n",argc,*argv);
    }

    *tp = -999;
    for (tp = &tab[0]; *tp != -999; tp++)
        printf("tab: %d, ",*tp);
    printf("\n");
    detab(&tab[0], &t[0]);
    printf("t:\n%s\n", t);


}

void entab() {
    int nspace, c, ntab;
    char *tempt = t;
    char *temps = s;
    nspace = 0;
    ntab = 0;

    while((c = *s++) != '\0' && (t - tempt) < MAXVAL) {
        while (c == ' ' && c != '\0')
        {
            nspace += 1;
            if (!((s - temps) % TABSTOP)) {
                nspace = 0;
                ntab += 1;
            }
            c = *s++;
        }
        while (nspace-- > 0)
            *t++ = ' ';
        nspace = 0;
        while (ntab-- > 0)
            *t++ = '\t';
        ntab = 0;
        *t++ = c;

        if (c == '\n')
            temps = s;
        if ((t - tempt) >= MAXVAL) {
            printf("warning: file was longer than array\n");
            return;
        }
    }
}
