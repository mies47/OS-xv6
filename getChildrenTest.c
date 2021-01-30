#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int main(void){
    int n1 = fork();
    int n2 = fork();
    int n3 = fork();
    int n4 = fork();
    if(n1 > 0 && n2 > 0 && n3 > 0 && n4 > 0){
        int* add = malloc(NPROC);
        getChildren(add ,n1);
        while(*add != -1){
            printf(1 , "%d/" , *add);
            add++;
        }
        printf(1 , "\n");
    }

    

    while(wait() != -1);
    sleep(1);
    exit();
}
