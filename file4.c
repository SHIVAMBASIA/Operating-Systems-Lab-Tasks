#include<stdlib.h>
#include<stdio.h>
int main()
{
char a[20];
FILE *fp1=fopen("a.txt","r");
FILE *fp2=fopen("abcd.txt","w");
while(!feof(fp1))
{
fgets(a,20,fp1);
fputs(a,fp2);
}
fclose(fp1);
fclose(fp2);
return (0);
}
/*char source_file[20],target_file[20];
file *source,*target;
printf("enter the name of the file to be copied");
gets(source_file);
source=fopen(source_file,"r");
if(source==
*/

