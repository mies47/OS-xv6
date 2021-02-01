#include "types.h"
#include "stat.h"
#include "user.h"


int main(void){
    for (int i = 0; i < 30; i++)
    {
        int pid = fork();
        if(i < 5) setPriority(6);
        if(i > 4 && i < 10) setPriority(5);
        if(i > 24) setPriority(1);
        if(pid == 0){
            for (int j = 0; j < 250; j++)
            {
                printf(1 , "/%d/ : /%d/\n" , getpid() , j);
            }
            
        }else{
            while(wait() != -1);
            sleep(1);
            exit();
        }
    }

    while(wait() != -1);
    sleep(1);
    exit();
    
}