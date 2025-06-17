#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void* run(void* arg) {
    int id = *(int*)arg;

    printf("Thread %d wants to enter...\n", id);
    sem_wait(&sem);
    printf("Thread %d in critical section\n", id);
    sleep(2);
    printf("Thread %d leaving...\n", id);
    sem_post(&sem);
    return NULL;
}

int main() {
    pthread_t t[3];
    int ids[3] = {1, 2, 3};

    sem_init(&sem, 0, 1);

    for (int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, run, &ids[i]);

    for (int i = 0; i < 3; i++)
        pthread_join(t[i], NULL);

    sem_destroy(&sem);
    return 0;
}
