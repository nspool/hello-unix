#include	<stdlib.h>
#include	<stdio.h>

int
main(void)
{
	printf("Real: %d, Effective: %d\n", getuid(), geteuid());
	exit(0);
}
