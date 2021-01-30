#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    int pid = fork();
    wait();
    if(pid == 0){ 
        printf(1, "the process ID is %d \n", getpid());
        printf(1, "the parent ID id %d \n", getParentID()); 
    }
    exit();
    return 0;
}