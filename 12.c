#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_THREADS 3
#define TOTAL_THREADS 5

sem_t counting_semaphore;

void *thread_function(void *arg)
{
    int thread_id = *((int *)arg);
    printf("Thread %d is trying to enter the critical section...\n", thread_id);
    
    sem_wait(&counting_semaphore);
    printf("Thread %d has entered the critical section.\n", thread_id);
    sleep(2);
    printf("Thread %d is leaving the critical section.\n", thread_id);
    
    sem_post(&counting_semaphore);
    printf("Thread %d has exited the critical section.\n", thread_id);
    
    return NULL;
}

int main()
{
    pthread_t threads[TOTAL_THREADS];
    int thread_ids[TOTAL_THREADS];

    sem_init(&counting_semaphore, 0, MAX_THREADS);

    for (int i = 0; i < TOTAL_THREADS; i++)
    {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        sleep(1);
    }

    for (int i = 0; i < TOTAL_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&counting_semaphore);

    return 0;
}
