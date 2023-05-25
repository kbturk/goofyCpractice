#define ALLOCSIZE 1000
#include "arrayallo.h"
#include <stdio.h>

static char allocbuf[ALLOCSIZE]; //storage for alloc
static char *allocp = allocbuf; //next free position

char *alloc(int n) //return pointer to n characters
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { //it fits
        allocp += n;
        return allocp - n; /*old p*/
    } else /*not enough room */
        return NULL;
}

void afree(char *p) //free storage pointed to by p
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
