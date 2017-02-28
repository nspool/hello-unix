#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int
main(int argc, char* argv[])
{

	char *src = "This is a test string!";
	int len = strlen(src);

	int fd = open("test.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR| S_IWUSR);	

	// set size of output file
	if(lseek(fd, len, SEEK_SET) == -1){
		perror("lseek failed");
	}

	if(write(fd, "", 1) != 1) {
		perror("write failed");
	}

	char *dest = mmap(0, 5, PROT_WRITE | PROT_READ, MAP_FILE | MAP_SHARED, fd, 0);

	if(src == MAP_FAILED) {
		perror("mmap failed");
	} else {
		memcpy(dest, src, len);
	}

	close(fd);
	exit(0);
}
