#include "types.h"
#include "stat.h"
#include "user.h"
#include "spinlock.h"


int main(void){
    int pid;
    uint CBT[30];
    uint waiting[30];
    uint TA[30];

    for (int i = 0; i < 30; i++)
    {
        CBT[i] = 0;
        waiting[i] = 0;
        TA[i] = 0;
        pid = fork();
        if(pid == 0){
            if(i < 5) setPriority(6);
            if(i > 4 && i < 10) setPriority(5);
            if(i > 24) setPriority(1);
            for (int j = 1; j <250; j++)
            {
                printf(1 , "/%d/ : /%d/\n" , i , j);
            }


            while(wait() != -1);
            CBT[i] = getCBT();
            waiting[i] = getWaiting();
            TA[i] = getTurnAround();
            printf(1 , "CBT is: %d\n" , CBT[i]);
            printf(1 , "Waiting is: %d\n" , waiting[i]);
            printf(1 , "TurnAround is: %d\n" , TA[i]);
            // my_acquire(i , -1);
            // my_acquire(i , -2);
            // my_acquire(i , -3);
            sleep(1);
            exit();            
        }
    }

    

    while(wait() != -1);
    sleep(1);
    uint totalCBT = 0;
    uint totalwaiting = 0;
    uint totalTA = 0;
    for (int i = 0; i < 30; i++)
    {
        totalCBT += CBT[i];
        totalwaiting += waiting[i];
        totalTA += TA[i];
    }

    printf(1, "Average CBT is: %d\n" , (uint) (totalCBT / 30));
    printf(1, "Average waiting is: %d\n" , (uint) (totalwaiting / 30));
    printf(1, "Average turnAround is: %d\n" , (uint) (totalTA / 30));
    
    exit();
    
}