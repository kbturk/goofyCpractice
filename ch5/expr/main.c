#include <stdio.h>
#include <stdlib.h> //for atof()
#include <string.h> //maybe remove, tbd.
#include <ctype.h> //for getop, getch and ungetch

#define MAXOP 100
#define MAXVAL 100 //max depth of push/pop stack
#define NUMBER '0' //signal that a number was found

int getop(char *argv, char *s);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0; //next free stack position
double val[MAXVAL];

//reverse polish calc with command line pointers
int main(int argc, char *argv[]) {
    int type;
    double op2;
    char s[MAXVAL];

    printf("commandline reverse Polish Calculator!\n");
    while (--argc > 0) {
        ++argv;
        printf("argc: %d, argv is %s\n",argc, *argv);

        type = getop(*argv, s);

        printf("after getop: %s vs %s\n",*argv, s);
        switch (type) {
            case NUMBER:
                push(atof(*argv));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop()/op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", *argv);
                break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}

void push(double f) {
    if (sp < MAXVAL) //there's room on the stack.
        val[sp++] = f; //push on the stack.
    else 
        printf("error: stack is full, can't push %g\n", f);
    return;
}

double pop(void) {
    if (sp > 0) //there's something on the stack.
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

//getop :get the next operator or numeric operand
int getop(char *string, char *s)
{
    int c, l;
    char *start;

    start = string;
    l = strlen(string);

    if (l <= 0)
        printf("ERROR: Problem in strlen: %d\n", l);
    else printf("%s is %d long\n",string, l);

    *s++ = c = *string++;

    //this handles doubles instead of ints
    if (!isdigit(c) && c != '.')
        return c; //not a number

    //collect number
    if (isdigit(c))
        while(isdigit(*s++ = c = *string++) && string - start < l)
            ;
    if (c == '.')
        while(isdigit(*s++ = c = *string++) && string - start < l)
            ;
    *s = '\0';
    printf("s is %s\n",s);
    return NUMBER;
}
