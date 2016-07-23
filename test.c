#include "types.h"
#include "stat.h"
#include "user.h"
#include "linkedlist.h"
#include "thread.h"

int
main (int argc, char* argv[]) {
  int n = 23;
  char* names[n];
  int counts[n];
  names[1] = "fork";
  names[2] = "exit";
  names[3] = "wait";
  names[4] = "pipe";
  names[5] = "write";
  names[6] = "read";
  names[7] = "close";
  names[8] = "kill";
  names[9] = "exec";
  names[10] = "open";
  names[11] = "mknod";
  names[12] = "unlink";
  names[13] = "fstat";
  names[14] = "link";
  names[15] = "mkdir";
  names[16] = "chdir";
  names[17] = "dup";
  names[18] = "getpid";
  names[19] = "sbrk";
  names[20] = "sleep";
  names[21] = "uptime";
  names[22] = "getcount";

  int i;
  for (i = 0; i < 20; i++) {
    getcount(counts, n);
  }

  for (i = 1; i < n; i++) {
    if (counts[i] < 0) {
      printf(1, "Count %s has a negative count of %d!\n", names[i], counts[i]);
    }
    printf(1, "Count %s: %d\n", names[i], counts[i]);
  }

  exit();

    printf(1, "Beginning Test\n");
    //   struct lock_t lock;
    //   lock = *(struct lock_t *)malloc(sizeof(struct lock_t));
    //   lock_acquire(&lock);
    int parent = getpid();
    char* stack = malloc(4096);
    /*  printf(1, "stack outside %d\n", stack[0]);*/
    int rc = clone(stack, 4096);
  
    printf(1, "Clone returns = %d\n", rc);
    /*  struct lock_t t;
//   t = (struct lock_t)malloc(sizeof(struct lock_t));
  lock_init(&t);
//   int i;
//   for (i = 0; i < 10; i++) {
//     ll_add(i);
//   }
//   ll_print();
//   ll_coolj();*/

    int pid = getpid();
    if (pid == parent) {
      int ret = wait();
      printf(1, "wait returned %d\n", ret);
    }

    printf(1, "pid: %d exiting\n", pid);
    exit();
}
