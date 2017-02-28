#include	<stdio.h>

int
main(void)
{
	printf("termid: %s\n", ctermid(NULL));
	return 0;
}
