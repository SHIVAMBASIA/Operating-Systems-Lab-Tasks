#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
int i;
int d[3][2];
for(i=0;i<3;i++)
{
pipe(d[i]);
int t=fork();
if(t>0 && i==0)
{
int p=12;
write(d[0][1],p,sizeof(p));
close(d[0][0]);
break;
}
if(t>0 && i==1)
{
int a;
read(d[0][1],a,sizeof(a));
int b=2;
int c=a+b;
write(d[1][1],c,sizeof(c));
close(d[1][0]);
break;
}
if(t>0 && i==2)
{
int f;
read(d[1][1],f,sizeof(f));
int g=3;
int h=f+g;
write(d[2][1],h,sizeof(h));
close(d[2][0]);
printf("%d\n",h);
break;
}
else{
int k;
read(d[2][1],k,sizeof(k));
printf("%d\n",k);
}}
return 0;
}


