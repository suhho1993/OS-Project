#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>


void print_menu(void){
	printf("This is simple shell program by Suhho\n");
	printf("Type in what you want to start\n ");

}
/*
void startcmd(char *cmd){
	int i=0;
	char *tcmd;
	char cmdl[10]={};

	tcmd=strtok(cmd," ");
	while(tcmd){
		cmdl[i]=tcmd;
		tcmd=strtok(NULL," ");
		printf("cmdline: %s\n",cmdl[i]);
		i++;
	}
	
	char *mpath=getenv("PATH");
	char *tokpath;
	char *go;
	int  check;

	tokpath=strtok(mpath,":");

	while(tokpath){
	printf("%s \n",tokpath);
	sprintf(go,"%s%s",tokpath,cmdl[0]);
	tokpath=strtok(NULL,":");
	check=execve(go,cmdl,NULL);
	}
	if(check==-1){
		printf("//no such command\n");
		exit(0);
		}

} */

int main(){
	char cmd[512];
	
	int i=0;
	char *tcmd;
	
	char cmdl[10]={};

	tcmd=strtok(cmd," ");
	while(tcmd){
		cmdl[i]=tcmd;
		tcmd=strtok(NULL," ");
		printf("cmdline: %s\n",cmdl[i]);
		i++;
	}

	char *mpath=getenv("PATH");
	char *tokpath;
	char *go;
	int check;

	print_menu();
	fgets(cmd,512,stdin);

	printf("%s\n\n\n",cmd);

	while(!strcmp(cmd,"exit")){
		
		
		int pid=fork();
		if(pid==-1){
			printf("fork error\n");
		}
		else if(pid==0){
			printf("this is child with pid: %d\n",getpid());
			printf("parent pid is: %d\n",getppid());
			printf("////////////////////////////////////////////\n");
			
			tokpath=strtok(mpath,":");
			while(tokpath){
				printf("%s\n",tokpath);
				sprintf(go,"%s%s",tokpath,cmdl[0]);
				tokpath=strtok(NULL,":");
				check=execve(go,cmdl,NULL);
			}
			if(check==-1){
				pritnf("//NO SUCH COMMAND\n");
				exit(1);
			}

			//startcmd(cmd);
		//	exit(1);	
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
