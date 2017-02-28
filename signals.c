#include	<stdio.h>
#include	<stdlib.h>
#include	<signal.h>

static void
sig_usr(int signo)
{
	if(signo == SIGUSR1) {
		printf("Received SIGUSR1\n");
		raise(SIGUSR2);
	}
	else if(signo == SIGALRM)
		printf("Received SIGALRM!\n");
	else if(signo == SIGUSR2)
		printf("Received SIGUSR2\n");

	printf("Signal %d\n", signo);
	psignal(signo, "TestProg");

	return;
}

int
main(void)
{
	sigset_t sigmask;

	sigemptyset(&sigmask);
	sigaddset(&sigmask, SIGQUIT);

	if(signal(SIGUSR1, sig_usr) == SIG_ERR)
		printf("can't catch SIGUSR1\n");
	if(signal(SIGUSR2, sig_usr) == SIG_ERR)
		printf("can't catch SIGUSR2\n");
	if(signal(SIGALRM, sig_usr) == SIG_ERR)
		printf("can't catch SIGALRM\n");

	alarm(60);
	int left = alarm(5);
	printf("replacing alarm that had %d seconds to go\n", left);
//	for(;;) {
	// waiting for any old signal:
		pause();
//	}

	abort();
}
