#include<stdio.h>
#include<pthread.h>


void * f1()
{
	printf("Hello from thread\n");
}

int main()
{
	pthread_t t1;
	pthread_create(&t1, NULL , f1, NULL);
	// pthread_join(t1, NULL);

	return 0 ;
}


/*

It prints nothing because we are not making the main thread to wait for this t1 thread.
Hence the output got stuck in the buffer and nothing gets printed on the terminal

So , if you run it 5 6 times continuosly, you might see the output of f1 function.


Solution :

use of pthread_join() function from the same library.
It will make the parent thread wait to execute first child thread and hence the parent will start executing only after the child gets destroyed.

*/