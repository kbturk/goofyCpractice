#include <stdio.h>

//Date conversions from Ch5 exercises

int day_of_year(int y, int m, int d);
void month_day(int y, int yd, int *pm, int *pd);
char *month_name(int n);

static char daytab[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int main() {
    //var exercise 5-8
    int t1 = 0, t2 = 0;
    int *pm;
    int *pd;
    pm = &t1;
    pd = &t2;

    //test functions for date conversions exercise 5-8
    printf("day of year for: %d %d %d: %d\n", 3, 17, 2023, day_of_year(2023, 3, 17));
    printf("day of year for: %d %d %d: %d\n", 3, 17, 2024, day_of_year(2024, 3, 17));
    printf("day of year for: %d %d %d: %d\n", 3, -17, 2023, day_of_year(2023, 3, -17));
    printf("day of year for: %d %d %d: %d\n", 42, 17, 2024, day_of_year(2024, 42, 17));
    printf("day of year for: %d %d %d: %d\n", 4, 31, 2024, day_of_year(2024, 4, 31));

    month_day(2024, 221, pm, pd);
    printf("month and day for: %d, %d: %d/%d\n", 221, 2024, *pm, *pd);
    month_day(2023, 221, pm, pd);
    printf("month and day for: %d, %d: %d/%d\n", 221, 2023, *pm, *pd);

    //month_name - static char pointer array
    printf("%s\n", month_name(5));
    printf("%s\n", month_name(10));
    printf("%s\n", month_name(17));
}

//set day of year from month & day
int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    //error checking
    if (month < 1 || month > 12)  {
        printf("Error: %d month outside bounds\n",month);
        return 0;
    } else if (day < 1 || day > daytab[leap][month]) {
        printf("Error: %d day outside bounds\n",day);
        return 0;
    }

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

//set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    //error checking
    if (yearday < 1 ) {
        printf("Error: %d yearday outside bounds",yearday);
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

char *month_name(int n) {
    static char *name[] = {
        "Illegal Month",
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep",
        "Oct",
        "Nov",
        "Dec"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}
