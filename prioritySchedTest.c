#include "types.h"
#include "stat.h"
#include "user.h"
#include "spinlock.h"


int main(void){
    int pid;
    for (int i = 0; i < 30; i++)
    {
        pid = fork();
        if(pid == 0){
            if(i < 5) setPriority(6);
            if(i > 4 && i < 10) setPriority(5);
            if(i > 24) setPriority(1);
            break;
            
        }
    }

    if(pid == 0){
        for (int j = 1; j <1000; j++)
        {
            my_acquire(j);
            // printf(1 , "/%d/ : /%d/\n" , getpid() , j);
        }

        my_acquire(-1);
        my_acquire(-2);
        my_acquire(-3);
        sleep(1);
        // printf(1 , "CBT is: %d\n" , getCBT());
        // printf(1 , "Waiting is: %d\n" , getWaiting());
        // printf(1 , "TurnAround is: %d\n" , getTurnAround());

        while(wait() != -1);
        sleep(1);
        exit();
        
    }

    while(wait() != -1);
    sleep(1);
    exit();
    
}