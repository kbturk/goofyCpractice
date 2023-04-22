#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define MAXLINE 1000

int binsearch(int x,  int v[], int n);
int binsearch2(int x, int v[], int n);
int intlen2(int s[]);
void escape(char s[], char t[]);//exercise 3-2
void trap(char s[], char t[]);//exercise 3-2

int main() {
    int v[] = {0,1,2,3,4,5,6,7,8,9,10};
    int n, bs1, bs2;
    char t2[MAXLINE];
    char t[MAXLINE];

    //exercise 3-1
    //TODO: get the clock function to actually work & ask
    //Derrick if there's a better way to profile this function
    printf("\n---exercise 3-1---\n");
    n = 11;
    printf("%d\n", n);
    clock_t begin = clock();
    bs1 = binsearch(1,v,n);
    clock_t end1 = clock();
    bs2 = binsearch2(1,v,n);
    clock_t end2 = clock();
    double time_spent = (double)(end1 - begin);
    double time_spent2 = (double)(end2 - end1);
    printf("bs1: %d - %d vs bs2: %d - %d\n",
            bs1, time_spent,
            bs2, time_spent2);

    printf("\n---exercise 3-2---\n");
    escape("\t\t\tMOM!!!!!\n RUN!",t);
    trap("\\t\\t\\tMOM!!!!\\n STOP!", t2);
    return 0;
}

void trap(char s[], char t[]) {
    int i, j;
    bool temp;
    temp = false;

    for (i = 0, j = 0; s[i] != '\0'; i++, j++) {
        if (temp) {
            switch (s[i]) {
                case 'n':
                case 't':
                    t[j] = (s[i] == 't') ? '\t' : '\n';
                    break;
                default:
                    break;
            }
            temp = false;
        } else {
            switch (s[i]) {
                case '\\':
                    temp = true;
                    j--;
                    break;
                default:
                    t[j] = s[i];
            }
        }
    }

    t[j] = '\0';
    printf("s: %s\nt: %s\n",s,t);
}

void escape(char s[], char t[]) {
    /*converts characters like newline and tab into visible
     * escape sequences using a switch*/
    int i, j;

    for (i = 0, j = 0; s[i] != '\0'; i++, j++) {
        switch (s[i]) {
            case '\t':
            case '\n':
                t[j] = '\\';
                ++j;
                t[j] = (s[i] == '\t') ?'t' : 'n';
                break;
            default:
                t[j] = s[i];
                break;
        }
    }
    t[j] = '\0';
    printf("s: %s\nt: %s\n",s,t);
}

int intlen2(int v[]) {
    int i;
    for (i = 0; v[i] != '\0'; ++i);
    return i;
}

//exercise 3-1
int binsearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high && x != v[mid]) {
        mid = (low+high)/2;
        if (x < v[mid]) 
            high = mid - 1;
        else low = mid + 1;
    }

    if (x == v[mid])
        return v[mid];
    else return -1;
}

//book example
int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <=high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
