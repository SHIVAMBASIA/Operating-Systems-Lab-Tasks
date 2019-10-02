#include<stdio.h>
#include<stdlib.h>
void *f1(void *p)
{
int *n=(int*)p;
printf("%d\n",*n);
/*int count=0,i;
for(i=0;i<5;i++)
{
count=count+a[i];
}
printf("%d",count);
printf("DEF\n");*/
//return NULL;
}
int main()
{
pthread_t t1;
int a=5;
pthread_create(&t1,NULL,f1,(void*)&a);
printf("ABC\n");
sleep(5);
return 0;
}

