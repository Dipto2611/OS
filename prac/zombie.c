#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid = fork();

    if(pid<0){
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0) {
        printf("Child (PID %d) exiting...\n", getpid());
        exit(0);
    } else {
        printf("Parent (PID %d) sleeping...\n", getpid());
        sleep(5);  // Child becomes zombie here
    }

    return 0;
}
