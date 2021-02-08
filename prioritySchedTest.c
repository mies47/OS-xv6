#include "types.h"
#include "stat.h"
#include "user.h"
#include "spinlock.h"


int main(void){
    int CBT[30];
    int waiting[30];
    int TA[30];
    int pids[30];
    int pid;
    int totalCBT[5] = {0 ,0 ,0 ,0 ,0};
    int totalWaiting[5] = {0 ,0 ,0 ,0 ,0};
    int totalTA[5] = {0 ,0 ,0 ,0 ,0};
    for (int i = 0; i < 30; i++)
    {
        pids[i] = fork();
        if(pids[i] == 0){
            if(i < 5) setPriority(6);
            if(i > 4 && i < 10) setPriority(5);
            if(i > 24) setPriority(1);
            for (int j = 1; j <= 250; j++)
            {
                printf(1 , "\n/%d/ : /%d/\n" , getpid() , j);
            }

            exit();            
        }
    }
    
    for (int i = 0; i < 30; i++)
    {
        pid = mywait(&CBT[i] , &waiting[i] , &TA[i]);
        for (int j = 0; j < 30; j++)
        {
            if(pid == pids[j]){
                if(j < 5){
                    totalCBT[0] += CBT[i];
                    totalWaiting[0] += waiting[i];
                    totalTA[0] += TA[i];
                }else if (j > 4 && j < 10)
                {
                    totalCBT[1] += CBT[i];
                    totalWaiting[1] += waiting[i];
                    totalTA[1] += TA[i];
                }else if (j > 24)
                {
                    totalCBT[2] += CBT[i];
                    totalWaiting[2] += waiting[i];
                    totalTA[2] += TA[i];
                }else{
                    totalCBT[3] += CBT[i];
                    totalWaiting[3] += waiting[i];
                    totalTA[3] += TA[i];
                }
                
                
            } 
        }

        totalCBT[4] += CBT[i];
        totalWaiting[4] += waiting[i];
        totalTA[4] += TA[i];
        
        printf(1 , "CBT %d is: %d\n" , pid, CBT[i]);
        printf(1 , "Waiting %d is: %d\n" ,pid, waiting[i]);
        printf(1 , "TurnAround %d is: %d\n" ,pid, TA[i]);
        
    }
    

    printf(1, "Average CBT priority 6 is: %d\n" , (int)(totalCBT[0] / 5));
    printf(1, "Average waiting priority 6 is: %d\n" , (int) (totalWaiting[0] / 5));
    printf(1, "Average turnAround priority 6 is: %d\n" , (int) (totalTA[0] / 5));

    printf(1, "Average CBT priority 5 is: %d\n" , (int)(totalCBT[1] / 5));
    printf(1, "Average waiting priority 5 is: %d\n" , (int) (totalWaiting[1] / 5));
    printf(1, "Average turnAround priority 5 is: %d\n" , (int) (totalTA[1] / 5));

    printf(1, "Average CBT priority 1 is: %d\n" , (int)(totalCBT[2] / 5));
    printf(1, "Average waiting priority 1 is: %d\n" , (int) (totalWaiting[2] / 5));
    printf(1, "Average turnAround priority 1 is: %d\n" , (int) (totalTA[2] / 5));

    printf(1, "Average CBT priority 3 is: %d\n" , (int)(totalCBT[3] / 15));
    printf(1, "Average waiting priority 3 is: %d\n" , (int) (totalWaiting[3] / 15));
    printf(1, "Average turnAround priority 3 is: %d\n" , (int) (totalTA[3] / 15));

    printf(1, "Average CBT is: %d\n" , (int)(totalCBT[4] / 30));
    printf(1, "Average waiting is: %d\n" , (int) (totalWaiting[4] / 30));
    printf(1, "Average turnAround is: %d\n" , (int) (totalTA[4] / 30));

    
    while(wait() != -1);

    sleep(1);

    
    exit();
    
}