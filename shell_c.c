#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>


void print_menu(void){
	printf("This is simple shell program by Suhho\n");
	printf("Type in what you want to start\n ");

}

void startcmd(char *cmd){

	char *tcmd;
	char *cmdop;

	tcmd=strtok(cmd," ");
	cmdop=strtok(NULL," ");

	printf("//%s \n //%s\n",tcmd,cmdop);


	char *mpath=getenv("PATH");
	char *tokpath;

	tokpath=strtok(mpath,":");

	while(tokpath=(NULL,":")){
	printf("%s \n",tokpath);
	//	sprintf(

	}
}

int main(){
	char cmd[512];
	
	print_menu();
	fgets(cmd,512,stdin);

	printf("%s\n\n\n",cmd);

	while(cmd!=NULL){
		int pid=fork();
		if(pid==-1){
			printf("fork error\n");
		}
		else if(pid==0){
			printf("this is child with pid: %d\n",getpid());
			printf("parent pid is: %d\n",getppid());
			printf("////////////////////////////////////////////\n");
			startcmd(cmd);
			exit(1);	
		}
		else {
			printf("this is parent with pid: %d\n",getpid());
			printf("waiting\n");
			printf("///////////////////////////////////////////\n");
			wait();
			printf("returned to parent with pid: %d\n",getpid());
			printf("///////////////////////////////////////////\n");
		}
		print_menu();
		//cmd=NULL;
		//getline(scmd,512);
		fgets(cmd,512,stdin);
	}
	printf("exiting program\n");
}
