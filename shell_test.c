#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <wait.h>
#include <stdlib.h>


int main ( int argc, char *argv[]){
	pid_t pid;
	pid= fork();

	int cmd=3;	

	if(pid == -1){
		perror("fork Error");
		return 0;
	}else if (pid == 0){
		//child
		printf("child process with pid %d\n", getpid());
		//execl("/bin/ls","ls",NULL);
	}else{
		//parent
		printf("parent Pid is %d \n",getpid());
		
		wait(0);
		printf("returned to parent\n");
	}

	return 0;
}

