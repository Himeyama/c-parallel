/*
 *  (c) 2021 Murata Mitsuharu
 *  Licensed under the MIT License.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct{
    int a;
    int b;
    int r;
} ThreadVar;

void* func(ThreadVar* tv){
    tv->r = tv->a + tv->b;
    sleep(tv->r);
}

int main(void){
    pthread_t thread[2];
    
    ThreadVar tv1 = {3, 2, -1};
    ThreadVar tv2 = {5, 3, -1};

    if(pthread_create(thread, NULL, (void*)func, (void*)&tv1))
        exit(EXIT_FAILURE);
    if(pthread_create(thread+1, NULL, (void*)func, (void*)&tv2))
        exit(EXIT_FAILURE);
    

    if(pthread_join(thread[0], NULL))
        exit(EXIT_FAILURE);
    if(pthread_join(thread[1], NULL))
        exit(EXIT_FAILURE);
    
    printf("1番目の答え: %d + %d = %d\n", tv1.a, tv1.b, tv1.r);
    printf("2番目の答え: %d + %d = %d\n", tv2.a, tv2.b, tv2.r);
    

    return 0;
}