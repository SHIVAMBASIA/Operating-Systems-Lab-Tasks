#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
int t,i,k,*q;
printf("Child:%dParent:%d\n",getpid(),getppid());
for(i=0;i<3;i++)
{
t=fork();
if(t>0)
break;
}
printf("Child::%dParent:%d\n",getpid(),getppid());
k=wait(&q);
return 0;
}

