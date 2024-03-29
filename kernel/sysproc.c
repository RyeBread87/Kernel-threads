#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "sysfunc.h"
#include "spinlock.h"
#include "pstat.h"

struct {
  struct spinlock lock;
  struct proc proc[NPROC];
} ptable;

int
sys_getprocs(void)
{
  int cnt = 0;
  struct proc *p;

  acquire(&ptable.lock);
  for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
    if (p -> state != UNUSED) {
      cnt++;
    }
  }

  release(&ptable.lock);
  return cnt;
}

// P2 - setting priority
int
sys_setpri(void)
{
  //return -10;
  int num = -1;
  argint(0, &num);
  //return num;

  if ((num != 1) && (num != 2)) {
    return -1;
  }

  int pid = sys_getpid();
  struct proc *p;

  //return NPROC;

  acquire(&ptable.lock);
  for (p = ptable.proc; p < &ptable.proc[NPROC]; p++) {
    if (p -> pid == pid) {
      if (p -> priority != num) {
	p -> priority = num;
	break;
      }
    }
  }
  release(&ptable.lock);
  return 0;
}

int
sys_getpinfo(void)
{
  int y = getpinfo();
  return y;
}

int
sys_fork(void)
{
  return fork();
}

int
sys_clone(void)
{
  void* fcn;
  void* arg;
  void* stack;

  //make sure arguments from the stack are sanitary
  if(argptr(0, (void*)&fcn, sizeof(void *)) < 0){
    return -1;
  }

  if(argptr(1, (void*)&arg, sizeof(void *)) < 0){
    return -1;
  }

  if(argptr(2, (void*)&stack, sizeof(void *)) < 0){
    return -1;
  }

  return clone(fcn, arg, stack);
}

int
sys_join(void)
{
  void** stack;

  if(argptr(0, (void*)&stack, sizeof(void *)) < 0){
    return -1;
  }

  return join(stack);
}


int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since boot.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

