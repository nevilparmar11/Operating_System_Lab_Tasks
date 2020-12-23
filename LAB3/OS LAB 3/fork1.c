#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int pid;
	pid = fork();
	printf("Hello\n");
	return 0;
}

/*

It prints two hello on the same terminal. 
since it creates a new child process of the same context from the parent process.
we can also run this prog without catching return pid in the variable **PID**

*/