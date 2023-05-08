#include <stdio.h>
#include <string.h>
#define MAXSTRING 1000

#define SWAP(t,x,y) { t temp; \
    temp = x; x = y; y = temp;}

static int i = 0; /*keep track of next position in s*/

void itoa(int, char s[]); /*use recursion to map an int to a string*/
void reverse(char s[], int, int);
void swap(char s[], int, int);

int main() {
    int num = 1234567;
    char s[MAXSTRING];

    itoa(num, s);
    printf("itoa recursive test: %d vs %s\n", num, s);

    i = 0;
    itoa(-num,s);
    printf("itoa recursive test: %d vs %s\n", -num, s);
    reverse(s, 0, strlen(s) - 1);
    printf("reverse test: %s\n", s);
    reverse(s, 0, strlen(s) - 1);
    printf("reverse test: %s\n", s);

    char l = 'l';
    char r = 'r';

    SWAP(char, l, r);
    printf("%c, %c\n", l, r);
    SWAP(char, l, r);
    printf("%c, %c\n", l, r);
    return 0;
}

//a recursive function that changes an int to a string
void itoa(int n, char s[]) {
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }

    if (n / 10)
        itoa(n/10, s);
    s[i++] = n % 10 + '0';
    s[i] = '\0';
    //printf("i is: %d, added: %c, s is now: %s\n",i,n % 10 + '0', s);
}

//a helper function for reverse
void swap(char s[], int i, int j) {
    int temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

//a recursive function which reverses a string
//note: there's no real error checking
void reverse(char s[], int left, int right) {
    int i, last;
    //do nothing if s is empty,
    //array contains fewer than 2 elements
    //or left or right are less than 0
    if (s[left] == '\0' ||
            left >= right ||
            left < 0 ||
            right < 0)
        return;

    reverse(s, left + 1, right - 1);
    swap(s, left, right);
    //printf("swapped s[%d] and s[%d], s is now: %s\n", left, right, s);
}
