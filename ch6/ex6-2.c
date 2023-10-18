#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXWORD 100
#define BUFSIZE 100

struct tnode {
    char *word;
    int count;
    //struct strlist;
    struct tnode *left;
    struct tnode *right;
};

struct strlist {
    char *word;
    struct strlist *left;
    struct strlist *right;
};

struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);
char *l_strdup(char *);

void treeprint(struct tnode *);
int getword(char *, int);
int compare_all(char *);
int getvar(char *, int);
int getch(void);
void ungetch(int);

/* just typing out loud...
 * capture variables when they're declared
 * group by top 6 or w/e similar items
 * so the struct should include a char limited to 6 chars
 * and then also have another sorted tree
 */

// count C keywords
int main() {
    char word[MAXWORD], prev[MAXWORD];
    struct tnode *root;
    int w, next;

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
    {
        //check variables when they're declared
        printf("I made it this far: %s\n", word);

        //there's got to be a better way to do this
        if (strcmp(word, "define") == 0)
        {
            if (getword(word, MAXWORD) != EOF && word[0] != '"'
                    && word[0] != '\'')
            {
                printf("adding: %s\n", word);
                root = addtree(root, word);
            }
        }
        else if (strcmp(word, "int") == 0 ||
                strcmp(word, "struct") == 0 ||
                strcmp(word, "char") == 0 ||
                strcmp(word, "string") == 0 ||
                strcmp(word, "float") == 0 ||
                strcmp(word, "void") == 0
                )
        {
            getword(word, MAXWORD);
            while (word[0] != EOF)
            {
                printf("analyzing: %s\n", word);
                strcpy(prev, word);
                next = getword(word, MAXWORD);
                if (next == ';' ||
                        next == '{' ||
                        next == ',' ||
                        next == '[') {
                    printf("next was: %c, adding: %s\n", next, prev);
                    root = addtree(root, prev);
                    break;
                }
                else if (next == '(' ||
                        next == '>' ||
                        next == '<' ||
                        next == ')' ||
                        next == '"' ||
                        next == '(' ||
                        next == '\'')
                {
                    break;
                }
            }
        }
    }
    treeprint(root);
    return 0;
}

int compare_all(char *w)
{
    printf("analyzing: %s\n", w);

    /*
       printf("%d\n", strcmp(w, "int") == 0);
       printf("%d\n", strcmp(w, "struct") == 0);
       printf("%d\n", strcmp(w, "char") == 0);
       printf("%d\n", strcmp(w, "string") == 0);
       printf("%d\n", strcmp(w, "float") == 0);
       printf("%d\n", strcmp(w, "void") == 0);
       */
    int temp = (strcmp(w, "int") == 0 ||
            strcmp(w, "struct") == 0 ||
            strcmp(w, "char") == 0 ||
            strcmp(w, "string") == 0 ||
            strcmp(w, "float") == 0 ||
            strcmp(w, "void") == 0
            );
    printf("overall: %d\n", temp);
    return temp;
}

//addtree: add a node with w at or below p. if there's a match, advance count
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = l_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++; //match found
    else if (cond < 0) // less than into left subtree
        p->left = addtree(p->left, w);
    else // greater than into right subtree
        p->right = addtree(p->right, w);
    return p;
}

//treeprint: in-order print of tree p
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

//tallac: make a tnode
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

//l_strdup: make a duplicate of s
char *l_strdup(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s) + 1); //1 for '\0'
    if (p != NULL)
        strcpy(p, s);
    return p;
}

// getword: get the next word
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;


    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;

    if (!isalnum(c)) {
        //skip comments
        if (c == '/')
        {
            if ((c = getchar()) == '/')
            {
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
                return c;
            }
            else if (c == '*')
            {
                while (true)
                    if ((c = getchar()) == '*' || c == EOF)
                        if ((c = getchar()) == '/' || c == EOF)
                            return c;
            }
        }
        *w = '\0';
        return c;
    }

    for ( ; --lim > 0; w++)
    {
        if (!isalnum(*w = getch()) && *w != '#')
        {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];

}

static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /*push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: exceeded BUFSIZE\n");
    else
        buf[bufp++] = c;
}
