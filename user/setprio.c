#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  if(argc != 3){
    printf("Usage: setprio pid priority\n");
    exit(1);
  }

  int pid = atoi(argv[1]);
  int prio = atoi(argv[2]);

  int ret = setpriority(pid, prio);
  printf("setpriority returned %d\n", ret);

  exit(0);
}
