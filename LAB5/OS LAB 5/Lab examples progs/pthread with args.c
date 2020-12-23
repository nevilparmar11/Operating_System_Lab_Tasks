#include<stdio.h>
#include<pthread.h>


void * f1(void * s)
{
	char * str = (char *)s;
	printf("Reply from thread : %s\n", str);
}

int main()
{
	pthread_t t1;
	char *s = "This was passed";
	pthread_create(&t1, NULL , f1, (void *)s);
	pthread_join(t1, NULL);
	printf("Parent (Here main thread, i.e main method) Thread joins\n");
	// pthread_join(t1, NULL);
	
	return 0 ;
}
