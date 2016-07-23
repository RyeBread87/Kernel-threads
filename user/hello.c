#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

void myfunc(int arg) {
  //printf(1, "hello from func %d\n", arg);
  //int x = getpid();
  int x = 0;
  printf(1, "hello from func (pid%d)\n", x);
  //int x = 20;
  //printf(1, "hello from func again %d\n", x);
}

int main(int argc, char *argv[])
{
  printf(1, "hello from main\n");
  myfunc(0);
  exit();
}
