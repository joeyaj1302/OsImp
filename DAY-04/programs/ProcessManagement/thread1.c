#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
/* need to include header file "pthread.h" for thread lib functions */

//step-1: implement thread function/thread procedure --> void *funtion_name(void *);
void* increment(void* param)
{
	int i;
	for(i=0; i<10; i++)
	{
		printf("inc : %d\n", i);
		sleep(1);
	}
	return NULL;
}

//step-1: implement thread function/thread procedure --> void *funtion_name(void *);
void* decrement(void* param)
{
	int i;
	for(i=9; i>=0; i--)
	{
		printf("dec : %d\n", i);
		sleep(1);
	}
	return NULL;
}

int main(void)
{
	pthread_t it, dt;
	int i;
	
	//create a thread
	pthread_create(&it, NULL, increment, NULL);//attaches thread object "it" => increment 
	pthread_create(&dt, NULL, decrement, NULL);//attaches thread object "dt" => decrement 

	//main thread
	for(i=0; i<5; i++)
	{
		printf("main: %d\n", i);
		sleep(1);
	}

	//due to this pthread_join() function main thread will wait for completion of its threads 
	pthread_join(it, NULL);
	pthread_join(dt, NULL);

	return 0;
}

/*
	ret = pthread_create(&tid, NULL, thread_func, args);

	arg1: addr of thread id (out-param)
	arg2: thread attributes - stack size, priority, sched algo, ...
		NULL --> use default thread attrs
	arg3: addr of thread func/thread procedure
	arg4: args for thread function
	
	return value: returns 0 on success


	compile --> $gcc -c thread1.c
	link    --> $gcc -o thread1.out thread1.o -lpthread
	run     --> $./thread1.out
	command to check info about process and its threads:
		$ps -t pts/0 -m -o pid,tid,nlwp,cmd
*/

