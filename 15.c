#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int turn = 0;
int flag[2] = {0, 0};

void *process0(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        flag[0] = 1;
        while (flag[1])
        {
            if (turn != 0)
            {
                flag[0] = 0;
                while (turn != 0)
                    ; // Busy wait
                flag[0] = 1;
            }
        }
        printf("Process 0 is in critical section\n");
        sleep(1);
        turn = 1;
        flag[0] = 0;
    }
    return NULL;
}

void *process1(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        flag[1] = 1;
        while (flag[0])
        {
            if (turn != 1)
            {
                flag[1] = 0;
                while (turn != 1)
                    ; // Busy wait
                flag[1] = 1;
            }
        }
        printf("Process 1 is in critical section\n");
        sleep(1);
        turn = 0;
        flag[1] = 0;
    }
    return NULL;
}

int main()
{
    pthread_t t0, t1;
    pthread_create(&t0, NULL, process0, NULL);
    pthread_create(&t1, NULL, process1, NULL);

    pthread_join(t0, NULL);
    pthread_join(t1, NULL);

    printf("Execution completed\n");
    return 0;
}
