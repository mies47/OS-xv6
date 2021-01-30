#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    // int pid = fork();
    // fork();
    // wait();
    // if (pid > 0){
    //    printf(1, "number of fork system call = %d ", getSyscallCounter(1));
    // }
    sleep(1);
    sleep(1);
    sleep(1);
    printf(1, "number of sleep system call = %d ", getSyscallCounter(13));
    exit();
    return 0;
}