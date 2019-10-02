#include<stdio.h>
#include<stdlib.h>
int a,b;
struct arr{
int *p;
int s;
};
void *f1(void *p)
{
int i,sum=0;
struct arr *q=(int*)p;
for(i=0;i<q->s;i++)
{
sum=sum+(*(q->p+i));
}
printf("%d\n",sum);
a=sum;
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
int i,mul=1;
struct arr *q=(int*)p;
for(i=(q->s)-1;i>=0;i--)
{
mul=mul*(*(q->p+i));
}
printf("%d\n",mul);
b=mul;
}
int main()
{
int c;
pthread_t t1;
pthread_t t2;
int a[5]={1,2,3,4,5};
struct arr n;
n.p=a;
n.s=5;

pthread_create(&t1,NULL,&f1,&n);
pthread_create(&t2,NULL,&f2,&n);
printf("ABC\n");
c=a+b;
printf("%d,c");
sleep(20);
return 0;
}
