#include	<syslog.h>

int
main(int argc, char** argv)
{
	openlog(argv[0], LOG_PID | LOG_NDELAY, LOG_USER); //optional
	setlogmask(LOG_UPTO(LOG_DEBUG));           
	syslog(LOG_INFO, "This is a test log message!");
	syslog(LOG_DEBUG, "<some uninteresting debug info here!>");
}
