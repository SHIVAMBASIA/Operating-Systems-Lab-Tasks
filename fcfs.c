#include<stdio.h>
#include<stdlib.h>
typedef struct
{
  int p_no;
  int at;
  int bt;
  int st;
  int ft;
  int tt;
  int rt;
  int wt;
}S;
void swap(S *p,S *q)
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
}
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
int main()
{
  S *s,tmp;
  int n,i,size=0,t=1;
  printf("Enter number of programs");
  scanf("%d",&n);
  s = (S*)malloc((n+1)*sizeof(S));
  while(size<n)
  {
  printf("Enter program no arrival time and burst time");
  scanf("%d%d%d",&tmp.p_no,&tmp.at,&tmp.bt);
  insertHeap(s,&size,tmp);
  }
  for(i=1;i<=size;i++)
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
  return 0;
}









