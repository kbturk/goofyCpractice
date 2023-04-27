#include <stdio.h>
#include "ch4fun.h"

#define MAXLINE 1000

char pattern[] = "Helena";

int main() {
    char line[MAXLINE];
    int found = 0;
    
    printf("\n---ch 4 book example 1---\n");
    printf("searching for...%s\n", pattern);

    while (getline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            found++;
            printf("%d: %s", found, line);
        }

    printf("found: %d matches", found);

    printf("\n---ch 4 book with my homebrewed fun---\n");

    //printf("found %d matches", getmatch(pattern));

    return 0;
}
