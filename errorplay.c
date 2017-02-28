#include <string.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	printf("EACCES: %s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
	return 0;
}
