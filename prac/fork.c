#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

    pid_t pid = fork();
    if(pid<0){
        fprintf(stderr,"Fork failed\n");
    }

    else if(pid == 0){
        printf("Child pros: my P P id is- %d\n",getppid());
    }
    else{
        printf("P : my child is:%d\n",pid); //pid is main here no extra getpid
    }
}