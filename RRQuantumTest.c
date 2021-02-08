#include "types.h"
#include "stat.h"
#include "user.h"
#include "spinlock.h"


int main(void){
    int quantum_values[] = {2, 5, 10, 50,  100, 200, 300, 375, 400, 500, 600};
    int w[11];
    int c[11];
    int tar[11];
    for(int t = 0 ; t < 11 ; t++){
    setQuantum(quantum_values[t]);    
    
    int CBT[10];
    int waiting[10];
    int TA[10];
    int pids[10];
    //int pid;
    int totalCBT = 0;
    int totalWaiting = 0;
    int totalTA = 0;
    for (int i = 0; i < 10; i++)
    {
        pids[i] = fork();
        if(pids[i] == 0){
            
            for (int j = 1; j <1000; j++)
            {
                printf(1 , "\n/%d/ : /%d/\n" , pids[i] , j);;
            }

            exit();            
        }
    }
    
    for (int i = 0; i < 10; i++)
    {
        mywait(&CBT[i] , &waiting[i] , &TA[i]);

        totalCBT+= CBT[i];
        totalWaiting+= waiting[i];
        totalTA += TA[i];
        
        // printf(1 , "CBT %d is: %d\n" , pid, CBT[i]);
        // printf(1 , "Waiting %d is: %d\n" ,pid, waiting[i]);
        // printf(1 , "TurnAround %d is: %d\n" ,pid, TA[i]);
        
    }
    

    // printf(1, "QUANTUM = %d \n", quantum_values[t]);
    // printf(1, "Average CBT is: %d\n" , (int)(totalCBT / 10));
    // printf(1, "Average waiting is: %d\n" , (int) (totalWaiting/ 10));
    // printf(1, "Average turnAround is: %d\n" , (int) (totalTA / 10));
    c[t] = (int)(totalCBT / 10);
    w[t] = (int) (totalWaiting/ 10);
    tar[t] = (int) (totalTA / 10);
    while(wait() != -1);

    sleep(1);

    
   
    }
    for(int y = 0 ; y < 11 ; y ++){
    printf(1,"AVG CBT time for QUANTUM = %d is : %d \n", quantum_values[y], c[y]);
    printf(1,"AVG Waiting time for QUANTUM = %d is : %d \n", quantum_values[y], w[y]);
    printf(1,"AVG TurnArround time for QUANTUM = %d is : %d \n", quantum_values[y], tar[y]);
    printf(1, "\n");
    }
     exit();
    
}