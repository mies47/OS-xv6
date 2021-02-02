#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    uint cbt[10];
    uint waitt[10];
    uint turnarround[10];
    
    for(int i = 0; i < 10; i++) 
    { 
        if(fork() == 0) 
        { 
            for(int j = 0 ; j < 10 ; j++){
                printf(1, "/ %d / : / %d /\n", getpid(), j); 
                
            }
            cbt[i] = getCBT();
            waitt[i] = getWaiting();
            turnarround[i] = getTurnAround();
        } 
        else{
            while(wait() != -1);
            sleep(1);
            exit();
        }
    }
    
    while(wait() != -1);
    sleep(1);

    for(int k = 0 ; k < 10 ; ++k){
        printf(1, "CPU Brust Time for %d : %d \n",k, cbt);
        printf(1, "Waiting Time for %d : %d \n",k, waitt);
        printf(1, "TurnArround Time for %d : %d \n",k, turnarround);
    }
    
    exit();
    
}