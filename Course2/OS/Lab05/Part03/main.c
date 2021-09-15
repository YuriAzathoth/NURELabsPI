#include <sys/unistd.h>
#include <sys/wait.h>
#include <stdio.h>

#define FILE_1		"./file1"
#define FILE_2		"./file2"
#define FILES_LIST	FILE_1, FILE_2
#define ARGS		APP_PATH, FILES_LIST

#define APP_01_APP	"Part01"
#define APP_02_APP	"Part02"
#define EXEC_APP(x)	x, x, FILES_LIST
#define APP_01_CMD	EXEC_APP(APP_01_APP)
#define APP_02_CMD	EXEC_APP(APP_02_APP)

int main()
{
	pid_t pid = fork();

	if (!pid)
		execl(APP_01_CMD);
	else if (pid > 0)
	{
		wait(0);
		execl(APP_02_CMD);
	}

	perror("fork");
	perror("execl");

    return 0;
}
