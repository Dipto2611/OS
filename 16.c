#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child process running (PID: %d)\n", getpid());
        printf("Child Process exiting...\n");
        exit(0);
    }
    else
    {
        // Parent process
        printf("Parent process running (PID: %d)\n", getpid());
        printf("Parent is sleeping for 10 seconds...\n");
        sleep(10);
        printf("Parent process exiting...\n");
    }

    return 0;
}
