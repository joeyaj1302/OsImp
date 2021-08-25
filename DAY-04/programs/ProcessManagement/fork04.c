#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(void)
{
	int ret;
	int i;
	printf("main() started !!!\n");

	printf("parent => pid: %d\n", getpid());

	ret = fork();//fork() -> function call statement
	/*
		ret = fork();//assign return value of fork() sys call to ret variable
		fork() -> called function
		main() -> calling function
	*/

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
		for( i = 1 ; i <= 40 ; i++ )
		{
			printf("parent: %d\n", i);
			sleep(1);
		}
	}

	printf("main() exited !!!\n");

	return 0;
}

/*
	- command to display info about only user processes currently running on tty2
	$ps -t pts/2 -o pid,ppid,cmd

	- - command to display info about all processes currently running on tty2
	$ps -e -t pts/2 -o pid,ppid,cmd,cm

*/

