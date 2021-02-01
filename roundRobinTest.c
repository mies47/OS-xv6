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
                printf(2, "/%d/ : /%d/\n", getpid(), j); 
                
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
    exit();
    
}