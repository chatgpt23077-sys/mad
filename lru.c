#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,n,rs[50],f[10];
    int nf,min,count[10];
    int flag[20],pf=0,next=1;
    float hr,mr;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
        flag[i]=0;
    }
    scanf("%d",&nf);
    for(i=0;i<nf;i++)
    {
        count[i]=0;
        f[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<nf;j++)
        {
            if(f[j]==rs[i])
            {
                flag[i]=1;
                count[j]=next++;
            }
        }
        if(flag[i]==0)
        {
            if(i<nf)
            {
                f[i]=rs[i];
                count[i]=next++;
            }
            else
            {
                min=0;
                for(j=1;j<nf;j++)
                    if(count[min]>count[j])
                        min=j;
                f[min]=rs[i];
                count[min]=next++;
            }
            pf++;
        }
    }
    printf("Total pf is %d\n",pf);
    mr=(float)pf/n;
    hr=(float)(n-pf)/n;
    printf("hr,mr %.2f %.2f\n",hrmr);
}
