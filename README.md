# Operating_System_Lab_Tasks
Operating System subject lab tasks sem 5. 

## Lab 1
- Implementation of “cat” and “cp” command in C. (use of open, read, write, and close system calls)

## Lab 2
- Implementation of “pwd” and “ls” command in C. (use of getcwd, opendir, readdir, closedir)

## Lab 3
- Process Creation and Termination (Use of fork, wait, getpid, and getppid system calls).
1. Call fork once, twice, thrice and print “Hello”. Observe and interpret the outcomes.
2. Print PID and PPID for parent and child processes. Observe and interpret the outcomes.

## Lab 4
1. Write a program to print process id and process name of all the current
  processes in the system.
- Extend the above program to read and display other fields from the stat file.

## Lab 5
- Thread creation and Termination. Synchronization using mutex
lock and unlock. (Use of pthread_create, ptread_join, pthread_mutex_lock
and pthread_mutex_unlock library functions of Pthread library).
1. Write a program to create a thread using pthread_create.
2. Write a program to pass a character string to the threaded function.
3. Write a program to implement a simple calculator using threads.
4. Write a program to multiply two matrices.

## Lab 6
- Inter process communication ( Use of pipe system call and mkfifo )
1. Write a program to create a pipe and print the values of pipe file descriptors.
2. Write a program to pass a message from parent process to child process
through a pipe.
3. Write a program to pass file name from parent process to child process through
a pipe, child process should pass the file contents to parent process and parent
should print the contents
4. Demonstrate the use of named pipe with appropriate programs and commands.

## Lab 7
1. Write a program to implement ls | sort functionality using the system calls and
functions covered in the lab.
2. Write a program to achieve following:
- Child process should open a file with the contents to be sorted, pass the
contents to the parent process.
- Parent process should sort the contents of the file and display.
3. Execv function demo program

## Lab 8
1. Implement the linux shell in C.
- [Linux Shell In C](https://gist.github.com/nevilparmar11/6c617636944a7cdb1774ed87343624ef)

## Lab 9
1. Write a program to implement a solution of bounded buffer producer consumer
problem using semaphores.

## Lab 10
1. Reader Writers problem ( Readers have priority).
2. Reader Writers problem ( Writers have priority ).

## Lab 11
1. Sleeping Barber Problem
2. Dining Philosopher Problem

## Lab 12
1. Banker's Algorithm
