#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *compute(void *ptr);

int main(int argc, char *argv[]) {
    //Abort and print error message if argc is 1
    if (argc == 1) {
        fprintf(stderr, "Error\n");
        exit(1);
    }
    
    pthread_t* arr = malloc(sizeof(pthread_t)*(argc-1));

    //Dynamically create pthread
    for (int i = 1; i < argc; i++) {
        pthread_create(&arr[i], NULL, compute, (void*) i);     
    }

    for (int i = 1; i < argc; i++) {
        pthread_join(arr[i], NULL);
    }

    for (int i = 0; i < argc - 1; i++) {
        printf("arr[%d](old) has been replaced with arr[%d](new)\n", i, i);
    }
    
    free(arr);
    free(threads);
    return 0;
}

void *compute(void *ptr){

    return NULL;
}