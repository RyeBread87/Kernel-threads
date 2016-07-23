#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "pstat.h"

int stdout = 1;
//struc pstat;

int
main(int argc, char *argv[])
{
  //int x = settickets(23);
   
  //const clock_t start = clock();
  // do stuff here
  //clock_t now = clock();
  //clock_t delta = now - start;
  //return (int) start;
  struct pstat *stat1;
  stat1 = malloc(sizeof(*stat1));   
  //int y = getpinfo(stat1);
  int y = getpinfo(NULL);

  int z = setpri(1);
  printf(stdout, "SETPRI, %d\n", z);

  int counter = 0;
  //for(counter = 0; counter < NPROCS; counter++){
  printf(stdout, "aux %s, \n", stat1->aux[counter]);
    printf(stdout, "PID %d, \n", stat1->pid[counter]);
    printf(stdout, "INUSE %d, \n", stat1->inuse[counter]);
    printf(stdout, "LTICKS %d, \n", stat1->hticks[counter]);   
    printf(stdout, "HTICKS %d, \n", stat1->lticks[counter]);   
    //}     
   
  // = malloc(sizeof(stat1));
  //y = y+0;
  //printf(1, x);
    printf(stdout, "hello you, %d\n", y);
  //return 0;
  exit();
}
