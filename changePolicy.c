#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int x = atoi(argv[1]);
    changePolicy(x);
    if(x == 0)
        printf(1, "Switch to Default XV6 Scheduling\n");
    if(x == 1)
        printf(1, "Switch to Round-Robin Scheduling\n");
    if(x == 2)
        printf(1, "Switch to Priority Scheduling\n");
    exit();
    return 0;
}