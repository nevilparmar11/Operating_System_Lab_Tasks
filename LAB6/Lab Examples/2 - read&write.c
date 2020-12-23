#include<unistd.h>
#include<stdio.h>

int main()
{
	int pid;
	
	int pipefd[2];
	int err = pipe(pipefd);
	
	if(err!=0)
	{	
	
		write(1,"error",5);
	}
	
	pid = fork();
	
	if(pid == -1)
		printf("Process creation error\n");

	else if(pid > 0)
	{
		//parent part
		close(pipefd[0]);
		char ch[1000] = {'\0'};
		read(0,ch,1000);
		printf("Parent pid: %d sending message: %s to child pid: %d \n",getpid(),ch, pid );
		write(pipefd[1],ch,1000);
	}
	else
	{
		//child part
		close(pipefd[1]);
		char ch2[1000] = {'\0'};
		int n = read(pipefd[0],ch2,1000);
		printf("Child pid: %d received message: %s from parent pid: %d \n",getpid(),ch2, getppid() );
		write(1,ch2,1000);
	}
	
	return 0;
}
