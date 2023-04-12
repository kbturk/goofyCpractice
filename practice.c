#include <stdio.h>

int main() {
    /*variables to count blanks, tabs, and newlines*/
    int c, b,t,nl;
    b = t = nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\b') {
            ++b;
        } else if (c == '\t') {
            ++t;
        } else if (c == '\n') {
            ++nl;
        }
    }
    printf("backspace count: %d, tab count: %d, newline count: %d", b, t, nl);
    return 0;
}
