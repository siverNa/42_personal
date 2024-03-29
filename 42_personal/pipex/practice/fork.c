#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t	pid;
	pid = fork();
    if (pid < 0)
    {
        printf("fork error!\n");
        exit(0);
    }
	if (pid > 0) // parent process
	{
		printf("parent PID: %d\n", getpid());
		printf("PID from fork() to the parent: %d\n", pid);
	}
	else if (pid == 0) // child process
	{
		printf("child PID: %d\n", getpid());
		printf("PID from fork() to the child: %d\n", pid);
	}
	return (0);
}