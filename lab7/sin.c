#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

int factorial(int denom){
    int result = 1;
    for (int i=1; i<=denom; ++i){
        result *= i;
    }
    return result;
}

int main(void){
    double term=0, total=0, radin=0, currnumd=0;
    int termsin=0, sign = 1;

    scanf("%lf%d", &radin, &termsin);
    
    for (int i=0; i<termsin; ++i){
        int currnum = 2*i+1;
        currnumd = (double) currnum;
        term = sign * pow(radin, currnumd) / factorial(currnum);
        total += term;
        sign *= -1;
        printf("sin is: %lf\n", total);
    };
}


// int main(void){
// pthread_t t1;
// pthread_create(&t1, NULL, &sin, NULL);
// pthread_join(&t1,m);
// }
