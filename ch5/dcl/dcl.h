#ifndef dcl_
#define dcl_

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

void dcl(void);
void dirdcl(void);

enum { NAME, PARENS, BRACKETS };

int gettoken(void);
int tokentype; //type of last token
char token[MAXTOKEN]; //last token string
char name[MAXTOKEN]; //identifier name
char datatype[MAXTOKEN]; //data type = char, int etc
char out[1000]; //output string


#endif
