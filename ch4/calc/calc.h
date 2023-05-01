#ifndef example_h
#define exampe_h

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define WORD '1' /* signal that a word was found */
#define VARIABLE '2' /*signal that a variable was found */
#define SETVAR '3' /*signal that a var followed by = was found*/
#define VARLENGTH 26

int getop(char s[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
//exercise 4-4 to 4-10
void ptop(void);
void pall(void);
void duplicate(void);
void swap(void);
int peek(void);
void ungets(char s[]);
int onegetch(void);
void oneungetch(int);

//home rolled functions
int isletter(char c); //0 or 1. I'm too lazy to import the bool lib tonight
int strcmp2(char s[], char t[]); //0 or 1

#endif
