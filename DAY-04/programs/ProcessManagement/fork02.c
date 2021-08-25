#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(void)
{
	int ret;
	printf("main() started !!!\n");

	printf("pid: %d\n", getpid());

	ret = fork();
	
	if( ret == -1 )
	{
		perror("fork() failed !!!\n");
		/* perror() C lib function not only prints user's error message, it also prints
		system error message */
		_exit(1);
		//_exit() used to exit a process explicitly
	}

	printf("ret = %d\n", ret);
	printf("pid: %d\n", getpid());

	printf("main() exited !!!\n");

	return 0;
}
