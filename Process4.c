#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
int t,i,k,*q,j,s;
printf("Process:%dParent:%d\n",getpid(),getppid());
for(i=0;i<2;i++)
{
t=fork();
if(t==0)
{
if(i==0)
fork();
else if(i==1)
{
for(j=0;j<2;j++)
{
s=fork();
if(s==0)
break;
}
}

break;
}}
printf("Process:%dParent:%d\n",getpid(),getppid());
while(k=wait(&q)>0);
sleep(10);
return 0;
}

