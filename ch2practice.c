#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
int strlen2(char s[]);

int main() {
    int len, max;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
        printf("len: %d line:%s\n", len, line);
    return 0;
}

int getline(char s[], int lim) {
    int c, i;

    for (i=0; (i < lim - 1) * ((c=getchar()) != '\n') * (c != EOF); ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

int strlen2(char s[]) {
    int i = 0;

    while (s[i] != '\0')
        ++i;
    return i;
}
