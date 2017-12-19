#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 2

void handler(int signum)
{
	printf("Thread: %ld got the signal : %d\n",(long)pthread_self(),signum);
}

void *thread(void *arg)
{
	signal(SIGCHLD,handler);
	printf("I am thread with id %ld waiting for signal\n",(long)pthread_self());
	pause();
}

int main()
{
	pthread_t tid;
	int i;
	
	
	
	printf("Main thread id = %ld\n",(long)pthread_self());
	
	for(i=0;i<NUM_THREADS;i++)
		pthread_create(&tid,NULL,thread,(void *)i);
		
	for(i=0;i<NUM_THREADS;i++)
		pthread_join(tid,NULL);
		
	if(!NUM_THREADS)
		pause();
}