#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

/*
	to avoid zombie state:
	wait(): it does three things:
	 	- it pauses an execution of parent process
		- it reads an exit status of child process from its PCB and pass it to its parent
		- removes PCB entry of child process

	-------------------------------------------------------------*/

int main(void)
{
	int ret;
	int i;
	int status;
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
		_exit(11);
		printf("child is exited !!!\n");
	}
	else//parent process
	{
		for( i = 1 ; i <= 40 ; i++ )
		{
			printf("parent: %d\n", i);
			sleep(1);
			if( i == 20 )
			{
				wait(&status);
				printf("exit value of child is: %d\n", WEXITSTATUS(status));
			}
		}
		printf("parent is exited !!!\n");
	}

	printf("main() exited !!!\n");

	return 0;
}
