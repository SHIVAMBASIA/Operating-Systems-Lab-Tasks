#include<stdio.h>
#include<stdlib.h>
int count=0;
pthread_mutex_t mt;

void *f1(void *p)
{
int *n=(int*)p;
int i;
for(i=0;i<*n;i++)
{
pthread_mutex_lock(&mt);
count++;
pthread_mutex_unlock(&mt);
}}
int main()
{
pthread_mutex_init(&mt,NULL);
int a=50;
int b=60;
pthread_t t1;
pthread_t t2;
pthread_create(&t1,NULL,&f1,(void*)&a);
pthread_create(&t2,NULL,&f1,(void*)&b);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("%d",count);
return 0;
}

