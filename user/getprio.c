#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc != 2){
    printf("Usage: getprio pid\n");
    exit(0);
  }

  int pid = atoi(argv[1]);
  int prio = getpriority(pid);

  if(prio < 0)
    printf("Process not found\n");
  else
    printf("Priority of process %d is %d\n", pid, prio);

  exit(0);
}
