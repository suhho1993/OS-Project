#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char *argv[]){

char* str;
str=getenv("TIME");
printf("%s\n",str);


return 0;
}

