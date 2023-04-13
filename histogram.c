#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000
#define MAXWORD 25

/* histogram
 * counts word length
 * maps count into an array
 * plots a histogram of word length
 */

void hhistogram(int l[]); /*plots histogram horizontal first*/
int max(int l[], int i);
int truncate(int l[]);

int main() {
    int i, c;
    int hist[MAXWORD];
    bool word;

    /*initialize*/
    for (i = 0; i < MAXWORD; ++i) hist[i] = 0;
    word = false;

    /*reuse i*/
    i = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n'  || c == '\t' || c == '.' ||
                c == '!' || c == ',' || c == ';' || c =='?') {
            if (word) {
                if (i >= MAXWORD) ++hist[MAXWORD - 2];
                else ++hist[i-1];
                word = false;
                i = 0;
            }
            } else {
                if (!word) word = true;
                ++i;
            }
        }
    hhistogram(hist);
    return 0;
}

void hhistogram(int h[]) {
    int i, j, imax, trun;
    i = j = 0;
    imax = max(h, MAXWORD);
    trun = truncate(h);

    printf("word length histogram:\n");
    /*print horizontal histogram*/
    for (i = imax; i > 0; --i) {
        for (j = 0; j < trun; ++j) {
            if (h[j] >= i) printf("  X");
            else printf("%3s", " ");
        }
        printf("\n");
    }
    for (i = 0; i < trun; ++i) {
        printf("%3d", h[i]);
    }
    printf("\n");
    for (i = 0; i < trun; ++i) {
        printf("%3s", "-");
    }
    printf("\n");
    for (i = 0; i < trun; ++i) {
        printf("%3d", i+1);
    }

    /*communicate there were words exceeding MAXWORD length*/
    if (h[MAXWORD-2] != 0) printf("+");
    printf("\n");
}

int truncate(int h[]) {
    int i, m;
    m = 0;
    for (i=0; i < MAXWORD; ++i)
        if (h[i] != 0) m = i;
    return m + 1;
}

int max(int h[], int lim) {
    int i, c, imax;

    imax = 0;
    for (i = 0; i < lim; ++i) {
        if (imax < h[i]) imax = h[i];
    }

    return imax;
}
