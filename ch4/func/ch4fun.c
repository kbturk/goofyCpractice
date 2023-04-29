#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

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

int pow2(int base, int raise) {
    int temp;
    for (temp = 1; raise > 0; --raise)
        temp *=base;
    return temp;
}

//convert string s to double very rudamentary with no error handling
double atof(char s[])
{
    double val, power, expon, sign;
    int i, expsign, p;
    expsign = 1;
    expon = 1.0;

    //skip white space
    for (i = 0; isspace(s[i]); i++) 
        ;
    //capture sign
    sign = (s[i] == '-') ? -1.0 : 1.0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    //skip white space again
    for (i; isspace(s[i]); i++)
        ;

    //digits before a '.'
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    //optional '.'
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    //optional exponential
    if (s[i] == 'e' || s[i] == 'E') {
        ++i;
        //handle neg exp's
        if (s[i] == '-') {
            expsign = -1;
            i++;
        }

        //capture p
        for (p = 0; isdigit(s[i]); i++)
            p = 10 * p + (s[i] - '0');

        expon = pow2(10, p);
        expon = (expsign == -1) ? (1.0/expon) : expon;
    }

    return (double)sign * val * (double)expon / power;
}
