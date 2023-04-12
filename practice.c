#include <stdio.h>

int main() {
    int c;
    c = getchar();
    while (c !=EOF) {
        putchar(c);
        c = getchar();
    }
    printf("end of line value: %i\n",c);

    return 0;
}
