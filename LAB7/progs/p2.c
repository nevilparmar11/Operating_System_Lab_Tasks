#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define readEnd 0
#define writeEnd 1

void report_and_exit(const char* msg) {
  perror(msg);
  exit(EXIT_FAILURE);    /** failure **/
}


int main(int argc, char *argv[]) {
    int pipeFds[2];
    char buffer[100];

    if (argc < 2) {
        fprintf(stderr, "usage: progname <filename>");
        exit(EXIT_FAILURE);
    }

    if (pipe(pipeFds) == -1) {
        report_and_exit("PIPE ERROR");
    }

    int pid = fork();

    if(pid == -1){
        report_and_exit("fork failed");
    }

    else if (pid > 0) {
        
        /*  Parent process */

        wait(NULL);
        close(readEnd); // close the standard input file
        dup2(pipeFds[0], readEnd);
        close(pipeFds[1]);
        execl("/bin/sort","sort",NULL);

    } else {
        
        /* Child Process */

        int fd;
        if ((fd = open(argv[1], O_RDONLY)) == -1) {
            report_and_exit("error opening file");    
        }

        close(writeEnd); // close the standard output file
        dup2(pipeFds[1], writeEnd); // now pipeFds[1] (the writing end of the pipe) is the standard output
        close(pipeFds[0]);

        char singleLine[150];

        while (read(fd, singleLine , sizeof(singleLine))) {
            write(pipeFds[1], singleLine, strlen(singleLine));
        }

        close(fd);
        
    } 

    return 0;
}