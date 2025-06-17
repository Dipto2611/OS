#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_ALLOWED 2  // Max threads in critical section at a time
#define TOTAL_THREADS 4

sem_t counting_sem;

void* thread_func(void* arg) {
    int id = *(int*)arg;

    printf("Thread %d wants to enter...\n", id);
    sem_wait(&counting_sem);  // Wait for permission
    printf("Thread %d is in critical section.\n", id);
    sleep(2);
    printf("Thread %d is leaving section.\n", id);
    sem_post(&counting_sem);  // Signal exit
    return NULL;
}

int main() {
    pthread_t threads[TOTAL_THREADS];
    int ids[TOTAL_THREADS];

    sem_init(&counting_sem, 0, MAX_ALLOWED);  // Initialize semaphore with count

    for (int i = 0; i < TOTAL_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_func, &ids[i]);
        sleep(1);  // Slight delay to see output clearly
    }

    for (int i = 0; i < TOTAL_THREADS; i++)
        pthread_join(threads[i], NULL);

    sem_destroy(&counting_sem);
    return 0;
}
