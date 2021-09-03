#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	redirect_in(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int main(int argc, char **argv)
{
	redirect_in(argv[1]);
	execve("/bin/cat", argv, 0);
	return (0);
}