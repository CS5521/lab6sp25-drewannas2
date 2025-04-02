#include "types.h"
#include "stat.h"
#include "user.h"
int 
main(int argc, char * argv[])
{
  int forks = fkc(1);
  printf(1, "number of forks when program starts: %d\n", forks);

  int pid = fork();
  if (pid == 0) {
    exit();
  }
  pid = fork();
  if (pid == 0) {
    exit();
  }
  forks = fkc(1);
  printf(1, "number of forks after two more forks: %d\n", forks);

  wait();
  wait();
  forks = fkc(0);
  printf(1, "number of forks after fork count cleared: %d\n", forks);

  pid = fork();
  if (pid == 0) { 
    exit();
  }
  pid = fork();
  if (pid == 0) {
    exit();
  }
  pid = fork();
  if (pid == 0) {
    exit();
  }
  forks = fkc(1);
  printf(1, "number of forks after three more forks: %d\n", forks); 
  wait();  
  wait();
  wait();

  exit();
}
