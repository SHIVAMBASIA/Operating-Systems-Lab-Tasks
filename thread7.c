#include<stdio.h>
#include<stdlib.h>
int a,b;
struct arr{
int *p;
int l;
int h;
int m;
};
void *f1(void *p)
{
int i;
pthread_t t2;
pthread_t t3;
struct arr *q=(int*)p;
if(q->l < q->h)
{ 
q->m=(q->l + q->h)/2;
struct arr *s=(int*)p;
s->l=q->l;
s->h=q->m;
struct arr *t=(int*)p;
t->l=q->m+1;
t->h=q->h;
pthread_create(&t2,NULL,&f1,&s);
pthread_create(&t3,NULL,&f1,&t);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
merge(q->p,q->l,q->m,q->h);
}
for(i=0;i<8;i++)
{
printf("%d",(*q->p+i));
}
}
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
/*void *f1(void *p)
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
//}
/*void *f2(void *p)
{
int i,mul=1;
struct arr *q=(int*)p;
for(i=(q->s)-1;i>=0;i--)
{
mul=mul*(*(q->p+i));
}
printf("%d\n",mul);
b=mul;
}*/
int main()
{
//int c;
int i;
int a[8]={9,6,7,4,10,15,20,25};
struct arr n;
n.p=a;
n.h=8;
n.l=0;
pthread_t t1;
pthread_create(&t1,NULL,&f1,&n);
for(i=0;i<8;i++)
{
printf("%d",*((n.p)+i));
}
//printf("ABC\n");
//c=a+b;
//printf("%d,c");
//sleep(20);
return 0;
}
