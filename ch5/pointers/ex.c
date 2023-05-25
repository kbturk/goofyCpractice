#include <stdio.h>

#define SIZE 100
void strcat2(char *s, char *t) {
    while(*s)
        s++;
    while(*s++ = *t++)
        ;
}

int main() {

    char s[SIZE] = "hi ";
    char t[SIZE] = "MOM";

    printf("%s\n",s);
    strcat2(s,t);
    printf("%s",s);
    return 0;
}
