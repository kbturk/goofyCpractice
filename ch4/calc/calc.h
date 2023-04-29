#ifndef example_h
#define exampe_h

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define WORD '1' /* signal that a word was found */
#define MAXVAL 100
#define BUFSIZE 100

int getop(char s[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
//exercise 4-4
void ptop(void);
void duplicate(void);
void swap(void);

//home rolled functions
int isletter(char c); //0 or 1. I'm too lazy to import the bool lib tonight
int strcmp2(char s[], char t[]); //0 or 1

#endif
