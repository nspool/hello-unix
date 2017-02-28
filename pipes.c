#include	<stdio.h>
#include	<unistd.h>

#define MAXLINE 100

int
main(void)
{
	int fd[2];
	pid_t pid;

	pipe(fd);
	
	pid = fork();

	if(pid > 0) {
		close(fd[0]);
		write(fd[1], "Helo, world\n",12);
	} else {
		close(fd[1]);
		char line[MAXLINE];
		int n = read(fd[0], line, MAXLINE);
		write(STDOUT_FILENO, line, n);
	}
}

	
