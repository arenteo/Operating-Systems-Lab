#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

int numterms = 5;
double sum;

struct thread_args{
    int id_num;
    int numthr;   
    double rad;
    double result;
};

int factorial(int denom){
    int result = 1;
    for (int i=1; i<=denom; i++){
        result *= i;
    }
    return result;
}

void *sin_func(void *yarg){
    struct thread_args* args = (struct thread_args*) yarg;
    int start_term = args->id_num * numterms;
    int end_term = start_term + args->numthr;
    int i = args->id_num;
    double input = args->rad;
    int numberthr = args->numthr;
    int sign = 1;
    
    for(i=start_term; i<end_term; i+=numberthr){
        double currnum = 2*i+1;
        double term, radin = *(double*)yarg;
        double currnumd = (double) currnum;
        
        term = sign * pow(radin, currnum) / factorial(currnum);
        sum += term;
        sign *= -1;
        printf("loop number: %d",i);
    }

}

int main(int argc, char **argv){
    if (argc > 2){
        printf("Error: only two arguments needed");
        return 1;
    }
    int threadin = atof(argv[0]), radin = atof(argv[1]); //possible that args start at argv[1]
    double resultout;

    pthread_t th[threadin];
    struct thread_args thread_data[threadin];
    int i;
    for (int i=0; i < threadin; i++){
        thread_data[i].id_num = i;
        thread_data[i].rad = radin;
        thread_data[i].numthr = threadin;
        thread_data[i].result = resultout;
        if (pthread_create(&th[i], NULL, &sin_func, (void*) &thread_data[i]) != 0){
            perror("failed to create thread");
            return 1;
        }
    }
    for (int i=0; i < threadin; i++){
        if (pthread_join(th[i], NULL) != 0){
            perror("failed to join thread");
            return 1;
        }
        resultout += thread_data[i].result;
    }
    return 0;
}