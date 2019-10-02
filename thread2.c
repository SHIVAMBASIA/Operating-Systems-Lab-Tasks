#include<stdio.h>
#include<stdlib.h>

void *f1(void *p)
{
int i;
int *n=(int*)p;
for(i=0;i<5;i++)
{

printf("%d\n",*(n+i));
}
/*for(i=0;i<5;i++)
{
count=count+a[i];
}
printf("%d",count);
printf("DEF\n");
//return NULL;*/
}
void *f2(void *p)
{
int i;
int *n=(int*)p;
for(i=4;i>=0;i--)
{
printf("%d\n",*(n+i));
}

}
int main()
{
pthread_t t1;
pthread_t t2;
int a[5]={1,2,3,4,5};

pthread_create(&t1,NULL,&f1,a);
pthread_create(&t2,NULL,&f2,a);
printf("ABC\n");
sleep(20);
return 0;
}
