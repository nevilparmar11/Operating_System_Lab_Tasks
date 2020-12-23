#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int pid;
	pid = fork();
	pid = fork();
	printf("Hello\n");
	return 0;
}

/*

It prints 4 hello.
also sometimes between terminal prompts .
Process dispatchers dispatches the process on the basis of some contexts, so while running this prog multiple times we might get this kindof behaviour.


*/