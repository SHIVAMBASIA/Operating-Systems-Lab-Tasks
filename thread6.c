#include<stdio.h>
#include<stdlib.h>
int g=5,m=6,c,d;
int a[8]={9,6,7,4,10,15,20,25};
len=7;
int dac(int a[],int l,int h,int sum)
{

while(h>l+1)
{
h=h/2;
}
sum=a[l]+a[h];
if(l>=len || h>len)
{
printf("%d",sum);
return;
}
dac(a,l+2,h+2,sum);
}

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
sum=g+m;
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
mul=g*m;

printf("%d\n",mul);
d=mul;
}
int main()
{
dac(a,0,7,0);

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
