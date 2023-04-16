#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);
int stop(char line[]);
void striptrailing(char to[], char from[]);
void copyreverse(char to[], char from[]);

/*print the longest input line*/
int main() {
    int len;
    int max;
    int diff;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
        if (len > 80) {
            printf("long line detected:\n%s",line);
        }
    }
    if (max > 0)
        printf("longest line was: %d\n%s", max, longest);
    else
        printf("no lines contained characters!");
    return 0;
}

int getline(char s[], int lim) {

    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) !=EOF && c != '\n'; ++i) s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
