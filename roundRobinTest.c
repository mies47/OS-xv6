#include "types.h"
#include "stat.h"
#include "user.h"
#include "spinlock.h"


int main(void){
    int CBT[10];
    int waiting[10];
    int TA[10];
    int pids[10];
    int pid;
    int totalCBT = 0;
    int totalWaiting = 0;
    int totalTA = 0;
    for (int i = 0; i < 10; i++)
    {
        pids[i] = fork();
        if(pids[i] == 0){
            
            for (int j = 1; j <1000; j++)
            {
                printf(1 , "\n/%d/ : /%d/\n" , getpid() , j);
            }

            exit();            
        }
    }
    
    for (int i = 0; i < 10; i++)
    {
        pid = mywait(&CBT[i] , &waiting[i] , &TA[i]);

        totalCBT+= CBT[i];
        totalWaiting+= waiting[i];
        totalTA += TA[i];
        
        printf(1 , "CBT %d is: %d\n" , pid, CBT[i]);
        printf(1 , "Waiting %d is: %d\n" ,pid, waiting[i]);
        printf(1 , "TurnAround %d is: %d\n" ,pid, TA[i]);
        
    }
    

    
    printf(1, "Average CBT is: %d\n" , (int)(totalCBT / 10));
    printf(1, "Average waiting is: %d\n" , (int) (totalWaiting/ 10));
    printf(1, "Average turnAround is: %d\n" , (int) (totalTA / 10));

    
    while(wait() != -1);

    sleep(1);

    
    exit();
    
}