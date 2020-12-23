#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int pid;
	// printf("World");
	pid = fork();
	pid = fork();
	pid = fork();
	printf("Hello\n");
	return 0;
}

/*

It prints 8 hello.
after 1st fork there are 2 process . IP will point to second fork
each of newly createrd 2 processes points to third process.
and same for the third fork, but this processes will point to printf.
So in total 8 processes will print :hello: 8 times.


Extra:
if we uncomment printf world line. Then the output is unpredictable. It will not flush the memory buffer and the word wordl will stay there.

*/