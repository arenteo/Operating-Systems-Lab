#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *run(void *ptr);

int main(int argc, char *argv[]) {
    //Abort and print error message if argc is 1
    if (argc == 1) {
        fprintf(stderr, "Error\n");
        exit(1);
    }

    int *arr = malloc((argc - 1) * sizeof(int));
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }
    
    pthread_t *threads = malloc((argc - 1) * sizeof(pthread_t));
    for (int i = 0; i < argc - 1; i++) {
        int index = i;
        pthread_create(&threads[i], NULL, run, &index);
    }
    
    for (int i = 0; i < argc - 1; i++) {
        pthread_join(threads[i], NULL);
    }
    
    for (int i = 0; i < argc - 1; i++) {
        printf("arr[%d](old) has been replaced with arr[%d](new)\n", i, i);
    }
    
    free(arr);
    free(threads);
    return 0;
}

void *run(void *ptr) {
    int index = *((int*) ptr);
    int value = *((int*) ptr + 1);
    
    if (index % 2 == 0) {
        value = value * value * value;
    } else {
        value = -value;
    }
    
    *((int*) ptr + 1) = value;
    
    return NULL;
}