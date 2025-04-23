#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#define NUM_ITERATIONS 3

bool flag[2] = {false, false};
int turn = 0;

void* process0(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        flag[0] = true;
        turn = 1;

        while (flag[1] && turn == 1);

        printf("Process 0 is in the Critical Section\n");
        sleep(1);

        flag[0] = false;
        printf("Process 0 is leaving the Critical Section\n");

        sleep(1);
    }

    return NULL;
}

void* process1(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        flag[1] = true;
        turn = 0;

        while (flag[0] && turn == 0);

        printf("Process 1 is in the Critical Section\n");
        sleep(1);

        flag[1] = false;
        printf("Process 1 is leaving the Critical Section\n");

        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t t0, t1;

    pthread_create(&t0, NULL, process0, NULL);
    pthread_create(&t1, NULL, process1, NULL);

    pthread_join(t0, NULL);
    pthread_join(t1, NULL);

    printf("Execution Completed Successfully!\n");

    return 0;
}