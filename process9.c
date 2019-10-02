#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
        int t,i;
        printf("Process id :%d\t Parent Process id:%d\n",getpid(),getppid());
        for(i=0;i<3;i++)
        {
                t=fork();
                if(t>0)
                {
                        break;
                }
        }printf("Process id :%d\t Parent Process id:%d\n",getpid(),getppid());
        return(0);
}
