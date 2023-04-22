#include <stdio.h>
#include <stdbool.h>

#include "example.h"
#define MAXLINE 1000

//exercise 3-1
int binsearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high && x != v[mid]) {
        mid = (low+high)/2;
        if (x < v[mid]) 
            high = mid - 1;
        else low = mid + 1;
    }

    if (x == v[mid])
        return v[mid];
    else return -1;
}

//book example
int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <=high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

void trap(char s[], char t[]) {
    int i, j;
    bool temp;
    temp = false;

    for (i = 0, j = 0; s[i] != '\0'; i++, j++) {
        if (temp) {
            switch (s[i]) {
                case 'n':
                case 't':
                    t[j] = (s[i] == 't') ? '\t' : '\n';
                    break;
                default:
                    break;
            }
            temp = false;
        } else {
            switch (s[i]) {
                case '\\':
                    temp = true;
                    j--;
                    break;
                default:
                    t[j] = s[i];
            }
        }
    }

    t[j] = '\0';
    printf("s: %s\nt: %s\n",s,t);
}

void escape(char s[], char t[]) {
    /*converts characters like newline and tab into visible
     * escape sequences using a switch*/
    int i, j;

    for (i = 0, j = 0; s[i] != '\0'; i++, j++) {
        switch (s[i]) {
            case '\t':
            case '\n':
                t[j] = '\\';
                ++j;
                t[j] = (s[i] == '\t') ?'t' : 'n';
                break;
            default:
                t[j] = s[i];
                break;
        }
    }
    t[j] = '\0';
    printf("s: %s\nt: %s\n",s,t);
}

int intlen2(int v[]) {
    int i;
    for (i = 0; v[i] != '\0'; ++i);
    return i;
}

void expand(char s1[], char s2[]) {
    //write a function that expands shorthand notation like a-z, to a..z and a-b-c and a-z0-9
    

}
