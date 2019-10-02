#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include <sys/types.h>
#include <unistd.h>
int count=0;
sem_t S1;
void *f1(void *p)
{
int *n=(int*)p;
int i;
for(i=0;i<*n;i++)
{
sem_wait(&S1);
count++;
sem_post(&S1);
}}
int main()
{
sem_init(&S1,0,1);
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

