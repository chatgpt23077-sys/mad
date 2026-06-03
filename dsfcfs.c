#include<stdio.h>
#include<stdlib.h>
int main()
{
    int req[20],n,hdpos;
    int tseek=0,i;
    float avgmv;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&req[i]);
    scanf("%d",&hdpos);
    for(i=0;i<n;i++)
    {
        tseek+=abs(req[i]-hdpos);
        hdpos=req[i];
    }
    avgmv=(float)tseek/n;
    printf("TST=%d\n",tseek);
    printf("Avg=%.2f\n",avgmv);
}
