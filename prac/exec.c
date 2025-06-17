#include <stdio.h>
#include <unistd.h>   // for fork(), execl()
#include <sys/wait.h> // for wait()

int main() {
    int pid = fork();  // create child process

    if (pid == 0) {
       
        printf("Child: running 'ls -l'\n");
        execl("/bin/ls", "ls", "-l", NULL);
        printf("Exec failed\n");
    } else {
        
        wait(NULL);
        printf("Parent: child finished.\n");
    }

    return 0;
}
