#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

void *sin (void *arg);
int factorial (int denom);

typedef struct {
    double rad;
    int terms;
} ThreadArgs;

int i=0, sign = 1;
int termsin = 0;
long double radin, *sum;
sum = malloc(sizeof(long double) * termsin);

int main(int termsin, double radin){
    pthread_t th[termsin];
    ThreadArgs args = {radin, termsin};

    for (int i=0; i < termsin; i++){
        if (pthread_create(&th[i], NULL, &sin, (void*) &args) != 0){
            perror("failed to create thread");
        }
    }

    for (int i=0; i < termsin; i++){
        if (pthread_join(th[i], NULL) != 0){
            perror("failed to join thread");
        }
    }

}

int factorial(int denom){
    int result = 1;
    for (int i=1; i<=denom; i++){
        result *= i;
    }
    return result;
}

void *sin(void *arg){
    ThreadArgs* args = (ThreadArgs*) arg;
    
    int currnum = 2*i+1;
    i++;
    double term, radin = *(double*)arg;
    double currnumd = (double) currnum;
    
    term = sign * pow(radin, currnum) / factorial(currnum);
    sum += term;
    sign *= -1;
}
