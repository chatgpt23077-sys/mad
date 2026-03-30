#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, i, j, temp;
    int wt[20], bt[20], tat[20], pno[20];
    int Twt = 0, Ttat = 0;
    float Avgwt, Avgtat;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    printf("Enter burst time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        pno[i] = i + 1;
    }

    // Sorting based on burst time
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[j] < bt[i]) {
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pno[i]; pno[i] = pno[j]; pno[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        Twt += wt[i];
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        Ttat += tat[i];
    }

    Avgwt = (float)Twt / n;
    Avgtat = (float)Ttat / n;

    printf("P\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", pno[i], bt[i], wt[i], tat[i]);
    }

    printf("Avg WT = %.2f\n", Avgwt);
    printf("Avg TAT = %.2f\n", Avgtat);
}
