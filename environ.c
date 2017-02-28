#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int
main()
{
	printf("Environment\n");
	printf("%s\n", getenv("LOGNAME"));
	printf("%s\n", environ[2]);
	return 0;
}
