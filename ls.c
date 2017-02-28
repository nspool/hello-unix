#include <sys/types.h>
#include <dirent.h>

int
main(int argc, char* argv[])
{
	DIR 		*dp;
	struct dirent	*dirp;

	if(argc != 2) {
		printf("a single argument is required\n");
		exit(1);
	}

	if( (dp = opendir(argv[1])) == NULL) {
		printf("cannot open directory %s!", argv[1]);
	}

	while( (dirp = readdir(dp)) != NULL) {
		printf("\nd_name  \t%s\n", dirp->d_name);
		printf("d_fileno\t%d\n", dirp->d_fileno);
		printf("d_off   \t%d\n", dirp->d_off);
		printf("d_reclen\t%d\n", dirp->d_reclen);
		printf("d_type  \t%d\n", dirp->d_type);
		printf("d_namlen\t%d\n", dirp->d_namlen);
	}
}
