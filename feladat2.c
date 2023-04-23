#include<time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*time_t T1;
    int T2, lower = -1, upper = 1, measurements;
    

    T2 = time(&T1);
    srand((unsigned) time(&T1));

    measurements = T2 % 900;

    if(measurements <= 99)
    {
        measurements = 100;
    }
    int values[measurements];
    values[0] = 0;
    for (int i = 1; i < measurements; i++)
    {
        values[i] = rand() % (upper - lower + 1) + lower;
        lower = values[i] - 1;
        upper = values[i] + 1;
    }
    for (int i = 0; i < measurements; i++)
    {
        printf("%d,", values[i]);
    }
    
    //printf("%d\n",random);
    printf("%d\n",measurements);*/
    double x = 11;
    double y = 31;
    printf("%f\n", x / y);
    return 0;
}