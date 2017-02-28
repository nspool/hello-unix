#include	<stdio.h>

int
main(void)
{
	char sfn[] = "/tmp/tempfile.XXXXXXXXX";
	mkstemp(sfn);
	sleep(10);
	printf("%s\n", sfn);
	return 0;
}
