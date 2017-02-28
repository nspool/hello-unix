#include	<signal.h>
#include	<termios.h>
#include	<unistd.h>
#include	<sys/ioctl.h>

static void pr_winsize(int), sig_winch(int);

int
main(void)
{
	signal(SIGWINCH, sig_winch);
	pr_winsize(STDIN_FILENO);
	for(;;)
		pause();
}

static void
pr_winsize(int fd)
{
	struct winsize size;
	ioctl(fd,TIOCGWINSZ, (char*)&size);
	printf("%d rows, %d columns\n", size.ws_row, size.ws_col);
}

static void
sig_winch(int signo)
{
	printf("SIGWINCH received!\n");
	pr_winsize(STDIN_FILENO);
	return;
}
