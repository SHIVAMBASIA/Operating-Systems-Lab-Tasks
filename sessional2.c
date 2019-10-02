#include <stdio.h>
#include <stdlib.h>
struct chart
{
    int at;
    int bt;
}p[5]={{0,9},{2,4},{0,6},{4,6},{9,7}};
int ct=0,k=0;
int ar[5]={0,0,0,0,0};
int cm[5]={0,0,0,0,0};
int ced[5]={9,4,6,6,7};
int get_comp_no();
int who_ex();
struct grantchart
{
   int pr;
   int ct;
   int et;
}gc[5];
int main()
{
    int i;
    while(get_comp_no()< 5)
    {
            int pr=who_ex();
            int ac=secondmax(pr,100);
            gc[k].pr=pr;
            gc[k].ct=ct;
            if(ac==-1)
            {
            gc[k].pr=pr;
            gc[k].ct=ct;
            gc[k].et=ct+1;
            ct++;
            ced[pr]--;
            if(ced[pr]==0)
                cm[pr]=1;
            k++;
            }
            else{
            int dif=ced[pr]-ced[ac];
            if(dif==0)
            {
            int sec=secondmax(ac,pr);
            int dif2=ced[pr]-ced[sec];
            gc[k].et=ct+dif2;
            ct=ct+dif2;
            ced[pr]=ced[pr]-dif2;
            if(ced[pr]==0) cm[pr]=1;
            k++;
           }
           else{
            //gc[k].pr=pr;
            //gc[k].ct=ct;
            gc[k].et=ct+dif;
            ct=ct+dif;
            ced[pr]=ced[pr]-dif;
            if(ced[pr]==0)
                cm[pr]=1;
            k++;}
    }}
    for(i=0;i<30;i++)
    {
        printf("%d\t",gc[i].pr);
        printf("%d\t",gc[i].ct);
        printf("%d\n",gc[i].et);
    }
    return 0;
}

int get_comp_no()
{
    int i,sum=0;
    for(i=0;i<5;i++)
    {
        sum+=cm[i];
    }
    return sum;
}
int who_ex()
{
    
    int max=-1,i;
    for(i=0;i<5;i++)
    {
        if(p[i].at<=ct)
        {
            ar[i]=1;
        }
    }
    for(i=0;i<5;i++)
    {
        if(ar[i]==1 && cm[i]==0)
        {
            if(max==-1)
                max=i;
            else
            {
                if( ced[i] > ced[max] || (ced[i]==ced[max] && p[i].at<p[max].at))
                    max=i;
            }
        }
    }
    return max;
}
int secondmax(int q,int w)
{
int secmax=-1,i;
 for(i=0;i<5;i++)
    {
        if(p[i].at<=ct)
        {
            ar[i]=1;
        }
    }
for(i=0;i<5;i++)
    {
        if(ar[i]==1 && cm[i]==0)
        {
           if(i!=q && i!=w)
           {
           if(secmax==-1) 
           {secmax=i;
           }
                else
                {
                if( ced[i] > ced[secmax] || (ced[i]==ced[secmax] && p[i].at<p[secmax].at))
                    secmax=i;
                }
            }
        }
    return secmax;
 }
 }

