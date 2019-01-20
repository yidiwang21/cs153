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
#define FORK_NUM        10

void test_status(void);
void test_wait(void);
void test_waitpid(void);

int main(int argc, char const *argv[])
{
    test_status();

    return 0;
}

void test_status(void) {
    int cpid, vpid;
    int status;

    for(int i = 0; i < FORK_NUM; i++) {
        cpid = fork();
        if (cpid < 0) {
            printf(1, "# Fork error");
            exitS(EXIT_FAILURE);
        }else if (cpid == 0) {
            // child process
            printf(1, "# [pid = %d] (child) exit status: %d\n", getpid(), i);
            exitS(i);
        }else {
            vpid = waitS(&status);
            printf(1, "# [pid = %d] (verifying) exit status: %d\n", vpid, status);
        }
    }
}