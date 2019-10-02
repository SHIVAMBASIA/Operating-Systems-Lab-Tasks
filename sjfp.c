#include<stdio.h>
#include<stdlib.h>
typedef struct
{
  int p_no;
  int at;
  int bt;
  int ct;
  int et;
  int ar;
  int cm;
  int cel;
  /*int st;
  int ft;
  int tt;
  int rt;
  int wt;*/
}S;
int ct=0;

int get_comp_no(S *s,int size)
{
int i,sum=0;
for(i=0;i<size;i++)
sum=sum + s[i].cm;
return sum;
}

int k=0;
/*void swap(S *p,S *q)
{
  S tmp = *p;
  *p = *q;
  *q = tmp;
}
void heapify(S *a,int i,int size)
{
  int m=i;
  if((2*i)<=size&&a[2*i].at<a[m].at)
     m = 2*i;
  if((2*i+1)<=size&&a[2*i+1].at<a[m].at)
     m = 2*i+1;
  if(m!=i)
  {
    swap(&a[m],&a[i]);
    heapify(a,m,size);
  }
}
void heap(S *a,int size)
{
  int i;
  for(i=size/2;i>=1;i--)
     heapify(a,i,size);
}*/
void insertHeap(S *a,int* size,S s1)
{
  (*size)++;
  int i = *size;
  while(s1.at<a[i/2].at&&i>1)
  {
    a[i] = a[i/2];
    i = i/2;
  }
  a[i] = s1;
}
int who_ex(S *s,int* size)
{
int min=-1;
int i;
for(i=0;i<5;i++)
{
if(s[i].at<ct)
s[i].ar=1;
}
for(i=0;i<*size;i++)
{
if(s[i].ar==1 && s[i].cm==0)
{
if(min==-1)
min=i;
else
{if(s[i].cel<s[min].cel||(s[i].cel==s[min].cel&&s[i].at<s[min].at))
{
min=i;
}}
}
}
return min;
}

int main()
{
  S *s;
  //S tmp;
  int n,i,size=0,t=1;
  printf("Enter number of programs");
  scanf("%d",&n);
  s = (S*)malloc((n+1)*sizeof(S));
  for(i=0;i<n;i++)
  {
  printf("Enter program no arrival time and burst time");
  scanf("%d%d%d",&s[i].p_no,&s[i].at,&s[i].bt);
  //insertHeap(s,&size,tmp);
  }
  for(i=0;i<n;i++)
  {s[i].ar=0;
  s[i].cm=0;
  s[i].cel=s[i].bt;
  }
  while(get_comp_no(s,n)<n)
  {
  int pra=who_ex(s,&size);
  s[k].p_no=pra;
  s[k].ct=ct;
  s[k].et=ct++;
  ct++;
  s[pra].cel--;
  printf("%d \t %d \t \t %d\n",s[k].p_no,s[k].ct,s[k].et);
  if (s[pra].cel==0)
  {s[pra].cm=1;
  k++;
  }}
  return 0;
  }
  
  
  /*for(i=1;i<=size;i++)
  {
  if(i==1)
  {
  s[i].st=s[i].at;
  s[i].ft=s[i].at + s[i].bt;
  }
  else
  {
  s[i].st=s[i-1].ft;
  s[i].ft=s[i].st + s[i].bt;
  }
  }
  for(i=size;i>0;i--)
  {
  s[i].tt=s[i].ft-s[i].at;
  }
  for(i=1;i<=size;i++)
  {
  s[i].rt=s[i].st-s[i].at;
  }
  for(i=1;i<=size;i++)
  {
  s[i].wt=s[i].tt-s[i].bt;
  }
  for(i=1;i<=size;i++)
  printf("pno %d at %d bt %d tt %d rt %d wt %d\n",s[i].p_no,s[i].at,s[i].bt,s[i].tt,s[i].rt,s[i].wt);
  return 0;*/

