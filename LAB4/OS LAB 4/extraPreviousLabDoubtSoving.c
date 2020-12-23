#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{
	int pid;
	int status;
	pid = fork();
	if(pid == -1)
	{
		printf("Error!\n");
	}
	else if(pid > 0)
	{
		wait(&status);
		printf("Hello from parent\n");
		printf("pid = %d\n",getpid());
		printf("ppid = %d\n",getppid());
		exit(0);
	}
	else
	{
		// child part
		// pid = 0
		printf("Hello from child\n");
		printf("child pid = %d\n",getpid());
		printf("child ppid = %d\n",getppid());
	
	}
	return 0;
}