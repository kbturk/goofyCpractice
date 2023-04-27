#include <stdio.h>
#include <stdbool.h>

#include "ch4fun.h"
#define MAXLINE 1000

//book exercises
//getline: get line into s, return length
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) !=EOF && c !='\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

//strindex: return index of t in s, -1 if none
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k = 0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

//my own homebrew
//returns an int of how many matches there were.
//No text print right now.
int getmatch(char t[]) {
    int i, k, c;

    i = k = 0;
    while ((c=getchar()) !=EOF) {
        if (c == t[k]) {
            ++k;
        } else {
            k = 0;
        }
        if (k > 0 && t[k] == '\0') {
            i++;
            k = 0;
        }
    }

    return i;
}
