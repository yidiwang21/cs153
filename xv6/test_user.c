#include "types.h"
#include "user.h"

int main (int argc, char *argv[])
{
	int status;
	int cpid;
	if (fork()== 0)
		exitS(0);
	else
		cpid = waitS(&status);
	printf(1, "\n hello from user space! \n");
	printf(1, "parent pid = %d  \n",getpid());
	printf(1, "child pid = %d  \n",cpid);
	printf(1, "status %d  \n",status);

	return 0;
}
