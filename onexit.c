#include <stdlib.h>
#include <stdio.h>

static void onexit();

int
main()
{
	atexit(onexit);
	sleep(10);
	exit(0);
}

static void onexit()
{
	printf("Now exiting. Toodles!\n");
}
