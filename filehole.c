#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int
main(void)
{
	int fd;

	fd = creat("file.hole", O_CREAT | O_TRUNC | O_WRONLY);
	write(fd, buf1, 10);
	lseek(fd, 40, SEEK_SET);
	/* offset now 40 */
	write(fd, buf2, 10);

	exit(0);
}
