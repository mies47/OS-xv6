#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int x = atoi(argv[1]);
    sleep(1);
    sleep(1);
    sleep(1);
    sleep(1);
    printf(1, "number of sleep system call = %d \n", getSyscallCounter(x));
    exit();
    return 0;
}