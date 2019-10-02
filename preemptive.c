#include <stdio.h>
#include <stdlib.h>
struct chart
{
    int at;
    int bt;
}p[5]={{9,4},{0,8},{6,10},{3,4},{4,2}};
int ct=0,k=0;
int ar[5]={0,0,0,0,0};
int cm[5]={0,0,0,0,0};
int ced[5]={4,8,10,4,2};
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
            gc[k].pr=pr;
            gc[k].ct=ct;
            gc[k].et=ct+1;
            ct++;
            ced[pr]--;
            if(ced[pr]==0)
                cm[pr]=1;
            k++;
    }
    for(i=0;i<28;i++)
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
    int min=-1,i;
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
            if(min==-1)
                min=i;
            else
            {
                if( ced[i] < ced[min] || (ced[i]==ced[min] && p[i].at<p[min].at))
                    min=i;
            }
        }
    }
    return min;
}

