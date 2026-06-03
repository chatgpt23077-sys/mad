#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,n,rs[50],f[10];
    int nf,k=0,avail,pf=0;
    float hr,mr;
    printf("Enter number of pages\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&rs[i]);
    printf("Enter frame size\n");
    scanf("%d",&nf);
    for(i=0;i<nf;i++)
        f[i]=-1;
    for(i=1;i<=n;i++)
    {
        avail=0;
        for(j=0;j<nf;j++)
            if(f[j]==rs[i])
                avail=1;
        if(avail==0)
        {
            f[k]=rs[i];
            k=(k+1)%nf;
            pf++;
        }
    }
    printf("Total pf is %d\n",pf);
    mr=(float)pf/n;
    hr=(float)(n-pf)/n;
    printf("hr,mr %.2f %.2f\n",hr,mr);
}
