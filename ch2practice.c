#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
int strlen2(char s[]);
int atoi2(char s[]);
void squeeze2(char s1[], char s2[]);

int main() {
    int len, max, temp;
    char line[MAXLINE];
    char s1[] = "stringy";
    char s2[] = "string";

    while ((len = getline(line, MAXLINE)) > 0) {
        printf("len: %d line:%s", len, line);
    }
    printf("\n");
    printf("line 1234 becomes: %d\n", atoi2("1234"));
    printf("squeeze2 check:\n");

    squeeze2(s1,s2);
    printf("stringy vs string: %s",s1);
    return 0;
}

int getline(char s[], int lim) {
    int c, i;

    for (i=0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i)
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
//converts a text string of digits to an integer value
int atoi2(char s[]) {
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

//exercise 2-4: deletes each char in s1 that matches
//any char in s2
void squeeze2(char s1[], char s2[]) {
    int i, j, k;
    bool match;

    for (i = j = 0; s1[i] != '\0'; i++) {
        match = false;
        for (k = 0; s2[k] != '\0'; k++){
            if (s1[i] == s2[k]) {match = true;
            }
        }
        if (!match) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}
