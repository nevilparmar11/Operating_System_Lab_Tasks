// parent send filename
// child send contents
// parent prints contents

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc,char* argv[])
{
	int pipefd[2],pipefd2[2];
	pipe(pipefd);
	pipe(pipefd2);
	int pid = fork();
	char buffer[100];
	

	if(pid == -1)
	{
		printf("Error\n");
	}
	else if(pid > 0)
	{
		close(pipefd[0]);
		close(pipefd2[1]);
		
		//parent part
		write(pipefd[1],argv[1],sizeof(argv[1]));
		wait(NULL);
		bzero(buffer,sizeof(buffer));
		int m = read(pipefd2[0],buffer,sizeof(buffer));
		write(1,buffer,m);
	}		
	else
	{
		
		close(pipefd[1]);
		close(pipefd2[0]);
		
		//child part
		bzero(buffer,sizeof(buffer));
		read(pipefd[0],buffer,sizeof(buffer));


		int fd = open(buffer,O_RDONLY);
		int n = read(fd,buffer,sizeof(buffer));
		write(pipefd2[1],buffer,n);

	}
	return 0;
}
