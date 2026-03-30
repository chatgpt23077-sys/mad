#include<stdio.h>

int main() {
    int n, i, t = 0, ts, count = 0;
    int bt[20], rt[20], wt[20], tat[20];
    int Twt = 0, Ttat = 0;
    float Avgwt, Avgtat;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    printf("Enter time slice:\n");
    scanf("%d", &ts);

    printf("Enter burst time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    while(count < n) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] > ts) {
                    t += ts;
                    rt[i] -= ts;
                } else {
                    t += rt[i];
                    tat[i] = t;
                    rt[i] = 0;
                    count++;
                }
            }
        }
    }

    for(i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        Twt += wt[i];
        Ttat += tat[i];
    }

    Avgwt = (float)Twt / n;
    Avgtat = (float)Ttat / n;

    printf("P\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("Avg WT = %.2f\n", Avgwt);
    printf("Avg TAT = %.2f\n", Avgtat);
}
