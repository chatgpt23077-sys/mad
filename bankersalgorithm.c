#include<stdio.h>
#include<stdlib.h>
int main()
{
    int max[10][10],need[10][10];
    int alloc[10][10],avail[10];
    int fin[10],safe[10];
    int pr_cnt,res_cnt;
    int i,j,process,count=0;
    printf("Enter the number of processes\n");
    scanf("%d",&pr_cnt);
    for(i=0;i<pr_cnt;i++)
        fin[i]=0;
    printf("Enter the number of resources\n");
    scanf("%d",&res_cnt);
    for(i=0;i<pr_cnt;i++)
        for(j=0;j<res_cnt;j++)
            scanf("%d",&max[i][j]);
    for(i=0;i<pr_cnt;i++)
        for(j=0;j<res_cnt;j++)
            scanf("%d",&alloc[i][j]);
    for(i=0;i<res_cnt;i++)
        scanf("%d",&avail[i]);
    for(i=0;i<pr_cnt;i++)
        for(j=0;j<res_cnt;j++)
            need[i][j]=max[i][j]-alloc[i][j];
    do
    {
        process=-1;
        for(i=0;i<pr_cnt;i++)
        {
            if(fin[i]==0)
            {
                process=i;
                for(j=0;j<res_cnt;j++)
                {
                    if(avail[j]<need[i][j])
                    {
                        process=-1;
                        break;
                    }
                }
            }
            if(process!=-1)
                break;
        }
        if(process!=-1)
        {
            safe[count]=process+1;
            count++;
            for(j=0;j<res_cnt;j++)
                avail[j]+=alloc[process][j];
            fin[process]=1;
        }
    }while(count!=pr_cnt && process!=-1);
    if(count==pr_cnt)
    {
        printf("Safe sequence: ");
        for(i=0;i<pr_cnt;i++)
            printf("%d ",safe[i]);
    }
    else
    {
        printf("Unsafe State\n");
    }
}
