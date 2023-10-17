#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAXWORD 100

int getword(char *, int);
int binsearch(char *, struct key *, int);

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

int main() {
    struct point p1 = {320, 200};
    struct point p2 = {0, 0};
    struct rect r = {p1, p2};
    struct point origin, *pp;
    pp = &origin;
    origin = makepoint(0,0);

    printf("Origin: (%d, %d)\n", pp->x, pp->y);

    printf("%d, %d\n", p1.x, p1.y);
    printf("%d, %d\n", r.pt1.x, r.pt1.y);

}
