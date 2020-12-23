#include<stdio.h>
#include<pthread.h>

typedef
struct mystruct
{
	int x;
}S;

void * f1(void * spt)
{
	S *sptr = (S *)spt;
	printf("Reply from thread : %d\n", sptr->x);
}

int main()
{
	pthread_t t1;

	S st, *pstr;
	st.x = 10;
	pstr = &st; 

	pthread_create(&t1, NULL , f1, (void *)pstr);
	pthread_join(t1, NULL);
	printf("Parent (Here main thread, i.e main method) Thread joins\n");
	
	return 0 ;
}
