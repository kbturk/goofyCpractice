#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

static int sp = 0; /* next free stack position */
static double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
        //printf("pushed %g to stack\n", f);
    }
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        //printf("popped %g, sp is now %d from stack\n", val[sp-1], sp-1);
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

//print the top item on the stack
void ptop() {
    printf("%g\n", val[sp - 1]);
    return;
}

//print the whole stack
void pall() {
    int i;
    for (i = sp - 1; i >= 0; --i)
        printf("%g,", val[i]);
    printf("\n");
}

//duplicate the top item on the stack
void duplicate() {
    double temp;
    temp = val[sp - 1];
    push(temp);
    printf("duplicated: %g, %g\n", val[sp - 1], val[sp - 2]);
    return;
}

//swap the top two elements on the stack
void swap() {
    int t1, t2;
    t1 = pop();
    t2 = pop();
    push(t1);
    push(t2);
    printf("swapped: %g, %g\n", val[sp - 1], val[sp - 2]);
}
