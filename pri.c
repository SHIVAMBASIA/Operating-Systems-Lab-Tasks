#include<stdio.h>

int ar[10],cm[10],left[10];

struct gct
{
	int pno,st,et;
	
}gc[100];

struct process
{
	int at,bt,pri;
}pr[10];

int ct=0;

int get_comp(int n)
{
	int cmp=0,i;
	for(i=0;i<n;i++)
	{
		if(cm[i]==1)
			cmp++;
	}
	
	return cmp;
}
int who_ex(int n)
{
	int min=-1,i;
	for(i=0;i<n;i++)
	{
		if(pr[i].at<=ct)
			ar[i]=1;
			
	}
	
	for(i=0;i<n;i++)
	{
		if(ar[i]==1&&cm[i]==0)
		{
			if(min==-1)
				min=i;
		//
			else if(pr[min].pri>pr[i].pri || pr[min].pri==pr[i].pri && left[i]<left[min] || pr[min].pri==pr[i].pri && left[min] == left[i] && pr[i].at<pr[min].at )
				min=i;
		}
	}
	
	return min;
}

int main()
{
	int n, i, j=-1,p=-1;
	printf("\nEnter the number of processes\n");
	scanf("%d",&n);
	printf("\nP# ST T PRI\n");
	for(i=0;i<n;i++)
	{
		printf("P%d: ",i);
		scanf("%d %d %d",&pr[i].at, &pr[i].bt, &pr[i].pri);
		left[i]=pr[i].bt;
	}
	
	printf("\nInput done\n");
	
	
	while(get_comp(n) < n)
	{
		if(p!=who_ex(n))
		{
			//printf("Inside new gc box\n");
			p=who_ex(n);
			j++;
			if(ct<pr[p].at)
				ct=pr[p].at;
			gc[j].pno=p;
			gc[j].st=ct;
			gc[j].et=ct+1;
			ct++;
			left[p]--;
			if(left[p]==0)
				cm[p]=1;
			
			
		}
		else
		{
			//printf("In the same GC box\n");
			p=who_ex(n);
			//j++;
			gc[j].pno=p;
			//gc[j].st=ct;
			gc[j].et=ct+1;
			ct++;
			left[p]--;
			if(left[p]==0)
				cm[p]=1;
		}
		
	}
	printf("\nP# ST ET\n");
	for(i=0;i<=j;i++)
	{
		printf("P%d %d %d\n",gc[i].pno, gc[i].st, gc[i].et);
	}
}
