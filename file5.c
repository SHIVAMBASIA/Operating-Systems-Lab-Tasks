#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
char a[20];
int no,no1;
//size_t count=20;
//size_t count2=20;
no=open("a.txt",O_RDONLY);

no1=open("abcd.txt",O_WRONLY);

int no2=read(no,a,20);
write(no1,a,no2);
close(no);
close(no2);
}

/*
while(!feof(fp1))
{
fgets(a,256,fp1);
fputs(a,fp2);
}
fclose(fp1);
fclose(fp2);
}
*/
