#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
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
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
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
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// return an array of all children's pid
void
sys_getChildren(void){
  int * x = 0;
  argptr(0 , (void*)&x , sizeof(*x));
  getChildren(x);
}

int
sys_getParentID(void)
{
  return getParentID();
}

int
sys_getSyscallCounter(void)
{
  int n;

  if(argint(0, &n) < 0)
    return -1;
  return getSyscallCounter(n);

}

void
sys_setPriority(void)
{
  int n;
  if(argint(0 , &n) >= 0)
    setPriority(n);
}

uint
sys_getCBT(void){
  return getCBT();
}

uint
sys_getTurnAround(void){
  return getTurnAround();
}

uint
sys_getWaiting(void){
  return getWaiting();
}

void
sys_changePolicy(void)
{
  int n;

  if(argint(0, &n) < 0)
    return;
  return changePolicy(n);
}

void
sys_my_acquire(void)
{
  int n , m;

  argint(0, &n);
  argint(1 , &m);
    // return;
  my_acquire(n , m);
}
