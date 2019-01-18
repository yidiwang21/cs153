#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

#define EXIT_FAILURE    1
#define EXIT_SUCCESS    0

int main(int argc, char const *argv[])
{
    int cpid;
    int status;

    // if (atoi(argv[1]) == 0) // test wait

    cpid = fork();
    if (cpid == -1) {
        printf(1, "# Fork error");
        exitS(EXIT_FAILURE);
    }

    if (cpid == 0) {
        // child process
        printf(1, "exiting child");
        exitS(EXIT_SUCCESS);
    }

    waitpid(cpid, &status, 0);
    if(!status) {
        printf(status, "EXIT status: %d");
    }

    return 0;
}
