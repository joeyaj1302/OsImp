#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(void)
{
	int ret;
	printf("main() started !!!\n");

	printf("parent => pid: %d\n", getpid());

	ret = fork();//child process gets created
	if( ret == -1 )
	{
		perror("fork() failed !!!\n");
		_exit(1);
	}

	if( ret == 0 )//child process
	{
		printf("child: ret = %d\n", ret);
		printf("child: pid = %d\n", getpid());
	}
	else//parent process
	{
		printf("parent: ret = %d\n", ret);
		printf("parent: pid = %d\n", getpid());
	}

	printf("main() exited !!!\n");

	return 0;
}
