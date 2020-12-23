#include<stdio.h> 
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main() 
{ 
	for(int i=0;i<4;i++) // loop will run n times (n=4) 
	{ 
		if(fork() == 0) 
		{ 
			printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid()); 
			exit(0); 
		} 
	} 
	for(int i=0;i<4;i++) // loop will run n times (n=4) 
		wait(NULL); 


	return 0;
} 
