// read a filename using cmd args in the parent proc and
// parse the filename through file to the child proc
// child proc should read the filename and print the file contents.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<strings.h>

int main(int argc,char* argv[])
{
	int pipefd[2];
	pipe(pipefd);
	
	int pid = fork();
	char buf[100];
	
	if(pid == -1)
	{
		printf("Error occured\n");
		exit(1);
	}
	else if(pid > 0)
	{
		//parent part
		close(pipefd[0]);
		write(pipefd[1],argv[1],sizeof(buf));
	}
	else
	{
		//child part
		close(pipefd[1]);
		bzero(buf,sizeof(buf));

		read(pipefd[0],buf,sizeof(buf));
		int fd = open(buf,O_RDONLY);
		int n = read(fd,buf,sizeof(buf));
		write(1,buf,n);		
	}
	return 0;
}
