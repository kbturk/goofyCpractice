#include <stdio.h>

#define MAXVAL 1000
#define TABSTOP 8
#define TABSTART 0

void detab(int m, int n, char *t);

//Exercise 5-12 extend detab and entab
//to accept the shorthand: entab -m +n
//to mean stops every n columns starting with m.
//choose a convient default behavior.
//for me, default would be m=0; n=8.
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

    detab(m, n, &t[0]);
    printf("output:\n%s\n", t);
}

void detab(int m, int n, char *t) {
    //t is a global 1d array
    char *temp = t;
    char *temp2 = t;
    int c, i = 0;

    while ((c = getchar()) != EOF && (t-temp) < MAXVAL) {
        i++;
        if (c == '\t' && i > m) {
            *t++ = ' ';
            while((t - temp2) % n)
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
