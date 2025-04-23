#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t frk[5];
void *philos(void *);
void eat(int);
int main()
{
    int i, n[5];
    pthread_t T[5];
    for (i = 0; i < 5; i++)
        sem_init(&frk[i], 0, 1);
    for (i = 0; i < 5; i++)
    {
        n[i] = i;
        pthread_create(&T[i], NULL, philos, (void *)&n[i]);
    }
    for (i = 0; i < 5; i++)
        pthread_join(T[i], NULL);
    return 0;
}
void *philos(void *n)
{
    int ph = *(int *)n;
    printf("Philosopher %d is thinking\n", ph);
    sleep(1);
    printf("Philosopher %d wants to eat\n", ph);
    printf("Philosopher %d tries to pick left Fork\n", ph);
    sem_wait(&frk[ph]);
    printf("Philosopher %d picks the left Fork\n", ph);
    printf("Philosopher %d tries to pick the right Fork\n", ph);
    sem_wait(&frk[(ph + 1) % 5]);
    printf("Philosopher %d picks the right Fork\n", ph);
    sleep(2);
    eat(ph);
    printf("Philosopher %d has finished eating\n", ph);
    sem_post(&frk[(ph + 1) % 5]);
    printf("Philosopher %d leaves the right Fork\n", ph);
    sem_post(&frk[ph]);
    printf("Philosopher %d leaves the left Fork\n", ph);
    printf("Philosopher %d is thinking\n", ph);
}
void eat(int ph)
{
    printf("Philosopher %d begins to eat\n", ph);
}