#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
        printf("a\n");
        fork();
        //printf("b\n");
        fork();
        //printf("c\n");
        fork();
       //printf("d\n");
        return(0);
}
