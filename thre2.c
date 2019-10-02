#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int g = 0;
void *myThread(void *value)
{
int q,k;
int *myid=(int*)value;
++g; 
printf("Thread ID: %d,Global: %d\n", *myid, g);
}
int main()
{
pthread_t tid1,tid2,tid3;
int i=1,j=2,k=3,e,q,w;
do{
printf("Enter the no of threads you want to execute.\nThe maximum threads that can be executed is 3.\n");
scanf("%d",&e);
if(e>3) printf("The maximum threads that can be created is 3.\nPlease reenter the value."); 
}while(e>3);
int p[e+1];
for(w=1;w<=e;w++) p[w]=5;
printf("Enter your choice of priority for each threads.\nThe default priorities are set to 5.\n");
printf("The maximum priority choice can be 10 and minimum priority  choice can be 1.\n");
for(q=1;q<=e;q++)
{
do{printf("Enter the priority for thread %d.\n",q);
scanf("%d",&p[q]);
if(p[q]>10 || p[q]<1) printf("The maximum priority choice can be 10 and minimum priority  choice can be 1.\n.Please reenter the value.\n"); 
}while(p[q]>10 || p[q]<1);
}
if(e==1)
{
pthread_create(&tid1,NULL,myThread,(void *)&i);
pthread_join(tid1,NULL);
}
if(e==2)
{if(p[1]>=p[2])
{
pthread_create(&tid1,NULL,myThread,(void *)&i);
pthread_join(tid1,NULL);
pthread_create(&tid2,NULL,myThread,(void *)&j);
pthread_join(tid2,NULL);
}
else
{
pthread_create(&tid2,NULL,myThread,(void *)&j);
pthread_join(tid2,NULL);
pthread_create(&tid1,NULL,myThread,(void *)&i);
pthread_join(tid1,NULL);
}}
if(e==3)
{
if(p[1]>p[2] && p[1]>p[3])
{
pthread_create(&tid1,NULL,myThread,(void *)&i);
pthread_join(tid1,NULL);
if(p[2]>=p[3])
{
pthread_create(&tid2,NULL,myThread,(void *)&j);
pthread_join(tid2,NULL);
pthread_create(&tid3,NULL,myThread,(void *)&k);
pthread_join(tid3,NULL);
}
else
{
pthread_create(&tid3,NULL,myThread,(void *)&k);
pthread_join(tid3,NULL);
pthread_create(&tid2,NULL,myThread,(void *)&j);
pthread_join(tid2,NULL);
}
}
if(p[2]>p[1] && p[2]>p[3])
{
pthread_create(&tid2,NULL,myThread,(void *)&j);
pthread_join(tid2,NULL);
if(p[1]>=p[3])
{
pthread_create(&tid1,NULL,myThread,(void *)&i);
pthread_join(tid1,NULL);
pthread_create(&tid3,NULL,myThread,(void *)&k);
pthread_join(tid3,NULL);
}
else
{
pthread_create(&tid3,NULL,myThread,(void *)&k);
pthread_join(tid3,NULL);
pthread_create(&tid1,NULL,myThread,(void *)&i);
pthread_join(tid1,NULL);
}
}
if(p[3]>p[1] && p[3]>p[2])
{
pthread_create(&tid3,NULL,myThread,(void *)&k);
pthread_join(tid3,NULL);
if(p[2]>=p[1])
{
pthread_create(&tid2,NULL,myThread,(void *)&j);
pthread_join(tid2,NULL);
pthread_create(&tid1,NULL,myThread,(void *)&i);
pthread_join(tid1,NULL);
}
else{
pthread_create(&tid1,NULL,myThread,(void *)&i);
pthread_join(tid1,NULL);
pthread_create(&tid2,NULL,myThread,(void *)&j);
pthread_join(tid2,NULL);
}
}
}
return 0;
}

