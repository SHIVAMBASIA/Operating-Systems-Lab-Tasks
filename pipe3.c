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
write(d[1],"Hello",6);
}
else
{
char a[20],c[20];
char b[3]={"h","i","\0"};
close(d[1);
read(d[0],a,10);
sprintf(c,"%s %s",a,b);
printf("%s",c);

write(
}
return 0;
}

