#include <stdio.h>

int main() {
    long nc, nl, c;
    nc = 0;
    nl = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
    }
    printf("program char: %ld newline chars: %ld\n", nc, nl);
    return 0;
}
