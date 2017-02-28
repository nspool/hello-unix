#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

static void sig_int(int signo);

int main() {

	if(signal(SIGINT, sig_int) == SIG_ERR){
		printf("signal error!");
	}

	while(1)
	{
	}
}

void
sig_int(int signo){
	printf("interrupt: %d\n", signo);
}
