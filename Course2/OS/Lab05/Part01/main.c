#include <sys/procfs.h>
#include <sys/unistd.h>
#include <stdio.h>

#define APP_PATH "geany"

int main(int argc, char** argv)
{
	printf("PID = %llu\n", getpid());
	execvp(APP_PATH, argv);
	perror("execvp");
	return 0;
}
