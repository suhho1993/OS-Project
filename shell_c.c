#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>


void print_menu(void){
	printf("This is simple shell program by Suhho\n");
	printf("Type in what you want to start\n ");

}
void startcmd(char *cmd,char* tokcmd){

	char *tcmd;
	char *cmdop;

	tcmd=strtok(cmd," ");
	cmdop=strtok(NULL," ");

	char *mpath=getenv("PATH");
	char *tokpath;

	tokpath=strtok(mpath,":");
	while(tokpath=(NULL,"PATH"));
	printf("%s \n",tokpath);
	}
}

	

int main(){
	char *cmd;
	char *tokcmd;

	char *mpath=getenv("PATH");
	char *tokpath;

	print_menu();
	
	getline(scmd,512);
	scanf("%d",&cmd);
	while(cmd!=0){
		int pid=fork();
		if(pid==-1){
			printf("fork error\n");
		}
		else if(pid==0){
			printf("this is child with pid: %d\n",getpid());
			printf("parent pid is: %d\n",getppid());
			switch(cmd){
				case 1: execl("/usr/bin/who","who",NULL);
				case 2: execl("/bin/ls","ls",NULL);
				case 3: execl("/usr/bin/uptime","uptime",NULL);
				case 4: execl("/bin/ps","ps",NULL);
				default: printf("NO DAP\n");
			}
			exit(1);		}
		else {
			printf("this is parent with pid: %d\n",getpid());
			printf("waiting\n");
			wait();
			printf("returned to parent with pid: %d\n",getpid());
		}
		print_menu();
		getline(scmd,512);
		scanf("%d",&cmd);
	}
	printf("exiting program\n");
}
