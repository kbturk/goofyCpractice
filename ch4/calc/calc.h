#ifndef example_h
#define exampe_h

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100
#define BUFSIZE 100

int getop(char s[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

#endif
