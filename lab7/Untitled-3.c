#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

int numterms = 7;

struct thread_args {
    int id_num;
    int numthr;
    long double rad;
    long double result;
    int sign;
};

int factorial(int denom) {
    int result = 1;
    for (int i = 1; i <= denom; i++) {
        result *= i;
    }
    return result;
}

void *sin_func(void *yarg) {
    struct thread_args* args = (struct thread_args*) yarg;
    int starttrm = args->id_num;
    int sign = args->sign;
    long double radin = args->rad, term;

    for (int i = starttrm; i < numterms; i+= args->numthr) {
        long double currnum = 2*i+1;
        term = sign * pow(radin, currnum) / factorial(currnum);
        args->result += term;
        printf("thread %d processed term %d\n", args->id_num, i);
        //printf("\n>>>>result = %0.18Lf\n", args->result);
    }

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Error: two arguments needed\n");
        return 1;
    }
    int threadin = atoi(argv[1]);
    double radin = atof(argv[2]);
    long double resultout = 0.0;

    pthread_t th[threadin];
    struct thread_args thread_data[threadin];
    for (int i = 0; i < threadin; i++) {
        thread_data[i].id_num = i;
        thread_data[i].rad = radin;
        thread_data[i].numthr = threadin;
        thread_data[i].result = 0.0;
        if (i % 2 == 0){
            thread_data[i].sign = 1;
        }else{
            thread_data[i].sign = -1;
        }


        if (pthread_create(&th[i], NULL, &sin_func, (void*) &thread_data[i]) != 0) {
            perror("failed to create thread");
            return 1;
        }

        if (pthread_join(th[i], NULL) != 0) {
            perror("failed to join thread");
            return 1;
        }
    // for (int i = 0; i < threadin; i++) {
    //     }
        resultout += thread_data[i].result;
    }
    printf("\nsin = %0.18Lf", resultout);
}