#include "types.h"
#include "stat.h"
#include "user.h"
#include "spinlock.h"


int main(void){
    for (int i = 0; i < 4; i++)
    {
        int pid = fork();
        if(pid > 0){
            if(i == 1) setPriority(6);
            if(i == 2) setPriority(5);
            if(i == 3) setPriority(1);
            for (int j = 0; j < 25; j++)
            {
                my_acquire(j);
                // printf(1 , "/%d/ : /%d/\n" , getpid() , j);
            }

            while(wait() != -1);
            sleep(1);
            exit();
            
        }
    }

    while(wait() != -1);
    sleep(1);
    exit();
    
}