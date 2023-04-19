#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
int strlen2(char s[]);
int atoi2(char s[]);
void squeeze2(char s1[], char s2[]);
int htoi(char s[]); //exercise 2-3 convert hexadecimal to integer 
int pow2(int x, int y);
void shift2(char s[]);
void lower2(char from[], char to[]);

int main() {
    int len, max, temp;
    char line[MAXLINE];
    char s1[] = "stringy";
    char s2[] = "string";
    char f[] = "HELLO MOM";
    char t[MAXLINE];

    lower2(f,t);
    printf("test lower: %s to %s\n", f, t);
    printf("bitwise stuff: %d\n", 1234177 & 0177);
    /*
    while ((len = getline(line, MAXLINE)) > 0) {
        printf("len: %d line:%s", len, line);
    }
    printf("\n");
    printf("line 1234 becomes: %d\n", atoi2("1234"));
    printf("squeeze2 check:\n");

    squeeze2(s1,s2);
    printf("stringy vs string: %s\n",s1);
*/
    printf("is %d == %d\n", 4, pow2(2,2));
    printf("is %d == %d\n", 16, pow2(4,2));
    printf("is %d == %d\n", 4096, pow2(16,3));
    printf("%s -> %d\n", "3B", htoi("3B"));
    printf("%s -> %d\n", "E7A9", htoi("E7A9"));
    printf("%s -> %d\n", "400", htoi("400"));
    printf("%s -> %d\n", "0x3B", htoi("0x3B"));
    printf("%s -> %d\n", "D0", htoi("D0"));
    return 0;
}

int getline(char s[], int lim) {
    int c, i;

    for (i=0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

//return string length
int strlen2(char s[]) {
    int i = 0;

    while (s[i] != '\0')
        ++i;
    return i;
}
//converts a text string of digits to an integer value
int atoi2(char s[]) {
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

//exercise 2-4: deletes each char in s1 that matches
//any char in s2
void squeeze2(char s1[], char s2[]) {
    int i, j, k;
    bool match;

    for (i = j = 0; s1[i] != '\0'; i++) {
        match = false;
        for (k = 0; s2[k] != '\0'; k++){
            if (s1[i] == s2[k]) {match = true;
            }
        }
        if (!match) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int pow2(int x, int y) {
    int i;
    int n = 1;

    for (i = 0; i < y; ++i) {
        n *= x;
    }
    return n;
}

//convert hex into an int
int htoi(char s[]) {
    int i = 0;
    int len = 0;
    int num = 0;
    //include the optional 0x or 0X. the allowable digits are
    //0-9, a-f, and A-F

    if ((len = strlen2(s))  == 0) return 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) i = 2;

    printf("testing: %s\n", s);
    
    for (i; i < len; ++i) {
        if (s[i] >= 'a' && s[i] <= 'f') {
            num += (10 + s[i] - 'a') * pow2(16,(len - i - 1));
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            num += (10 + s[i] - 'A') * pow2(16,(len - i - 1));
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            num += (s[i] - '0') * pow2(16,(len - i - 1));
        }
        else {
            printf("invalid character: %c/n", s[i]);
            return 0;
        }
    }

    return num;
}

//convert all char to lowercase
void lower2(char from[],char to[]) {
    int i;

    for (i = 0; i < strlen2(from); ++i) to[i] = (from[i] >= 'A' && from[i] <= 'Z') ? 'a' + (from[i] - 'A') : from[i];
    to[i] = '\0';
}
