#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
char a[50];
int d[2];
pipe(d);
int t=fork();
write(d[1],"ABC",4);
read(d[0],a,50);
printf("%s",a);
return 0;
}


