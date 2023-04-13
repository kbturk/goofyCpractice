#include <stdio.h>
#include <limits.h>
#include <float.h>


/*determine the ranges of char, short, int, and long unsigned and signed by printing appropriate values from
 * standard headers and by direct computation.*/
int main() {
    //char
    printf("min char: %d\n", CHAR_MIN);
    printf("max char: %d\n", CHAR_MAX);
    //short
    printf("min short: %d\n", SHRT_MIN);
    printf("max shrt: %d\n", SHRT_MAX);
    //int
    printf("min int: %d\n", INT_MIN);
    printf("max int: %d\n", INT_MAX);
    printf("max uint:%u\n", UINT_MAX);

    return 0;
}
