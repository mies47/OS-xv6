#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    for(int i = 0; i < 10; i++) 
    { 
        if(fork() == 0) 
        { 
            for(int j = 0 ; j < 1000 ; j++){
                printf(1, "/ %d / : / %d /\n", getpid(), j); 
                
            }
        } 
        else{
            while(wait() != -1);
            sleep(1);
            exit();
        }
    }
    
    while(wait() != -1);
    sleep(1);

    uint cbt = getCBT();
    uint wait = getWaiting();
    uint turnarround = getTurnAround();
    printf(1, "CPU Brust Time : %d \n", cbt);
    printf(1, "Waiting Time : %d \n", wait);
    printf(1, "TurnArround Time : %d \n", turnarround);
    exit();
    
}