#include<stdio.h>
#include<stdlib.h>
int a=5,b=6,c,d;
/*struct arr{
int *p;
int s;
};*/
/*int a[5]={1,2,3,4,5};
struct arr n;
n.p=a;
n.s=5;*/
void *f1(void *p)
{
int sum;
sum=a+b;
printf("%d\n",sum);
c=sum;
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
int mul;
mul=a*b;

printf("%d\n",mul);
d=mul;
}
int main()
{
int e;
pthread_t t1;
pthread_t t2;
pthread_create(&t1,NULL,&f1,(void*)&c);
pthread_join(t1,NULL);
pthread_create(&t2,NULL,&f2,(void*)&d);
pthread_join(t2,NULL);
printf("ABC\n");
e=c+d;
printf("%d\n",e);
//sleep(20);
return 0;
}
