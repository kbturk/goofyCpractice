#include <stdio.h>
#include <stdbool.h>

int main() {
    /*variables to count blanks, tabs, and newlines*/
    int c, b,t,nl;
    b = t = nl = 0;
    /*replace long blanks*/
    bool written;
    written = false;
    /*replace tab with \t, backspace by \b, and backslash by \\*/

    while ((c = getchar()) != EOF) {
        if (c == '\b') {
            ++b;
            printf("\\b");
            written = true;
        } else if (c == '\t') {
            ++t;
            printf("\\t");
            written = true;
        } else if (c == '\n') {
            ++nl;
        } else if (c == '\\') {
            printf("\\\\");
            written = true;
        } else if (c == ' ') {
            if (!written) {
                putchar(c);
            }
            written = true;
        } else {
            written = false;
        }
        if (!written) putchar(c);
    }
    printf("backspace count: %d, tab count: %d, newline count: %d", b, t, nl);
    return 0;
}
