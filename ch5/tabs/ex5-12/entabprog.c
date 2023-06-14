#include <stdio.h>

#define MAXVAL 1000
#define TABSTOP 8
#define TABSTART 0

void entab(int m, int n, char *t);

void main(int argc, char *argv[]) {
    char t[MAXVAL]; //output array
    int c, m=TABSTART, n=TABSTOP;

    while (--argc && ((c = (*++argv)[0]) == '-' | c == '+')) {
        switch (c) {
            case '-':
                m = (int)*++argv[0] - '0';
                if (m < 0) {
                    printf("Error: m is < 0: %d\n", m);
                    return;
                }
                break;
            case '+':
                n = (int)*++argv[0] - '0';
                if (n <= 0) {
                    printf("Error: n is <= 0: %d. using default\n", n);
                    n=TABSTOP;
                    return;
                }
                break;
            default:
                printf("Usage: detab -m +n\n");
                return;
        }
    }

    entab(m, n, &t[0]);
    printf("output:\n%s\n", t);

}

void entab(int m, int n, char *t) {
    int nspace = 0, ntab = 0, c, i = 0;
    char *tempt = t;

    while((c = getchar()) != EOF && (t-tempt) < MAXVAL) {
        i++;
        while (c == ' ' && c != EOF && i > m)
        {
            nspace += 1;
            if (!(((t+nspace) - tempt) % n)) {
                nspace = 0;
                ntab += 1;
                tempt = (t+nspace);
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
