#include <stdio.h>
#include <stdlib.h>

int zhangyu_flag = 0;

int main()
{
    double f = 1.5;
    unsigned long long temp = 0;

    memcpy(&temp, &f, sizeof(temp));
    printf("temp=%016llX\n", temp);
    printf("temp=%llX\n", temp);
    printf("temp=%lX\n", temp);
    printf("temp=%X\n", temp);
    printf("temp=%ld\n", sizeof(temp));
    printf("sizeof(int)=%ld\n", sizeof(int));
    printf("sizeof(float)=%ld\n", sizeof(float));
    printf("sizeof(long)=%ld\n", sizeof(long));
    printf("sizeof(long long)=%ld\n", sizeof(long long));
    

    return 0;
}

