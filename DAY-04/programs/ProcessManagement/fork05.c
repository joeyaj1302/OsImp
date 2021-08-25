#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

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
		for( i = 1 ; i <= 40 ; i++ )
		{
			printf("child: %d\n", i);
			sleep(1);
		}
	}
	else//parent process
	{
		for( i = 40 ; i > 0 ; i-- )
		{
			printf("parent: %d\n", i);
			sleep(1);
		}
	}

	printf("main() exited !!!\n");

	return 0;
}
