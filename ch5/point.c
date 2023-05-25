#include <stdio.h>
#include "point.h"

//5-5 exercises:
//5-5 write a version of the library functions strncpy, strncat, and strncmp using s,t,n (see appendix B)
//5-6 eh.... rewrite getline, atoi, itoa, reverse, strindex and getop
//note: was on page 107

//strcopy: copy t to s; pointer version from 5-5
void strcpy2(char *s, char *t) {
    while (*s++ = *t++)
        ;
}

//ex 5-3: write a pointer version fo the function strcat from Ch2:
void strcat2(char *s, char *t) {
    while (*s) //find the end of s
        s++;
    while (*s++ = *t++) //copy t
        ;
}

//5-4 write the function strend(s,t) which returns 1 if the string t occurs at the end of the string s, zero otherwise.
//reverse both strings and check
int strend(char *s,char *t) {
    char *temp = t;
    while (*s)//advance to end
        s++;
    while (*t)//advance to end
        t++;
    while (*s-- == *t-- && t >= temp)//reverse check
        ;
    if (temp == t + 1) return 1;
    else return 0;
}

void strendWrap(char *s, char *t) {
    if (strend( s, t))
        printf("'%s' is at the end of '%s'\n", t, s);
    else
        printf("'%s' is NOT at the end of '%s'\n", t, s);
}

