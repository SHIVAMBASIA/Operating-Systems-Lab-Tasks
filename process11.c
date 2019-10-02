#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
        int t,i,q,k;
        printf("Process id :%d\t Parent Process id:%d\n",getpid(),getppid());
        for(i=0;i<2;i++)
        {
                t=fork();
                if(t == 0)
                {
                        if(i==0)
                        {
                                fork();
                        }
                        else if(i==1)
                        {
                                
                        } 
                        break;
0CVjy                }
        }printf("Process id :%d\t Parent Process id:%d\n",getpid(),getppid());
        // k=wait(&q);
        while(k=wait(&q)>0);
        return(0);
}
