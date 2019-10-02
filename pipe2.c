#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
char a[50];
int d[2],e[2];
pipe(d);
pipe(e);
int t=fork();
if(t>0)
{
close(d[0]);
write(d[1],"ABC",4);
}
else
{
char a[10];
close(d[1]);
read(d[0],a,10);
printf("%s",a);
}
return 0;
}


