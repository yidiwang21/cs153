#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

#define MAXFORKS 1

int test_scheduler(void);

int main(int argc, char *argv[])
{

  printf(1, "\n FFFFFUUUUCCCCKKKKK YYYYYOOOUUUU\n");
  
    test_scheduler();
	return 0;
 }

int test_scheduler(void) {
  int pid, cpid, wpid, status, cnt;
  unsigned int i, n;

//   printf(1, "\nTesting priority scheduler\n\n");Z
//   setpriority(0);
  printf(1, "\n FFFFFUUUUCCCCKKKKK YYYYYOOOUUUU!!!!!!!!!!!!!!!!!!!\n");
  cpid = fork();
  if (cpid == 0) {
      for (n = 0; n < MAXFORKS; n++) {
        pid = fork();
        if (pid == 0) {
          setpriority(n+1);
          break;
        } else if (pid > 0) {
          setpriority(63);
        } else {
          printf(1, "fail\n");
          exitS(-1);
        }
      }
      if (pid > 0) {
        printf(1, "[%d] was used to create processes of ascending priority.\n",
            (int) getpid());
        printf(1, "[%d] waiting for all children to exit.\n", (int) getpid());
        for (i = 0; i < 33554432; i++)
          cnt = (i % 2) ? cnt + i : cnt - i;
        while((wpid=waitS(&status)) >= 0)// && wpid != pid)
          ;
      }
      for (i = 0; i < 8388608; i++)
        cnt = (i % 2) ? cnt + i : cnt - i;
      printf(1, "[%d] has priority: %d\n", (int) getpid(), getpriority());
      exitS(0);
  } else if (cpid > 0) {
    cpid = waitpid(cpid, 0, 0);
    printf(1, "\n");
  } else {
    printf(2, "fail\n");
    exitS(-1);
  }

  return 0;
}





