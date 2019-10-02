#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
int t,s;
printf("%d\n%d\n",getppid(),getpid());
t=fork();
//printf("ABC=%d\n%d\n",getppid(),getpid());
if(t==0)
{
printf("ABC=%d\n%d\n",getppid(),getpid());
}
else 
{
scanf("%d",&s);
printf("DEF=%d\n%d\n",getppid(),getpid());
}
return 0;
}

