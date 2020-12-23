// child is passing the msg to parent

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int pipefd[2];
	pipe(pipefd);
	
	int pid = fork();
	char buf[100];
	
	if(pid == -1)
		printf("Error has occured\n");
	
	else if(pid==0)
	{
		//child part	
		close(pipefd[0]);
		int m = read(0,buf,sizeof(buf));
		printf("Child pid: %d sending message: %s to parent pid: %d \n",getpid(),buf, getppid() );
		write(pipefd[1],buf,m);
	}
	else
	{
		//parent part
		close(pipefd[1]);
		wait(NULL);
		int n = read(pipefd[0],buf,sizeof(buf));
		printf("Parent pid: %d received message: %s from child pid: %d \n",getpid(), buf, pid );
		write(1,buf,n);
	}
	return 0;
}
