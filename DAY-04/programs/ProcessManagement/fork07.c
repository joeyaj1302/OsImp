#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

/* "zombie state":
	if child process terminates before its parent and parent continues its execution without
	reading exit status of its child, PCB entry of a child process remains exists in a main
	memory even after termination in "defunct state", and this state is also reffered as
	zombie state.
	- in this case child process will be referred as a zombie process.
--------------------------------------------------------------------------------------*/

int main(void)
{
	int ret;
	int i;
	printf("main() started !!!\n");

	printf("pid: %d\n", getpid());

	ret = fork();
	if( ret == -1 )
	{
		perror("fork() failed !!!\n");
		_exit(1);
	}

	if( ret == 0 )//child process
	{
		for( i = 1 ; i <= 20 ; i++ )
		{
			printf("child: %d\n", i);
			sleep(1);
		}
		printf("child is exited !!!\n");
	}
	else//parent process
	{
		for( i = 1 ; i <= 40 ; i++ )
		{
			printf("parent: %d\n", i);
			sleep(1);
		}
		printf("parent is exited !!!\n");
	}

	printf("main() exited !!!\n");

	return 0;
}
