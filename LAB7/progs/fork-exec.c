#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

#define readEnd 0
#define writeEnd 1

void report_and_exit(const char* msg) {
  perror(msg);
  exit(EXIT_FAILURE);    /** failure **/
}

int main()
{
	int pipeFds[2];
	int status = pipe(pipeFds);

	if(status == -1)
	{
		report_and_exit("Pipe Failed ! \n");
	}

	int pid = fork();

	if(pid == -1)
	{
		report_and_exit("Fork Failed ! \n");
	}

	else if (pid > 0)
	{
		/*	parent process 	*/

		wait(NULL);
		close(readEnd); // close the standard input file
		dup2(pipeFds[0], readEnd);
		close(pipeFds[1]);
		execl("/bin/sort","sort",NULL);
	}

	else 
	{
		/*	child process */

		close(writeEnd); // close the standard output file
		dup2(pipeFds[1], writeEnd); // now pipeFds[1] (the writing end of the pipe) is the standard output
		close(pipeFds[0]);
		execl("/bin/ls","ls",NULL);
	}

	return 0;
}
