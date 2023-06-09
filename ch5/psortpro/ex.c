#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sort lines numerically or alphabetically
#define MAXLINES 50000 //max lines to be sorted
#define MAXLEN 10000 //max length of any input line

int getline(char *, int);
char *alloc(int); //return pointer to n characters

char *lineptr[MAXLINES]; //pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int numeric);

void qsort2(void *lineptr[], int left, int right,
        int (*comp)(void *, void *));
void swap(void *v[], int i, int j);

int numcmp(char *, char *);
int strcmp2(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines; //number of linput lines read
    int numeric = 0; //1 if numeric sort

    if (argc > 1 && strcmp2(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort2((void **) lineptr, 0, nlines-1,
                (int (*)(void*, void*))(numeric ? numcmp : strcmp2));
        writelines(lineptr, nlines, numeric);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}


//read input
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            if (p == NULL)
                printf("Danger on line %d",nlines);
            return -1;
        }
        else {
            line[len-1] = '\0';//replace newline with \0
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

//write output lines
void writelines(char *lineptr[], int nlines, int numeric) {
    while (nlines-- > 0) {
    //    if (numeric)
    //        printf("%d: %s\n",atof(*lineptr),*lineptr++);
    //    else
        printf("%s\n", *lineptr++);
    }
}

void qsort2(void *v[], int left, int right,
        int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int i, int j);

    if (left >=right) //do nothing if an array contains
        return;       //fewer than two elements
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort2(v, left, last -1, comp);
    qsort2(v, last+1, right, comp);
}

/*numcmp: compare s1 and s2 numerically*/
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    printf("v1: %f, s1: %s\n", v1, s1);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

//strcmp2: return <0 if s<t, 0 if s==t, >0 if s>t
int strcmp2(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

void swap(void *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

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

#define ALLOCSIZE 100000
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

