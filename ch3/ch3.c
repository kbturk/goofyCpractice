#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "example.h"

#define MAXLINE 1000

int main() {
    int v[] = {0,1,2,3,4,5,6,7,8,9,10};
    int n, bs1, bs2;
    char t2[MAXLINE];
    char t[MAXLINE];

    //exercise 3-1
    //TODO: get the clock function to actually work & ask
    //Derrick if there's a better way to profile 
    //this function
    printf("\n---exercise 3-1---\n");
    n = 11;
    printf("%d\n", n);
    clock_t begin = clock();
    bs1 = binsearch(1,v,n);
    clock_t end1 = clock();
    bs2 = binsearch2(1,v,n);
    clock_t end2 = clock();
    double time_spent = (double)(end1 - begin);
    double time_spent2 = (double)(end2 - end1);
    printf("bs1: %d - %d vs bs2: %d - %d\n",
            bs1, time_spent,
            bs2, time_spent2);

    printf("\n---exercise 3-2---\n");
    escape("\t\t\tMOM!!!!!\n RUN!",t);
    trap("\\t\\t\\tMOM!!!!\\n STOP!", t2);
    return 0;
}
