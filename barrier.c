#include "my_barrier.h"
#include <pthread.h>
#include <stdio.h>

#define TOTAL_THREADS 5

my_barrier barrier;

unsigned int pthread_my_barrier_init(my_barrier *mb, unsigned int v){
    if (v == 0)
        return -1;
    mb->vinit = v;
    pthread_mutex_init(&mb->lock, NULL);
    mb->val = 0;
    pthread_cond_init(&mb->varcond, NULL);

    return 0;
}

unsigned int pthread_my_barrier_wait(my_barrier *mb){
    pthread_mutex_lock(&mb->lock);

    mb->val++;

    if (mb->val < mb->vinit) {
        pthread_cond_wait(&mb->varcond, &mb->lock);
    } else {
        pthread_cond_broadcast(&mb->varcond);
    }

    pthread_mutex_unlock(&mb->lock);

    return 0;
}

void *thread_func(void *ptr){
    printf("thread id %ld is waiting at the barrier, as not enough threads are running ...\n", (unsigned long)pthread_self());
    pthread_my_barrier_wait(&barrier);
    printf("The barrier is lifted, thread id %lu is running now\n", (unsigned long)pthread_self());

    return NULL;
}

int main()
{  
	pthread_t thread_id[TOTAL_THREADS];

    pthread_my_barrier_init(&barrier, TOTAL_THREADS);
    for (int i = 0; i < TOTAL_THREADS; i++){
        pthread_create(&thread_id[i], NULL, thread_func, NULL);
    }

    // As pthread_join() will block the process until all the threads it specified are finished, 
    // and there is not enough thread to wait at the barrier, so this process is blocked
    for (int i = 0; i < TOTAL_THREADS; i++){
        pthread_join(thread_id[i], NULL);
    }

    printf("Thread barrier is lifted\n"); // This line won't be called as TOTAL_THREADS < THREAD_BARRIERS_NUMBER
}