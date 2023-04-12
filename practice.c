#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    int fahr, celsius;
    printf("fahr to cel\n\n");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32.0));
    printf("\n\n");
    printf("cel to fahr\n\n");
    for (celsius = LOWER; celsius <= UPPER; celsius = celsius + STEP)
        printf("%3d %6.1f\n", celsius, (9.0/5.0)*(celsius + 32));
    return 0;
}
