#include <stdio.h>

#define MAXVAL 1000
#define TABSTOP 8

void detab(char *t);
void entab(char *s, char *t);

int main(int argc, char *argv[]) {
   char s[MAXVAL];
   char t[MAXVAL];

   detab(s);
   printf("detab:\n");
   printf("%s\n", s);
   printf("entab:\n");
   entab(s,t);
   printf("%s\n", t);
}

void detab(char *t) {
    char *temp = t;
    char *temp2 = t;
    int c;

    while ((c = getchar()) != EOF && (t-temp) < MAXVAL) {
        if (c == '\t') {
            *t++ = ' ';
            while((t - temp2) % TABSTOP)
                *t++ = ' ';
        }
        else
            *t++ = c;
        if (c == '\n')
            temp2 = t;
    }
    if ((t - temp) >= MAXVAL) {
        printf("warning: file was longer than array\n");
        return;
    }
}

void entab(char *s, char *t) {
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
