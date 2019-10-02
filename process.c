#include<stdio.h>
#include<stdlib.h>
struct process
{
        int pno;
        int bt;
        int at;
        int wt;
        int tat;
};
void main()
{
        int i,n,c;
        c=0;
        printf("enter number of process");
        scanf("%d",&n);
        struct process **p=(struct process **)malloc(n*sizeof(struct process *));
        for(i=0;i<n;i++)
        {
                p[i]=(struct process *)malloc(sizeof(struct process *));
                printf("enter burst time");
                scanf("%d",&p[i]->bt);
                printf("enter arrival time");
                scanf("%d",&p[i]->at);
        }
        for(i=0;i<n;i++)
        {        
                if(i==0)
                {
                c=p[i]->bt;
                p[i]->tat=c;
                }
                else
                {
                        for(i=1;i<n;i++)
                        {
                                c=c+p[i]->bt;
                                p[i]->wt=c-p[i]->at;
                                p[i]->tat=c-p[i]->wt;
                
                        }
                }
        }
        for(i=0;i<n;i++)
        {
                printf("p[%d]->wt=%d \n",i,p[i]->wt);
                printf("p[%d]->tat=%d \n",i,p[i]->tat);
        }
}

