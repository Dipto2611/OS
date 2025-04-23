#include<stdio.h>
#include<unistd.h>
#include<sys/types.h> 

int main(){
	pid_t pid = fork();
	if(pid < 0)
		fprintf(stderr, "Fork Failed\n");
	else if(pid == 0){
		printf("child process: My parent process is %d\n", getppid());
	}
	else{
		printf("parent process: my child is %d\n", pid);
	}
    return 0;
}
