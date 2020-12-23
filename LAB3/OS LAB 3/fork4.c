#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int pid;
	pid = fork();
	if(pid == -1)
	{
		printf("Error!\n");
	}
	else if(pid > 0)
	{
		printf("Hello from parent\n");
		printf("pid = %d\n",getpid());
		printf("ppid = %d\n",getppid());
	
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

/*

Output:
Hello from parent
Hello from child


Extra:

can be useful to achieve separeate tasks independently

1. Inside parent block we can run ls in terminal
2. whose output will be given to child ( here child block )
	which will sort the output of ls, executed in parent block.



*/