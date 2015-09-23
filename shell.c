#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main (int argc, char* argv[]){
	char *tcmd; //tokenized cmd
	char *mpath;//path str
	char *tokpath; // tokenized path
	char go[512]={}; // buffer for execution	
	char cmd[512]={};// buffer for cmd
	char* cmdline[10]={};// buffer for tokenized cmd


	while(strcmp(cmd,"exit")!=0){ //if the input is not exit 
		int i=0;
		//main program get cmd
		memset(cmd,0,sizeof(cmd));
		printf("SHELL SUHHO>> ");
		fgets(cmd,512,stdin);
		cmd[strlen(cmd)-1]='\0';
		
		//forked 
		pid_t pid=fork();
			
		if(pid==-1){
			printf("ERROR: fork error\n");
			exit(1);
		}
		else if(pid==0){
			printf("this is child, pid: %d\n\n", getpid());
			//command toknizing
			tcmd=strtok(cmd," ");
			while(tcmd){
				cmdline[i]=tcmd;
			//	printf("%s\n",cmdline[i]);
				tcmd=strtok(NULL," ");
				i++;
			}	
			//valid for cmd		
			int valid=0;
			
			//path tok
			mpath=getenv("PATH");
			
			tokpath=strtok(mpath,":");			
			
			while(tokpath){
				
				sprintf(go,"%s/%s",tokpath,cmdline[0]);
			
				valid=execve(go,cmdline,NULL);
				
				tokpath=strtok(NULL,":");	
			}
			if(valid==-1){
				printf("ERROR: NO SUCH COMMAND\n");
				exit(1);
			}

		}else{
			printf("this is parent, pid: %d\n\n",getpid());
			wait();
			printf("\nreturned to parent, pid: %d\n\n",getpid());
		}
	}
	printf("Exiting SHELL SUHHO\n");

	return 0;
}

			




