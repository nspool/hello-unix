#include	<sys/types.h>
#include	<stdio.h>
#include	<stdlib.h>

int
main(void)
{
	pid_t pid = getpid();
	printf("PID before fork: %d\n", pid);

	// Lazy fork bomb
	// (for testing system limits)

	for(;;)
	{
		pid = fork();

		if(pid > 0) {
			printf("Child PID: %d\n", pid);
		}
		if(pid < 0) {
			printf("Fork has failed!\n");
		}
		sleep(2);
	}
	return 0;
}
