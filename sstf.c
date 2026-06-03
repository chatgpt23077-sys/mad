#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
int main()
{
    int req[20],temp[20];
    int n,hdpos,tseek=0;
    int i,min,dist,index,cpos,cnt=0;
    float avgmv;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
        temp[i]=0;
    }
    scanf("%d",&hdpos);
    cpos=hdpos;
    while(cnt<n)
    {
        min=INT_MAX;
        for(i=0;i<n;i++)
        {
            if(temp[i]!=-1)
            {
                dist=abs(req[i]-cpos);
                if(min>dist)
                {
                    min=dist;
                    index=i;
                }
            }
        }
        tseek+=min;
        temp[index]=-1;
        cnt++;
        cpos=req[index];
    }
    avgmv=(float)tseek/n;
    printf("TST=%d\n",tseek);
    printf("Avg=%.2f\n",avgmv);
}
