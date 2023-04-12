#include <stdio.h>
#include <stdbool.h>

int main() {
    /*variables to count blanks, tabs, and newlines*/
    int c, b,t,nl;
    b = t = nl = 0;
    /*replace long blanks*/
    bool blank;
    blank = false;
    while ((c = getchar()) != EOF) {
        if (c == '\b') {
            ++b;
        } else if (c == '\t') {
            ++t;
        } else if (c == '\n') {
            ++nl;
        }
        if (c == ' ') {
            if (!blank) {
                putchar(c);
            }
            blank = true;
        } else {
            blank = false;
        }
        if (!blank) putchar(c);
    }
    printf("backspace count: %d, tab count: %d, newline count: %d", b, t, nl);
    return 0;
}
