#include <stdio.h>
#include <time.h>

int binsearch(int x,  int v[], int n);
int binsearch2(int x, int v[], int n);
int intlen2(int s[]);

int main() {
    int v[] = {0,1,2,3,4,5,6,7,8,9,10};
    int n, bs1, bs2;

    //exercise 3-1
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

    return 0;
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
